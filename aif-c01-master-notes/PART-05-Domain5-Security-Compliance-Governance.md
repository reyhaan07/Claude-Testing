# PART 5 — AIF-C01 MASTER NOTES

# DOMAIN 5 — SECURITY, COMPLIANCE, AND GOVERNANCE FOR AI SOLUTIONS (14%)

The guide has two task statements:
- **5.1** Explain methods to secure AI systems (including **AgentCore Identity & Policy**, prompt injection, output filtering/validation, audit logging, **hallucination detection & grounding**; new emphasis in v1.1)
- **5.2** Recognize governance and compliance regulations for AI systems

---

## 5.0 AWS SHARED RESPONSIBILITY MODEL (START HERE)

- **Simple meaning:** AWS and you **split** the security work. AWS secures the **building** (data centers, hardware, core services). You secure **what you put in it** (your data, who can access it, how you configure things).
- **Technical meaning:**
  - **AWS = security OF the cloud:** physical data centers, hardware, network infrastructure, virtualization, and the managed service software (e.g., Bedrock's underlying infrastructure and model hosting).
  - **Customer = security IN the cloud:** **your data**, **IAM** (users/roles/permissions), **encryption choices**, network configuration (VPC, security groups), application security, **prompts/guardrails configuration**, compliance of your use case.
- **For AI/managed services:** The more managed the service (Bedrock), the **more AWS handles**. But **you are always responsible for your data, access management, and how you use the model** (e.g., configuring Guardrails, validating outputs).
- **Example:** Bedrock: AWS secures the model-hosting infrastructure. You control who can call the model (IAM), encrypt your fine-tuning data (KMS), and configure Guardrails.
- **Exam keyword:** "responsibility", "who is responsible for…"
- **Exam trap:** "Who is responsible for configuring IAM permissions / encrypting customer data / patching the physical host?" → Customer / Customer / **AWS**.
- **Memory trick:** **AWS = OF the cloud (the house). You = IN the cloud (your furniture + locking your doors).**

| Responsibility | AWS | Customer |
|---|---|---|
| Physical data center security | ✅ | |
| Hardware & global network | ✅ | |
| Managed service infrastructure (Bedrock hosting) | ✅ | |
| Customer data (classification, encryption choice) | | ✅ |
| IAM users, roles, policies | | ✅ |
| Network config (VPC, security groups, endpoints) | | ✅ |
| Guardrails & prompt design | | ✅ |
| OS patching on EC2 | | ✅ |
| OS patching for managed services (Bedrock, Lambda) | ✅ | |
| Compliance of your AI use case | | ✅ (AWS provides compliant infrastructure & reports) |

---

## 5.1 IDENTITY & ACCESS (IAM)

### 5.1.1 AWS IAM (Identity and Access Management)
- **Simple meaning:** The AWS service that decides **who** can get in and **what** they're allowed to do.
- **Technical meaning:** A global service to securely control **authentication** (who you are) and **authorization** (what you may do) to AWS resources using users, groups, roles, and policies. **Free.**
- **AWS AI example:** An IAM policy allowing only the data-science role to call `bedrock:InvokeModel` for a specific model.
- **Exam keyword:** "control access", "permissions", "who can", "least privilege"
- **Memory trick:** **IAM = "I Am" = who am I and what can I do.**

### 5.1.2 IAM users
- **Simple meaning:** A login identity for **one person or application** with long-term credentials (password / access keys).
- **Best practice:** Avoid long-term keys; prefer roles and federated access (IAM Identity Center). Never use the **root user** for daily tasks; enable **MFA**.

### 5.1.3 IAM groups
- A collection of users that share permissions (e.g., "DataScientists" group).

### 5.1.4 IAM roles
- **Simple meaning:** A "hat" with permissions that a person, service, or application can **temporarily put on**. There's no permanent password; it uses **temporary credentials**.
- **Technical meaning:** An identity with permissions that trusted entities **assume** to get temporary security credentials. It is used by **AWS services** (e.g., SageMaker needs a role to read S3; a Bedrock Knowledge Base needs a role to read S3 and write to OpenSearch), applications, and federated users.
- **Exam keyword:** "service needs access to another service", "temporary credentials", "cross-account"
- **Exam trap:** "Allow SageMaker/Bedrock/Lambda to access S3 securely" → **IAM role** (NOT an IAM user with access keys stored in code).
- **Memory trick:** **Role = a hat you wear temporarily.**

### 5.1.5 IAM policies
- **Simple meaning:** A document (JSON) listing what is **allowed or denied**.
- **Technical meaning:** JSON documents with **Effect (Allow/Deny), Action, Resource, (Condition)**. Types:
  - **Identity-based policies:** attached to users, groups, roles
  - **Resource-based policies:** attached to resources (e.g., **S3 bucket policy**)
  - An explicit **Deny always wins**; by default everything is **implicitly denied**.
- **Example:**
  ```json
  {"Effect": "Allow", "Action": "bedrock:InvokeModel",
   "Resource": "arn:aws:bedrock:us-east-1::foundation-model/amazon.nova-lite-v1:0"}
  ```
- **Memory trick:** **Policy = the permission slip.**

### 5.1.6 Permissions & least privilege
- **Simple meaning:** Give people and services **only the access they need, nothing more**.
- **Technical meaning:** The **principle of least privilege**: grant the minimum permissions required to perform a task. Reduces the blast radius if credentials are compromised or an agent is manipulated (prompt injection).
- **AWS:** IAM policies scoped to specific actions/resources; **SageMaker Role Manager**; IAM Access Analyzer; **AgentCore Identity** & **Policy** for agents.
- **Exam keyword:** "minimum permissions", "only what is required", "reduce risk"
- **Exam trap:** "Give the agent AdministratorAccess so it works" = **WRONG**. Least privilege is almost always the right answer.
- **Memory trick:** **Least privilege = need-to-know basis.**

### 5.1.7 Authentication vs Authorization
| | Authentication (AuthN) | Authorization (AuthZ) |
|---|---|---|
| Question | **Who are you?** | **What are you allowed to do?** |
| Happens | First | Second |
| Examples | Password, MFA, access keys, SSO, OAuth sign-in | IAM policies, permissions, Cedar policies |
| Memory | **AuthN = ideNtity** | **AuthZ = Zones you can enter** |

### 5.1.8 Amazon Bedrock AgentCore Identity (NEW in v1.1)
- **Simple meaning:** Gives each AI agent its **own secure identity** and safely manages the **credentials** it needs to access other systems (like Slack, GitHub, Salesforce, or AWS resources) **on behalf of a user**, with only the permissions it needs.
- **Technical meaning:** An identity and credential management service for AI agents. It supports **inbound authentication** (verifying users/apps that call the agent, via corporate identity providers like Okta, Microsoft Entra ID, Amazon Cognito) and **outbound authentication** (securely obtaining and storing **OAuth tokens and API keys** in a **token vault** to access third-party tools and AWS resources on behalf of users). It enables **least-privilege, user-delegated access** without hard-coding secrets.
- **Real-world example:** A sales agent needs to read a user's Salesforce data. AgentCore Identity handles the OAuth consent and stores the token securely, so the agent accesses **only that user's** data.
- **Exam keyword:** "agent needs to securely access third-party services on behalf of users", "manage agent credentials/OAuth tokens", "agent identity", "no hard-coded credentials"
- **Common confusion:** AgentCore Identity (identity/credentials **for agents**) vs IAM (identity for AWS principals) vs Secrets Manager (general secret storage).
- **Memory trick:** **AgentCore Identity = the agent's ID badge + key ring.**

### 5.1.9 Policy in Amazon Bedrock AgentCore (NEW in v1.1)
- **Simple meaning:** A set of **strict rules** about which tools an agent is allowed to use and under what conditions. It is checked **every time** the agent tries to call a tool, **outside the AI model**, so a tricked model still can't break the rules.
- **Technical meaning:** A policy engine attached to **AgentCore Gateway** that intercepts **every tool call** and evaluates it against **Cedar** policies (an open-source AWS policy language; policies can also be written in natural language and converted to Cedar). It is **default-deny**: only explicitly permitted tool invocations are allowed. It provides **deterministic, auditable** control of agent actions, independent of the model's reasoning.
- **Example:** "The refund agent may call `issueRefund` only if amount < $500; otherwise deny" (a human must handle larger refunds).
- **Exam keyword:** "deterministic control over agent tool calls", "restrict which actions an agent can take", "enforce business rules on agent actions", "Cedar"
- **Common confusion:** **Policy in AgentCore** (controls **actions/tool calls**) vs **Bedrock Guardrails** (controls **content** of prompts/responses) vs **IAM** (controls AWS API access).
- **Exam trap:** Prompt instructions like "never refund more than $500" can be bypassed by prompt injection. **Policy in AgentCore enforces it deterministically outside the model.**
- **Memory trick:** **AgentCore Policy = the rulebook the bouncer checks before every agent action.**

### IF THE QUESTION SAYS… → THINK…
119. "Allow a SageMaker notebook/Bedrock KB to read data in S3 securely" → **IAM role**
120. "Grant only the minimum permissions required" → **Least privilege (IAM policies)**
121. "Agent must access users' third-party apps via OAuth without hard-coded credentials" → **AgentCore Identity**
122. "Deterministically restrict which tools an agent can call and under which conditions" → **Policy in Amazon Bedrock AgentCore (Cedar)**
123. "Control which employees can invoke which Bedrock models" → **IAM policies**

---

## 5.2 ENCRYPTION, SECRETS & DATA PROTECTION

### 5.2.1 Encryption at rest
- **Simple meaning:** Scrambling data **while it's stored** (on disk, in S3, in databases) so thieves can't read it.
- **Technical meaning:** Encrypting stored data using keys (AES-256), typically managed by **AWS KMS**. In AWS AI services: S3 training data, Bedrock custom models, Knowledge Base vector stores, SageMaker volumes/artifacts.
- **Keyword:** "stored data", "data on disk", "S3 encryption"

### 5.2.2 Encryption in transit
- **Simple meaning:** Scrambling data **while it travels** over the network.
- **Technical meaning:** Protecting data moving between clients and services (or between services) using **TLS/HTTPS**. AWS API endpoints use TLS.
- **Keyword:** "data moving over network", "TLS", "HTTPS"
- **Memory trick:** **At rest = in the safe. In transit = in the armored truck.**

### 5.2.3 AWS KMS (Key Management Service)
- **Simple meaning:** AWS's service to **create and control encryption keys**.
- **Technical meaning:** A managed service to create, manage, rotate, and control access to **cryptographic keys** used to encrypt data across AWS services. Supports **AWS managed keys** and **customer managed keys (CMKs)** (you control policies & rotation). Key usage is logged in **CloudTrail**.
- **AI example:** Encrypt Bedrock custom models, fine-tuning jobs, Knowledge Bases, Agents, and SageMaker data with **your own KMS key**.
- **Exam keyword:** "encryption keys", "customer managed keys", "control/rotate keys", "encrypt at rest"
- **Common confusion:** KMS (**keys**) vs Secrets Manager (**passwords/API keys/credentials**) vs IAM (**access**).
- **Memory trick:** **KMS = Key Management = the key maker.**

### 5.2.4 AWS Secrets Manager
- **Simple meaning:** A safe place to store **passwords, API keys, and database credentials**, instead of writing them in your code.
- **Technical meaning:** A managed service to **store, retrieve, and automatically rotate secrets** (DB credentials, API keys, OAuth tokens), encrypted with KMS and controlled by IAM.
- **AI example:** Store the API key for a third-party vector DB (e.g., Pinecone) used by a Bedrock Knowledge Base; store DB credentials for a RAG app.
- **Exam keyword:** "store credentials securely", "rotate passwords automatically", "don't hard-code API keys"
- **Exam trap:** "Hard-coded DB password in Lambda code" → move it to **Secrets Manager**.
- **Memory trick:** **Secrets Manager = password vault.**

### 5.2.5 Amazon Macie
- **Simple meaning:** A tool that **scans your S3 buckets** to find **sensitive data** like credit card numbers, names, and addresses.
- **Technical meaning:** A managed data-security service that uses ML and pattern matching to **discover, classify, and protect sensitive data (PII, financial, credentials) in Amazon S3**, and alerts on security risks (e.g., public buckets).
- **AI example:** Scan an S3 bucket of documents **before** using them for fine-tuning or a knowledge base, to avoid training on or exposing PII.
- **Exam keyword:** "discover PII in S3", "sensitive data discovery", "classify data in S3"
- **Common confusion:** **Macie** (sensitive **data** in S3) vs **Inspector** (software **vulnerabilities**) vs **Guardrails PII filter** (PII in **prompts/responses**) vs **Comprehend PII detection** (PII in **text** you send to it).
- **Memory trick:** **Macie = "My Awesome Classified Information Explorer": finds secrets in S3.**

### 5.2.6 Data privacy practices for AI
- **Data minimization** (collect only what's needed), **anonymization/masking**, **consent**, **access control**, **encryption**, **retention limits**, **don't send PII to models unnecessarily**.
- **Bedrock privacy facts:** prompts/responses are **not used to train base models**, **not shared** with model providers, and **stay in the Region** you use (unless you opt into cross-region inference). Fine-tuned custom models are **private to your account**.

### IF THE QUESTION SAYS… → THINK…
124. "Company wants to control and rotate its own encryption keys for Bedrock data" → **AWS KMS customer managed keys**
125. "Store API keys/database passwords securely and rotate them" → **AWS Secrets Manager**
126. "Find PII in S3 before using data for training" → **Amazon Macie**
127. "Protect data traveling between app and model endpoint" → **Encryption in transit (TLS)**

---

## 5.3 NETWORK SECURITY

### 5.3.1 Amazon VPC (Virtual Private Cloud)
- **Simple meaning:** Your own **private, isolated network** inside AWS.
- **Technical meaning:** A logically isolated virtual network where you control IP ranges, **subnets (public/private)**, route tables, **security groups** (instance-level firewall), and **network ACLs** (subnet-level firewall).
- **AI example:** Run SageMaker training/endpoints inside private subnets with no internet access (network isolation).
- **Keyword:** "isolated network", "private subnet", "no internet access"
- **Memory trick:** **VPC = your private fenced yard in AWS.**

### 5.3.2 AWS PrivateLink / VPC interface endpoints
- **Simple meaning:** A **private tunnel** from your VPC to AWS services (like Bedrock) so traffic **never goes over the public internet**.
- **Technical meaning:** Private connectivity between VPCs and AWS services using **interface VPC endpoints** (powered by PrivateLink). Traffic stays on the AWS network.
- **AI example:** Call **Amazon Bedrock** or SageMaker APIs from a private subnet via a **VPC endpoint (PrivateLink)**.
- **Exam keyword:** "without traversing the public internet", "private connectivity", "keep traffic within AWS network"
- **Exam trap:** "Access Bedrock from a VPC with no internet gateway" → **VPC interface endpoint (AWS PrivateLink)**.
- **Memory trick:** **PrivateLink = private tunnel.**

### 5.3.3 Infrastructure protection
- Protect networks and compute: VPC isolation, security groups, NACLs, **AWS WAF** (web application firewall: blocks malicious web requests such as SQL injection and bots; can protect GenAI app front-ends), **AWS Shield** (DDoS protection), private endpoints.

### IF THE QUESTION SAYS… → THINK…
128. "Traffic to Bedrock must not traverse the public internet" → **AWS PrivateLink (VPC interface endpoint)**
129. "Run ML training in an isolated network" → **VPC (private subnets, network isolation)**

---

## 5.4 MONITORING, LOGGING, AUDITING & COMPLIANCE SERVICES

### 5.4.1 AWS CloudTrail
- **Simple meaning:** A **security camera recording of every API call** in your AWS account: who did what, when, from where.
- **Technical meaning:** Records **API activity/events** (user, service, time, source IP, parameters) across AWS for **auditing, governance, compliance, and forensics**. Logs Bedrock API calls (e.g., who called `InvokeModel`, who created a guardrail).
- **Exam keyword:** "who made the API call", "audit trail", "track user activity", "governance/audit"
- **Common confusion:** CloudTrail (**who did what**, API calls) vs CloudWatch (**performance metrics, logs, alarms**) vs Config (**resource configuration history/compliance**).
- **Memory trick:** **CloudTrail = the trail of footprints (who walked where).**

### 5.4.2 Amazon CloudWatch
- **Simple meaning:** The **health dashboard**: metrics, logs, and alarms for your applications and resources.
- **Technical meaning:** Monitoring & observability: **metrics** (e.g., Bedrock invocations, latency, token counts, throttles), **logs** (CloudWatch Logs), **alarms**, dashboards. **Bedrock model invocation logging** can send full prompts & responses to CloudWatch Logs and/or S3. AgentCore Observability uses CloudWatch.
- **Exam keyword:** "monitor performance", "latency metrics", "set alarms", "application logs", "track token usage"
- **Memory trick:** **CloudWatch = watching the health monitor.**

### 5.4.3 AWS Config
- **Simple meaning:** Keeps a **history of how your resources are configured** and checks whether they follow your rules.
- **Technical meaning:** Continuously records **resource configurations and changes**, evaluates them against **Config rules** (e.g., "S3 buckets must be encrypted", "SageMaker endpoints must use KMS"), and reports **compliance**. It can auto-remediate.
- **Exam keyword:** "configuration changes", "resource compliance", "configuration history", "is the resource compliant with rules"
- **Memory trick:** **Config = configuration history + compliance checker.**

### 5.4.4 Amazon Inspector
- **Simple meaning:** **Scans for software vulnerabilities** in your servers, containers, and Lambda functions.
- **Technical meaning:** Automated **vulnerability management** that continuously scans **EC2 instances, container images (ECR), and Lambda functions** for **software vulnerabilities (CVEs)** and unintended **network exposure**.
- **Exam keyword:** "vulnerability scanning", "CVEs", "software vulnerabilities", "unpatched"
- **Memory trick:** **Inspector = the building inspector checking for cracks (vulnerabilities).**

### 5.4.5 AWS Artifact
- **Simple meaning:** A portal to **download AWS's compliance reports and agreements**.
- **Technical meaning:** A self-service portal for **AWS security & compliance reports** (SOC 1/2/3, ISO 27001, PCI DSS, etc.) and **agreements** (e.g., **BAA** for HIPAA). Also provides **third-party ISV compliance reports**.
- **Exam keyword:** "download compliance reports", "SOC reports", "ISO certification evidence", "auditor needs AWS compliance documents"
- **Memory trick:** **Artifact = the archive of official certificates.**

### 5.4.6 AWS Trusted Advisor
- **Simple meaning:** An **advisor** that checks your account and gives **best-practice recommendations**.
- **Technical meaning:** Inspects your AWS environment and recommends improvements across **cost optimization, performance, security, fault tolerance, service limits (quotas), and operational excellence**.
- **Exam keyword:** "best practice recommendations", "cost optimization checks", "security checks (e.g., MFA on root, open ports)"
- **Memory trick:** **Trusted Advisor = a consultant's checklist.**

### 5.4.7 AWS Audit Manager
- **Simple meaning:** Automates **collecting evidence** for audits.
- **Technical meaning:** Continuously collects evidence to assess compliance with standards/regulations. It includes a **Generative AI best practices framework** for Bedrock/SageMaker.
- **Keyword:** "collect audit evidence", "prepare for audits continuously"

### 5.4.8 Other security services to recognize
| Service | One-liner | Keyword |
|---|---|---|
| **Amazon GuardDuty** | **Threat detection** using logs (CloudTrail, VPC Flow Logs, DNS) and ML to find malicious activity | "detect threats/compromised accounts/malicious activity" |
| **AWS Security Hub** | Central view of security findings + compliance checks | "aggregate security findings" |
| **Amazon Detective** | Investigate root cause of security findings | "investigate incident" |
| **AWS WAF** | Web application firewall | "block malicious web requests" |
| **AWS Shield** | DDoS protection | "DDoS" |
| **IAM Access Analyzer** | Finds resources shared externally; validates least privilege | "unintended access" |
| **AWS Organizations / SCPs** | Central governance across accounts; guardrail policies | "multi-account governance" |
| **AWS Control Tower** | Set up governed multi-account environments | "landing zone" |

### IAM vs KMS vs Secrets Manager vs Macie vs CloudTrail vs Config vs Inspector vs Artifact vs Trusted Advisor (MEMORIZE)

| Service | Question it answers | Protects/does | Keyword | Memory |
|---|---|---|---|---|
| **IAM** | **Who** can do **what**? | Access control (authN + authZ) | "permissions", "least privilege", "roles" | "I Am" |
| **KMS** | How are **encryption keys** managed? | Create/rotate/control keys | "encryption keys", "CMK" | Key maker |
| **Secrets Manager** | Where do I safely store **passwords/API keys**? | Store + rotate secrets | "credentials", "rotate", "hard-coded" | Password vault |
| **Macie** | Where is **sensitive data (PII)** in **S3**? | Discover/classify sensitive data | "PII in S3" | Secret finder |
| **CloudTrail** | **Who did what API call, when**? | Audit log of actions | "API activity", "audit trail" | Footprints |
| **CloudWatch** | How is my app **performing**? | Metrics, logs, alarms | "monitor", "latency", "alarms" | Health monitor |
| **Config** | How are resources **configured**; are they **compliant**? | Config history + rules | "configuration changes", "compliance rules" | Config history |
| **Inspector** | Does my software have **vulnerabilities**? | Vulnerability scanning (EC2, ECR, Lambda) | "CVE", "vulnerability" | Building inspector |
| **Artifact** | Where are AWS's **compliance reports**? | Download SOC/ISO/PCI reports, BAA | "compliance reports" | Certificate archive |
| **Trusted Advisor** | Am I following **best practices**? | Recommendations (cost, security, limits…) | "best practices", "recommendations" | Consultant |
| **GuardDuty** | Is someone **attacking** me? | Threat detection | "malicious activity" | Guard dog |

### IF THE QUESTION SAYS… → THINK…
130. "Auditors need to know who invoked a Bedrock model and when" → **AWS CloudTrail**
131. "Monitor model latency and invocation counts; alarm on errors" → **Amazon CloudWatch**
132. "Record prompts and responses sent to Bedrock for auditing" → **Bedrock model invocation logging → CloudWatch Logs / S3**
133. "Track configuration changes and check that resources meet compliance rules" → **AWS Config**
134. "Scan EC2/containers/Lambda for software vulnerabilities" → **Amazon Inspector**
135. "Download AWS SOC 2 / ISO compliance reports for an audit" → **AWS Artifact**
136. "Get recommendations on cost, security, and service limits" → **AWS Trusted Advisor**
137. "Detect malicious activity or compromised credentials" → **Amazon GuardDuty**

---

## 5.5 SECURING GENAI APPLICATIONS (NEW EMPHASIS IN v1.1)

### 5.5.1 Application security
- Secure the whole GenAI app: **authentication/authorization** (Cognito/IAM), **input validation**, **output validation/filtering**, **least-privilege** access to tools/data, **secure secrets**, **rate limiting** (API Gateway throttling), **WAF**, **logging**, **dependency/vulnerability scanning** (Inspector).

### 5.5.2 Threat detection
- Identify attacks and misuse: **GuardDuty** (account/infra threats), monitoring prompt-attack detections from **Guardrails** (CloudWatch metrics), anomaly alerts on usage/cost spikes.

### 5.5.3 Vulnerability management
- Continuously find and fix weaknesses: **Inspector** (software CVEs), patching, dependency updates, **red teaming** of the GenAI app (test prompt injection/jailbreaks), security reviews.

### 5.5.4 Infrastructure protection
- VPC isolation, **PrivateLink**, security groups, WAF, Shield, encryption.

### 5.5.5 Prompt injection defense (security view)
- **Guardrails prompt attack filter** (detects jailbreak & injection attempts)
- **Input validation & sanitization**; separate trusted instructions from untrusted data with **delimiters/tags**
- **Least privilege** for agents' tools (**AgentCore Identity**) + **deterministic tool-call rules (Policy in AgentCore)**
- **Human confirmation** for sensitive actions
- **Output validation** (check responses before acting on them)
- **Monitoring & logging** of attempts

### 5.5.6 Data leakage defense
- Guardrails **sensitive information filters** (mask/block PII), **Macie** (scan sources), **RAG access controls/metadata filtering** (users retrieve only documents they're allowed to see), encryption, don't put secrets in prompts, **least privilege**.

### 5.5.7 Output filtering
- **Simple meaning:** Checking the model's answer and **removing or blocking bad parts** before the user sees it.
- **Technical meaning:** Applying filters on model outputs (harmful content, PII, denied topics, profanity) → **Bedrock Guardrails** on responses.
- **Keyword:** "filter model responses", "block harmful output"

### 5.5.8 Output validation
- **Simple meaning:** Checking the model's answer is **correct and in the right format** before using it (especially before an agent **acts** on it).
- **Technical meaning:** Programmatic checks of outputs: **schema/format validation** (valid JSON?), business-rule checks, **grounding/factuality checks** (contextual grounding, Automated Reasoning), confidence thresholds, and human review for high-risk outputs.
- **Keyword:** "validate response format", "verify before executing", "ensure output meets rules"
- **Filtering vs validation:** Filtering = **remove harmful content**. Validation = **confirm correctness/format/compliance**.

### 5.5.9 Hallucination detection & RAG grounding (NEW)
- **Grounding** = anchoring responses to trusted source data (RAG).
- **Hallucination detection methods:**
  - **Guardrails contextual grounding check** (grounding + relevance scores vs a threshold → block ungrounded responses)
  - **Automated Reasoning checks** (logical verification against defined policies)
  - **RAG evaluation** in Bedrock (faithfulness/correctness metrics)
  - **LLM-as-a-judge** reviewing answers
  - **Citations** so users can verify
- **Keyword:** "ensure responses are supported by source documents", "detect ungrounded answers"

### 5.5.10 Confidence scoring
- **Simple meaning:** A number showing **how sure** the model or system is about its output.
- **Technical meaning:** A probability/score attached to predictions (e.g., Rekognition label confidence 97%, Textract confidence, classification probability, grounding score in Guardrails). Used to **route low-confidence outputs to humans** (**A2I**) or reject them.
- **Keyword:** "confidence threshold", "low-confidence predictions → human review"
- **Exam trap:** High confidence ≠ guaranteed correctness (LLMs can be confidently wrong). Combine with grounding checks and human review.

### 5.5.11 Toxicity
- Harmful, offensive, or abusive content. **Detect/prevent:** Guardrails content filters, Bedrock Model Evaluation (toxicity metric), Comprehend toxicity detection.

### 5.5.12 Audit trails & logging (AI audit logging, NEW)
- **Simple meaning:** Keeping a record of **who used the AI, what was asked, what it answered, and what actions it took**, so you can investigate and prove compliance.
- **AWS:**
  - **CloudTrail** → API calls (management + data events)
  - **Bedrock model invocation logging** → full **prompts, responses, metadata** to **CloudWatch Logs / S3** (**disabled by default; you must enable it**)
  - **CloudWatch** → metrics/alarms (guardrail interventions, latency, tokens)
  - **AgentCore Observability** → agent traces (each reasoning step and tool call)
  - **Guardrails trace** → which policy blocked what
- **Exam trap:** CloudTrail logs **that** `InvokeModel` was called; **invocation logging** captures **what** the prompt/response **content** was.

### Securing agentic AI: summary checklist
1. **Identity**: each agent has its own identity (AgentCore Identity), no hard-coded secrets
2. **Least privilege**: minimal permissions for tools and data (IAM + AgentCore Identity)
3. **Deterministic rules on actions**: Policy in AgentCore (Cedar, default-deny)
4. **Content safety**: Guardrails on inputs & outputs
5. **Human approval** for high-impact actions
6. **Isolation**: AgentCore Runtime session isolation, sandboxed Code Interpreter
7. **Observability & audit**: AgentCore Observability, CloudTrail, invocation logs
8. **Output validation** before executing actions

### IF THE QUESTION SAYS… → THINK…
138. "Ensure the model's JSON output matches the required schema before the app uses it" → **Output validation**
139. "Route predictions below 80% confidence to human reviewers" → **Confidence scoring + Amazon A2I**
140. "Keep a full record of prompts and model responses" → **Bedrock model invocation logging** (+ CloudTrail for API calls)
141. "Trace each step and tool call an agent makes" → **AgentCore Observability**
142. "Ensure RAG answers are supported by retrieved documents" → **Grounding → Guardrails contextual grounding check**

---

## 5.6 GENERATIVE AI SECURITY SCOPING MATRIX (MEMORIZE THE 5 SCOPES)

- **Simple meaning:** An AWS framework that sorts GenAI use into **5 levels ("scopes")** based on **how much of the AI you own/control**. The more you build yourself, the **more security responsibility** you have.
- **Technical meaning:** A mental model for classifying GenAI workloads to determine the security, governance, compliance, and risk-management controls needed.

| Scope | Name | Simple meaning | Example | Your control/responsibility |
|---|---|---|---|---|
| **1** | **Consumer app** | Use a **public** third-party GenAI app | Employees using a public chatbot or image app | Lowest control. Mainly usage policies, data you enter |
| **2** | **Enterprise app** | Use a **business SaaS app** with GenAI features (under an enterprise agreement) | Amazon Quick / Q Business, a SaaS tool with built-in GenAI | Low. Contract terms, data handling, access |
| **3** | **Pre-trained models** | **Build your own app** using an existing FM via API (no changes to model) | Your app calling Claude/Nova on **Amazon Bedrock** (+ RAG) | Medium. App security, prompts, RAG data, guardrails |
| **4** | **Fine-tuned models** | **Fine-tune** an existing FM with **your data** | Custom model via Bedrock fine-tuning | High. Training data security, model access, plus all of scope 3 |
| **5** | **Self-trained models** | **Train your own model from scratch** | Pre-training an FM on SageMaker HyperPod | Highest. Everything: data, training, model, infrastructure |

- **Buy vs Build:** Scopes **1–2 = "Buy"** (consume). Scopes **3–5 = "Build"**.
- **Security disciplines considered across scopes:** **governance & compliance, legal & privacy, risk management, controls, resilience**.
- **Exam keyword:** "classify GenAI use case to determine security responsibilities", "scope"
- **Exam trap:** "Company builds a chatbot using Claude on Bedrock with RAG (no fine-tuning)" → **Scope 3 (pre-trained models)**. With fine-tuning → **Scope 4**.
- **Memory trick:** **"Consumers Enter, then Pre-build, Fine-tune, Self-train" → C-E-P-F-S = 1→5 (control & responsibility increase).**

143. "Company fine-tunes a Bedrock model with proprietary data; which scope?" → **Scope 4 (Fine-tuned models)**
144. "Employees use a public GenAI chat website" → **Scope 1 (Consumer app)**

---

## 5.7 DATA GOVERNANCE (TASK 5.2)

### 5.7.1 Data governance
- **Simple meaning:** Rules and processes for **how data is collected, stored, used, shared, and deleted**, and who is responsible.
- **Technical meaning:** Framework of policies, roles, standards, and controls ensuring data is **accurate, secure, compliant, and used appropriately** across its lifecycle.
- **AWS:** **AWS Lake Formation** (fine-grained data-lake permissions), **AWS Glue Data Catalog** (catalog), **Amazon DataZone / SageMaker Catalog** (discover, share, govern data with business context), IAM, Macie, Config.

### 5.7.2 Data lineage
- **Simple meaning:** The **family tree of data**: where it came from and every change made to it on the way to the model.
- **Technical meaning:** Tracking the **origin, movement, and transformations** of data (and models) through pipelines. It supports **reproducibility, debugging, audits, and source citation**.
- **AWS:** **SageMaker ML Lineage Tracking**, SageMaker Catalog/DataZone lineage, Glue.
- **Keyword:** "trace data origin", "track transformations", "which data trained this model"
- **Memory trick:** **Lineage = data's family tree.**

### 5.7.3 Data cataloging
- **Simple meaning:** A **searchable inventory** (like a library catalog) of all your datasets and what's in them.
- **Technical meaning:** Maintaining metadata (schema, location, owner, classification) about datasets so they're discoverable and governable.
- **AWS:** **AWS Glue Data Catalog**, Amazon DataZone / SageMaker Catalog.
- **Keyword:** "discover datasets", "metadata", "inventory of data"
- **Memory trick:** **Catalog = library index card.**

### 5.7.4 Data quality
- Accurate, complete, consistent, timely, valid data. **AWS:** **AWS Glue Data Quality**, SageMaker Data Wrangler, Model Monitor (data-quality drift).

### 5.7.5 Data integrity
- **Simple meaning:** Data hasn't been **changed or corrupted** by accident or on purpose.
- **Technical meaning:** Assurance that data is accurate, consistent, and unaltered (checksums, versioning, access controls, **S3 Object Lock**, logging). It protects against **poisoning**.
- **Keyword:** "data not tampered", "consistency"

### 5.7.6 Data access control
- Only authorized people/services access data: **IAM**, **S3 bucket policies**, **Lake Formation** fine-grained permissions, KMS key policies, **RAG metadata filtering** per user.

### 5.7.7 Data lifecycle, residency, retention
| Concept | Simple meaning | AWS |
|---|---|---|
| **Data lifecycle** | Managing data from creation → storage → use → archive → deletion | **S3 Lifecycle policies** (move to cheaper storage / delete) |
| **Data residency** | Data must stay in a specific **country/Region** (laws like GDPR) | Choose AWS **Region**; Bedrock keeps data in-Region; be careful with cross-region inference |
| **Data retention** | How long data is kept (and deleted after) | S3 Lifecycle, retention policies, Object Lock, CloudWatch Logs retention |
| **Data logging** | Recording data access/use | CloudTrail data events, S3 access logs |
| **Data monitoring** | Watching data quality/drift/access | Model Monitor, Macie, CloudWatch |

- **Exam trap:** "Data must never leave the EU" → **data residency** → deploy in an EU Region and avoid cross-region routing outside it.

### 5.7.8 Privacy
- Protect personal data per laws/policies: consent, minimization, anonymization, encryption, access control, **right to deletion**.

### 5.7.9 Source citation & documenting data origins
- Citing sources in RAG outputs; documenting data provenance (lineage, Model Cards) for transparency.

### IF THE QUESTION SAYS… → THINK…
145. "Track where training data came from and how it was transformed" → **Data lineage (SageMaker ML Lineage Tracking)**
146. "Create a searchable inventory of datasets with metadata" → **Data cataloging (AWS Glue Data Catalog / SageMaker Catalog)**
147. "Automatically delete training data after 1 year" → **Data retention → S3 Lifecycle policies**
148. "Data must stay within a specific country" → **Data residency (choose Region)**

---

## 5.8 GOVERNANCE & COMPLIANCE FOR AI

### 5.8.1 Governance
- **Simple meaning:** The **rules, roles, and oversight** that make sure AI is used safely, legally, and according to company values.
- **Technical meaning:** Policies, review processes, accountability structures, documentation, and monitoring across the AI lifecycle: **governance boards/committees**, approval workflows, risk assessments, audits, **transparency standards**, **team training**.
- **Governance strategies (from the guide):** policies, **review cadence**, **review strategies**, **governance frameworks** (e.g., the Generative AI Security Scoping Matrix), **transparency standards**, **team training requirements**, data governance.
- **AWS tools:** **SageMaker Model Cards**, **Model Registry**, **Model Dashboard**, **SageMaker Role Manager**, **AWS Audit Manager**, **AWS Config**, **CloudTrail**, **AWS Organizations**, Bedrock Guardrails (policy enforcement).

### 5.8.2 SageMaker Model Cards (governance view)
- Document **intended use, risk rating, training data/details, evaluation metrics, ethical considerations, caveats**. **Immutable versions** give an audit trail. Can be exported as PDF for stakeholders/auditors.
- **Keyword:** "document model for governance/audits", "model risk rating"

### 5.8.3 Compliance standards to recognize (names only)
| Standard | Area |
|---|---|
| **ISO/IEC 42001** | **AI management systems** (AWS is certified for AI services incl. Bedrock) |
| **ISO 27001** | Information security management |
| **SOC 1/2/3** | Service organization controls |
| **GDPR** | EU data privacy |
| **HIPAA** | US health data |
| **PCI DSS** | Payment card data |
| **EU AI Act** | EU AI regulation (risk-based) |
| **NIST AI RMF** | NIST AI Risk Management Framework |
| **Algorithm accountability laws** | Require transparency/fairness in automated decisions |

- **Unique AI compliance challenges:** complexity/opacity of models, **bias**, **explainability** requirements, IP/copyright, **data privacy** in training data, **hallucinations**, **evolving regulations**, **algorithmic accountability**.

### 5.8.4 Monitoring (governance view)
- Monitor **model quality/drift** (Model Monitor), **usage & cost** (CloudWatch, Cost Explorer), **guardrail interventions**, **access & API activity** (CloudTrail), **configuration compliance** (Config).

### 5.8.5 Transparency (governance view)
- Model Cards, AI Service Cards, disclosing AI use to users, citations, documentation of limitations.

### IF THE QUESTION SAYS… → THINK…
149. "Collect evidence continuously to prepare for compliance audits of GenAI workloads" → **AWS Audit Manager**
150. "Establish a regular process to review AI models for risk" → **Governance: review cadence/strategy, governance board, Model Cards**
151. "Certification for AI management systems" → **ISO/IEC 42001**

---

## DOMAIN 5 — FAST RECAP
- Shared responsibility: AWS = OF the cloud; you = IN the cloud (data, IAM, config, guardrails).
- IAM = who/what (roles for services, least privilege). AuthN = who you are; AuthZ = what you can do.
- AgentCore Identity = agent credentials/OAuth on behalf of users. Policy in AgentCore = Cedar rules on every tool call (default-deny, deterministic).
- KMS = keys; Secrets Manager = passwords/API keys; Macie = PII in S3; PrivateLink = private tunnel to Bedrock.
- CloudTrail = who did what (API). CloudWatch = metrics/logs/alarms. Config = config compliance. Inspector = vulnerabilities. Artifact = compliance reports. Trusted Advisor = best-practice recommendations. GuardDuty = threats.
- Invocation logging = prompt/response content (enable it!).
- Output filtering (remove harmful) vs output validation (check correctness/format). Confidence scores → A2I.
- Scoping Matrix: 1 Consumer app, 2 Enterprise app, 3 Pre-trained models, 4 Fine-tuned models, 5 Self-trained models.
- Data governance: lineage (family tree), catalog (index), quality, integrity, access control, lifecycle, residency (Region), retention (S3 Lifecycle).

**➡ Continue to PART 6 — AWS Service Cheat Sheet + "Which Service Do I Choose?"**
