# PART 6 — AIF-C01 MASTER NOTES

# AWS SERVICE CHEAT SHEET + "WHICH AWS SERVICE DO I CHOOSE?"

Format for every service: **What it does → When to choose it → Exam keyword → Memory trick**

---

## 6.1 GENERATIVE AI SERVICES (HIGHEST PRIORITY)

### Amazon Bedrock
- **What:** Fully managed, **serverless** service to access many **foundation models** (Amazon Nova/Titan, Anthropic, Meta, Mistral, Cohere, AI21, Stability AI, DeepSeek, OpenAI open-weight…) through **one API**. Includes customization, Knowledge Bases, Agents, Guardrails, Model Evaluation, Prompt Management, Flows, batch inference, prompt caching.
- **Choose when:** You want to build GenAI apps **quickly** with **no infrastructure** to manage and **choice of models**.
- **Keyword:** "foundation models via API", "serverless GenAI", "least operational overhead", "multiple FMs"
- **Memory:** **Bedrock = model buffet with one API.**

### Amazon Bedrock Knowledge Bases
- **What:** Fully managed **RAG**: ingests data (S3, web, Confluence, SharePoint, Salesforce…), chunks, embeds, stores in vector DB, retrieves, and generates answers **with citations**.
- **Choose when:** An FM must answer from **company/private/current documents**.
- **Keyword:** "RAG", "company documents", "citations", "ground responses"
- **Memory:** **Knowledge Base = the model's company library.**

### Amazon Bedrock Agents
- **What:** Fully managed agents that use FM reasoning to **plan and execute multi-step tasks**, calling APIs via **action groups** (Lambda + OpenAPI schema) and querying Knowledge Bases. Supports memory, user confirmation, code interpretation, **multi-agent collaboration** (supervisor).
- **Choose when:** The app must **take actions** (book, update, refund, create tickets) with minimal setup.
- **Keyword:** "perform tasks", "call APIs", "multi-step", "orchestrate actions"
- **Memory:** **Agents = the assistant who does the errands.**

### Amazon Bedrock AgentCore
- **What:** Enterprise platform to **deploy and operate AI agents securely at scale**, using **any framework** (Strands, LangGraph, CrewAI…) and **any model**. Components: **Runtime, Memory, Gateway (MCP tools), Identity, Policy, Code Interpreter, Browser, Observability, Evaluations**.
- **Choose when:** You built agents with open-source frameworks and need production-grade **hosting, memory, tool connectivity (MCP), identity, policy controls, observability**.
- **Keyword:** "run agents at scale", "any framework", "agent identity", "MCP gateway", "agent observability"
- **Memory:** **AgentCore = the agent's operating base (the airport where agents take off and land safely).**

### Amazon Bedrock Guardrails
- **What:** Configurable safeguards on inputs and outputs: **content filters** (hate, insults, sexual, violence, misconduct, **prompt attacks**), **denied topics**, **word filters**, **sensitive info (PII) filters** (block/mask), **contextual grounding check** (hallucinations), **Automated Reasoning checks**. Works across models; `ApplyGuardrail` API for any model.
- **Choose when:** "Prevent harmful content", "block topics", "mask PII", "detect hallucinations/prompt attacks".
- **Keyword:** "safety", "responsible AI policies", "filter", "block", "redact"
- **Memory:** **Guardrails = the bouncer.**

### Amazon Bedrock Model Evaluation
- **What:** Evaluate & compare FMs (and RAG) with **automatic metrics**, **human evaluation**, or **LLM-as-a-judge**.
- **Choose when:** "Which model is best for our use case?"
- **Keyword:** "compare models", "evaluate accuracy, toxicity, robustness"
- **Memory:** **Model Evaluation = the model exam hall.**

### Amazon Bedrock Prompt Management
- **What:** Create, test, **version**, and share prompts/templates with variables; use them in apps and Flows.
- **Choose when:** "Reuse, version, and manage prompts across teams."
- **Keyword:** "prompt versioning", "prompt templates", "manage prompts"
- **Memory:** **Git for prompts.**

### Amazon Bedrock Flows
- **What:** Visual builder to **link prompts, FMs, Knowledge Bases, Agents, Lambda, and Guardrails** into a **workflow**.
- **Choose when:** "Build a predefined multi-step GenAI workflow with low code."
- **Keyword:** "workflow", "chain steps", "visual builder"
- **Memory:** **Flows = the assembly line.**

### Amazon Bedrock custom models (fine-tuning, continued pre-training, distillation)
- **What:** Customize supported FMs with your data. **Fine-tuning** (labeled), **continued pre-training** (unlabeled), **Model Distillation** (teacher → student), reinforcement fine-tuning. Custom models are private; usually need **Provisioned Throughput**.
- **Keyword:** "customize model with our data", "style", "domain", "smaller cheaper model"

### Amazon Bedrock Data Automation (MEDIUM PRIORITY)
- **What:** GenAI-powered extraction of structured insights from **documents, images, audio, video** (multimodal content processing).
- **Keyword:** "extract insights from unstructured multimodal content"

### Amazon Nova (Amazon's FMs in Bedrock)
- **What:** Amazon's family of FMs: **Nova Micro** (text-only, fastest, cheapest), **Nova Lite** (low-cost multimodal), **Nova Pro** (capable multimodal), **Nova Premier** (most capable, good teacher for distillation), **Nova Canvas** (image generation/editing), **Nova Reel** (video generation), **Nova Sonic** (real-time speech-to-speech conversation), **Nova Act** (agent that performs actions in web browsers), Nova multimodal embeddings.
- **Choose when:** You want cost-effective, AWS-native FMs; image/video generation; speech conversation.
- **Keyword:** "Amazon's own foundation models", "cost-effective", "image/video generation"
- **Memory:** **Micro-Lite-Pro-Premier = Small → Big. Canvas = pictures, Reel = videos, Sonic = voice, Act = actions.**

### Amazon Titan (older Amazon FM family, still in exams)
- **What:** **Titan Text Embeddings** (very common in RAG questions), Titan Multimodal Embeddings, Titan Image Generator, Titan Text models.
- **Keyword:** "embeddings model on Bedrock" → Titan Text Embeddings.

### Amazon SageMaker AI
- **What:** Fully managed platform to **build, train, tune, deploy, and monitor your own ML models** with full control (notebooks, training jobs, endpoints, MLOps).
- **Choose when:** **Custom ML models**, full control over training/infrastructure, traditional ML on tabular data, custom deployment.
- **Keyword:** "build/train/deploy custom models", "data scientists", "full control"
- **Memory:** **SageMaker = the ML workshop/factory.**

### Amazon SageMaker JumpStart
- **What:** **ML hub** with **pre-trained models** (including open-source FMs like Llama, Mistral, Falcon) and solution templates. **One-click deploy/fine-tune** into **your SageMaker** environment.
- **Choose when:** "Quickly deploy/fine-tune a pre-trained or open-source model in our own account/VPC with control over instances."
- **Keyword:** "pre-trained models", "model hub", "one-click deploy", "open-source FM on SageMaker"
- **Memory:** **JumpStart = jump-start with a ready-made model.**

### Amazon SageMaker Canvas
- **What:** **No-code** visual ML for business analysts (predictions, forecasting, data prep; can use FMs too).
- **Keyword:** "no code", "business analyst", "no ML expertise"

### Other SageMaker features (Domain 1/4/5)
| Feature | What | Keyword |
|---|---|---|
| **Clarify** | Bias detection + explainability; FM evaluation | "bias", "explain", "feature importance" |
| **Model Monitor** | Drift & quality monitoring in production | "drift", "degraded over time" |
| **Model Cards** | Model documentation for governance | "document intended use/risk" |
| **Model Registry** | Catalog, version, approve models | "model versions", "approval" |
| **Model Dashboard** | Central view of models, monitors, cards | "overview of all models" |
| **Pipelines** | MLOps workflow automation | "automate ML workflow", "CI/CD" |
| **Ground Truth** | Human data labeling (+ RLHF data) | "label data" |
| **Data Wrangler** | Visual data preparation | "prepare data, little code" |
| **Feature Store** | Store/reuse features | "share features" |
| **Experiments / MLflow** | Track experiments | "compare runs" |
| **Automatic Model Tuning** | Hyperparameter optimization | "best hyperparameters" |
| **Debugger** | Debug training | "training problems" |
| **Role Manager** | Least-privilege personas for ML | "ML permissions quickly" |
| **HyperPod** | Resilient clusters for large-scale FM training | "train FMs at scale" (LOW PRIORITY) |
| **Unified Studio** | Single environment for data, analytics, ML, GenAI (Bedrock) | "one studio for data + AI" |

### Amazon Augmented AI (Amazon A2I)
- **What:** Adds **human review workflows** to ML predictions (Textract, Rekognition, custom). Trigger on **low confidence** or random sampling.
- **Keyword:** "human review", "low confidence", "human-in-the-loop"
- **Memory:** **A2I = Augmented with 2 human Eyes.**

### Amazon Quick (Amazon Quick Suite)
- **What:** **Agentic AI workspace for business users**: chat with company data (connected to wikis, apps, S3, Redshift; MCP to 1,000+ apps), deep research, **BI dashboards (QuickSight)**, and **workflow automation**. Enterprise security; queries not used to train models.
- **Choose when:** "Employees need an AI assistant to find answers, analyze data, and automate tasks across company tools, **without building** an app."
- **Keyword:** "business users", "enterprise AI assistant", "research + BI + automation"
- **Memory:** **Quick = quick answers + quick automations for employees.**

### Amazon Q Business / Amazon Q Developer
- **Q Business:** GenAI assistant that answers questions from enterprise data sources (related to Amazon Quick). **Keyword:** "employee Q&A over company data, no build".
- **Q Developer:** AI coding assistant (IDE, CLI, console), code generation, security scans, code transformation (e.g., Java upgrades), AWS help. **Keyword:** "developer assistant", "code suggestions", "upgrade code".

### Kiro
- **What:** AWS's **agentic AI IDE**: **spec-driven development** (prompt → requirements → design → tasks → code), **agent hooks** (automations on events), MCP support.
- **Keyword:** "AI IDE", "spec-driven development", "from prototype to production code"
- **Memory:** **Kiro = the AI coding co-worker with a plan (specs).**

### Strands Agents
- **What:** **Open-source SDK** (from AWS) for building AI agents with a **model-driven** approach (model + prompt + tools). Supports MCP, multi-agent patterns, many model providers; deploys to AgentCore/Lambda/containers.
- **Keyword:** "open-source agent SDK", "build agents in a few lines of code"
- **Memory:** **Strands = the threads you weave an agent from.**

### PartyRock (an Amazon Bedrock Playground)
- **What:** Free, **no-code** playground to **learn prompt engineering** by building small GenAI apps.
- **Keyword:** "learn/experiment with GenAI, no code"

---

## 6.2 AI SERVICES (PRE-TRAINED, "API-READY"; NO ML EXPERTISE NEEDED)

| Service | What it does | Choose when | Exam keyword | Memory trick |
|---|---|---|---|---|
| **Amazon Rekognition** | Image & video analysis: objects, scenes, **faces** (detection/comparison), celebrities, text in images, **content moderation** (unsafe images), PPE detection, custom labels | Analyze **images/videos** | "detect objects/faces", "moderate images", "video analysis" | **Recognize** what's in pictures |
| **Amazon Textract** | Extracts **printed & handwritten text, forms (key-value pairs), tables** from scanned documents; specialized APIs for invoices/receipts (AnalyzeExpense), IDs (AnalyzeID), lending | **Documents** → structured data | "extract text/tables/forms from scanned documents", "OCR" | **Text-extract** |
| **Amazon Transcribe** | **Speech-to-text** (ASR): call transcripts, subtitles, speaker identification, PII redaction, custom vocabulary; **Transcribe Medical**; **Call Analytics** | Audio → text | "speech to text", "transcribe calls", "subtitles" | **Transcribe = writes down what's said** |
| **Amazon Polly** | **Text-to-speech**: lifelike voices, many languages, **SSML** control, neural/generative voices | Text → audio | "text to speech", "read aloud", "voice" | **Polly the parrot talks** |
| **Amazon Translate** | Neural **machine translation** between languages; custom terminology; real-time & batch | Translate text | "translate", "multilingual", "localize" | **Translate** |
| **Amazon Comprehend** | **NLP text analytics**: **sentiment**, **entities**, key phrases, language detection, topic modeling, **PII detection/redaction**, **toxicity detection**, custom classification & entities; **Comprehend Medical** (medical entities, PHI) | Analyze text | "sentiment", "extract entities", "key phrases", "classify documents", "detect PII in text" | **Comprehend = understand text** |
| **Amazon Lex** | Build **conversational interfaces (chatbots/voicebots)**: intents, slots, speech + text; same tech as Alexa; integrates with **Amazon Connect**, Lambda, Bedrock (generative features) | Chatbot / IVR with structured intents | "chatbot", "conversational interface", "voice bot", "intents" | **Lex = Lexicon for talking bots** |
| **Amazon Personalize** | Real-time **personalized recommendations** (the same tech as Amazon.com) from user interaction data | Recommendations | "recommend products", "personalized", "customers who bought" | **Personalize = personal shopper** |
| **Amazon Kendra** | **Intelligent enterprise search** across documents with natural-language questions; many connectors; can be a **RAG retriever** | Search internal documents | "enterprise search", "search across document repositories" | **Kendra = Knowledge finder** |
| **Amazon Connect** | Cloud **contact center** with AI features (Contact Lens analytics, agent assist) | Contact center | "call center" | **Connect callers** |
| **Amazon Comprehend Medical / Transcribe Medical / HealthScribe** | Medical NLP / speech / clinical note generation | Healthcare | "clinical notes", "PHI" | Medical versions |
| **Amazon Fraud Detector** | Managed fraud detection (**closed to new customers**) | — | **LOW PRIORITY** | — |
| **Amazon Forecast** | Time-series forecasting (**closed to new customers**; use SageMaker Canvas) | — | **LOW PRIORITY** | — |
| **Amazon Lookout for Vision/Equipment/Metrics** | Anomaly detection (**being discontinued**) | — | **LOW PRIORITY** | — |
| **AWS DeepRacer** | RL learning via racing cars (retired from console) | RL learning example | "reinforcement learning" (LOW PRIORITY) | — |
| **AWS HealthLake, Panorama, DeepLens, Monitron** | Specialized/legacy | — | **OUT OF SCOPE / LOW PRIORITY** | — |

---

## 6.3 DATA, STORAGE & DATABASE SERVICES (AS THEY RELATE TO AI)

| Service | What it does | AI relevance | Keyword | Memory |
|---|---|---|---|---|
| **Amazon S3** | Object storage (virtually unlimited, durable) | **Store training data, documents for Knowledge Bases, model artifacts, batch inference input/output, logs** | "store data", "data lake", "documents" | **S3 = Simple Storage bucket** |
| **Amazon OpenSearch Service / Serverless** | Search & analytics engine with **vector search (k-NN)** | **Default vector store for Bedrock KBs**, hybrid search | "vector search", "semantic search" | **OpenSearch = Search** |
| **Amazon Aurora** (PostgreSQL) | High-performance managed relational DB; **pgvector** | Vectors + relational data together | "PostgreSQL-compatible + vectors" | **Aurora = high-end Postgres** |
| **Amazon RDS** (for PostgreSQL) | Managed relational DB (PostgreSQL, MySQL, etc.); PostgreSQL supports **pgvector** | Vector store for RAG with existing RDS | "managed relational DB", "pgvector" | **RDS = Relational Database Service** |
| **Amazon Neptune** | **Graph** database (Neptune Analytics supports vectors) | **GraphRAG**, knowledge graphs | "relationships", "graph" | **Neptune = Network of nodes** |
| **Amazon DocumentDB** | MongoDB-compatible document DB with vector search | JSON docs + vectors | "MongoDB-compatible" | Document DB |
| **Amazon DynamoDB** | Serverless NoSQL key-value DB | Chat history/session storage, app data (not a typical vector store answer) | "key-value", "session state" | Dynamo = fast NoSQL |
| **Amazon MemoryDB** | In-memory DB; fastest vector search | Ultra-low-latency vector search | "in-memory", "microseconds" | Memory-fast |
| **Amazon S3 Vectors** | Native vector buckets in S3 | Cheapest large-scale vector storage (supported by KBs) | "cost-optimized vectors" | Storage-cheap vectors |
| **Amazon Redshift** | Data warehouse | Analytics; KBs can query structured data (NL→SQL) | "data warehouse" | Big analytics |
| **AWS Glue** | Serverless **ETL** + **Data Catalog** + Data Quality | Prepare/clean/catalog data for ML | "ETL", "catalog", "data quality" | Glue sticks data together |
| **AWS Lake Formation** | Build & **govern** data lakes (fine-grained permissions) | Data access control | "data lake permissions" | Lake guard |
| **Amazon DataZone / SageMaker Catalog** | Data catalog, sharing & governance with business context | Governance, lineage | "discover and govern data" | — |
| **Amazon EMR / Athena / Kinesis** | Big data processing / SQL on S3 / streaming | Data pipelines (LOW PRIORITY for AIF) | — | — |

---

## 6.4 COMPUTE & NETWORKING

| Service | What | AI relevance | Keyword | Memory |
|---|---|---|---|---|
| **Amazon EC2** | Virtual servers (you manage OS) | Self-managed ML; GPU instances (P, G families); **Trainium (Trn)** for training, **Inferentia (Inf)** for inference | "full control of servers", "GPU instances" | **EC2 = rent a computer** |
| **AWS Trainium / Inferentia** | AWS custom AI chips | Lower cost & energy for training (Trainium) and inference (Inferentia) | "cost-effective, energy-efficient training/inference" | **Train-ium trains, Infer-entia infers** |
| **AWS Lambda** | **Serverless functions** run on events (pay per ms) | **Bedrock Agents action groups**, pre/post-processing, custom chunking, glue logic | "serverless code", "event-driven", "action group" | **Lambda = little function that runs on demand** |
| **Amazon ECS / EKS / Fargate** | Containers | Hosting AI apps (LOW PRIORITY) | "containers" | — |
| **Amazon API Gateway** | Create/secure/throttle APIs | Front door for GenAI apps; rate limiting | "expose API", "throttling" | — |
| **AWS Step Functions** | Serverless workflow orchestration | Orchestrate ML/GenAI steps | "orchestrate workflow" | — |
| **Amazon VPC** | Private isolated network | Network isolation for ML | "private network" | Fenced yard |
| **AWS PrivateLink** (VPC endpoints) | Private connectivity to AWS services | Bedrock/SageMaker without internet | "no public internet" | Private tunnel |
| **Amazon Cognito** | User sign-up/sign-in for apps | Authenticate users of GenAI apps; AgentCore Identity inbound auth | "app user authentication" | — |

---

## 6.5 SECURITY, COMPLIANCE, GOVERNANCE & MONITORING

| Service | What | Choose when | Keyword | Memory |
|---|---|---|---|---|
| **AWS IAM** | Users, groups, roles, policies | Control **who** can do **what** | "permissions", "least privilege" | "I Am" |
| **AWS IAM Identity Center** | SSO for workforce across accounts/apps | Employee single sign-on | "SSO" | — |
| **AWS KMS** | Encryption key management | Encrypt data with managed/customer keys | "encryption keys" | Key maker |
| **AWS Secrets Manager** | Store & rotate secrets | Credentials/API keys | "rotate credentials" | Password vault |
| **Amazon Macie** | Find sensitive data (PII) in S3 | Data discovery before training/RAG | "PII in S3" | Secret finder |
| **AWS CloudTrail** | API activity logging | Audit who did what | "audit", "API calls" | Footprints |
| **Amazon CloudWatch** | Metrics, logs, alarms, dashboards | Monitor performance/usage; invocation logs | "monitor", "metrics", "alarms" | Health monitor |
| **AWS Config** | Resource configuration history & compliance rules | Config compliance | "configuration changes" | Config history |
| **Amazon Inspector** | Vulnerability scanning (EC2, ECR, Lambda) | Find CVEs | "vulnerabilities" | Building inspector |
| **AWS Artifact** | Compliance reports & agreements | Download SOC/ISO/PCI, BAA | "compliance reports" | Certificate archive |
| **AWS Trusted Advisor** | Best-practice checks | Cost/security/performance/limits recommendations | "recommendations" | Consultant |
| **AWS Audit Manager** | Continuous audit evidence collection | Audit readiness (incl. GenAI framework) | "audit evidence" | Evidence collector |
| **Amazon GuardDuty** | Threat detection | Malicious activity | "threats" | Guard dog |
| **AWS Security Hub** | Central security findings | Aggregate findings | "single pane of security" | — |
| **AWS WAF / Shield** | Web firewall / DDoS protection | Protect app front-end | "web exploits", "DDoS" | — |
| **AWS Organizations** | Multi-account management + SCPs | Central governance | "multiple accounts" | — |
| **AWS Cost Explorer / Budgets** | Track and alert on spend | GenAI cost control | "cost tracking", "budget alerts" | — |
| **AWS AI Service Cards** | AWS responsible-AI documentation per service | Understand AWS service limits/intended use | "service transparency" | — |

---

## 6.6 "WHICH AWS SERVICE DO I CHOOSE?" MASTER TABLE

### AI capabilities
| Need… | Choose |
|---|---|
| Speech (general, both directions) | **Transcribe** (speech→text) / **Polly** (text→speech); real-time voice conversation with an FM → **Nova Sonic** |
| Speech-to-text | **Amazon Transcribe** |
| Text-to-speech | **Amazon Polly** |
| Translation | **Amazon Translate** |
| Sentiment / text analysis / entities / key phrases | **Amazon Comprehend** |
| Detect PII in text | **Amazon Comprehend** (in GenAI app I/O → **Bedrock Guardrails**; in S3 → **Macie**) |
| Medical text entities | **Amazon Comprehend Medical** |
| Image/video analysis (objects, faces, moderation) | **Amazon Rekognition** |
| Document text extraction (forms, tables, handwriting) | **Amazon Textract** |
| Invoice/receipt data extraction | **Textract (AnalyzeExpense)** |
| Multimodal content insights (docs+images+audio+video) with GenAI | **Bedrock Data Automation** |
| Recommendations | **Amazon Personalize** |
| Chatbot (intent-based, voice/text, contact center) | **Amazon Lex** |
| GenAI chatbot over company documents | **Bedrock + Knowledge Bases** (or **Amazon Quick / Q Business** if no build) |
| Enterprise search | **Amazon Kendra** (or Bedrock KBs / Quick) |
| Contact center | **Amazon Connect** (+ Lex, Bedrock) |

### GenAI & ML building
| Need… | Choose |
|---|---|
| Foundation models (API, serverless) | **Amazon Bedrock** |
| Amazon's own FMs | **Amazon Nova** (Titan for embeddings) |
| Generate images | **Nova Canvas** / **Stability AI** / Titan Image Generator (Bedrock) |
| Generate videos | **Nova Reel** |
| Embeddings | **Titan Text Embeddings** / Cohere Embed / Nova embeddings |
| RAG | **Bedrock Knowledge Bases** (+ vector store) |
| Vector store | **OpenSearch Service** (default), Aurora/RDS PostgreSQL pgvector, Neptune (graph), S3 Vectors (cheap), MemoryDB (fastest) |
| AI agents (managed, quick) | **Bedrock Agents** |
| AI agents at scale / any framework | **Bedrock AgentCore** |
| Build agents with open-source SDK | **Strands Agents** |
| Connect agents to tools (standard protocol) | **MCP** (via **AgentCore Gateway**) |
| Agent credentials / OAuth on behalf of users | **AgentCore Identity** |
| Restrict agent tool calls deterministically | **Policy in AgentCore** |
| Agent memory | **AgentCore Memory** |
| Agent tracing/debugging | **AgentCore Observability** (CloudWatch) |
| Fixed multi-step GenAI workflow | **Bedrock Flows** (or Step Functions) |
| Manage/version prompts | **Bedrock Prompt Management** |
| Safety filters / PII masking / denied topics / hallucination check | **Bedrock Guardrails** |
| Compare/evaluate FMs | **Bedrock Model Evaluation** |
| Customize FM (style) | **Bedrock fine-tuning** |
| Customize FM (domain, unlabeled data) | **Bedrock continued pre-training** |
| Smaller/cheaper model with similar accuracy | **Bedrock Model Distillation** |
| Guaranteed throughput / host custom model | **Bedrock Provisioned Throughput** |
| Large offline prompt jobs | **Bedrock batch inference** |
| Reduce cost of repeated long prompts | **Bedrock prompt caching** |
| Model training (custom ML) | **Amazon SageMaker AI** |
| Pretrained ML models / open-source FMs in your account | **SageMaker JumpStart** |
| No-code ML | **SageMaker Canvas** |
| Data labeling | **SageMaker Ground Truth** |
| Human review of predictions | **Amazon A2I** |
| Bias detection / explainability | **SageMaker Clarify** |
| Drift monitoring | **SageMaker Model Monitor** |
| Model documentation | **SageMaker Model Cards** |
| MLOps automation | **SageMaker Pipelines** |
| Model versioning/approval | **SageMaker Model Registry** |
| Employee AI assistant (no build) | **Amazon Quick** (Q Business) |
| AI coding assistant / IDE | **Kiro** / **Amazon Q Developer** |
| Learn GenAI without code | **PartyRock** |

### Security, compliance & governance
| Need… | Choose |
|---|---|
| Encryption keys | **AWS KMS** |
| Secrets (passwords, API keys) | **AWS Secrets Manager** |
| Sensitive-data discovery (in S3) | **Amazon Macie** |
| API activity logs (who did what) | **AWS CloudTrail** |
| Prompt/response content logs | **Bedrock model invocation logging** (CloudWatch Logs/S3) |
| Performance metrics, logs, alarms | **Amazon CloudWatch** |
| Compliance reports (SOC, ISO) | **AWS Artifact** |
| Vulnerability scanning | **Amazon Inspector** |
| Resource configuration / compliance rules | **AWS Config** |
| Best-practice recommendations | **AWS Trusted Advisor** |
| Audit evidence collection | **AWS Audit Manager** |
| Threat detection | **Amazon GuardDuty** |
| Access control | **AWS IAM** |
| Private connectivity to Bedrock | **AWS PrivateLink (VPC endpoint)** |
| Isolated network | **Amazon VPC** |
| Data catalog | **AWS Glue Data Catalog** / SageMaker Catalog |
| Data lineage | **SageMaker ML Lineage Tracking** |
| Data lake permissions | **AWS Lake Formation** |
| Data retention / lifecycle | **S3 Lifecycle policies** |

---

## 6.7 AWS SERVICES MEMORY MAP (VISUAL)

```
                           ┌────────────── AIF-C01 SERVICE MAP ──────────────┐
                           │                                                 │
  GENAI (Bedrock family)   │  Bedrock ─┬─ Models: Nova (Micro/Lite/Pro/Premier/Canvas/Reel/Sonic), Titan, Claude, Llama…
                           │           ├─ Knowledge Bases (RAG) ── vector store: OpenSearch | Aurora/RDS pgvector | Neptune | S3 Vectors
                           │           ├─ Agents (actions) ── Action groups (Lambda) + KBs + multi-agent
                           │           ├─ AgentCore: Runtime | Memory | Gateway(MCP) | Identity | Policy | Code Interp | Browser | Observability
                           │           ├─ Guardrails (safety) ── content | topics | words | PII | grounding | automated reasoning
                           │           ├─ Model Evaluation | Prompt Management | Flows | Custom models | Distillation
                           │           └─ Pricing: On-demand | Batch | Provisioned Throughput | Prompt caching
                           │  Apps: Amazon Quick / Q Business (employees) | Kiro / Q Developer (developers) | PartyRock (learn)
                           │  SDK: Strands Agents   Protocol: MCP
                           │
  ML PLATFORM (SageMaker)  │  SageMaker AI ─ JumpStart | Canvas | Ground Truth | Data Wrangler | Feature Store | Pipelines
                           │                 Clarify (bias/explain) | Model Monitor (drift) | Model Cards | Model Registry | A2I (human review)
                           │
  AI SERVICES (pre-trained)│  See: Rekognition (images) | Textract (documents)
                           │  Hear/Speak: Transcribe (speech→text) | Polly (text→speech)
                           │  Read/Write: Comprehend (analyze text) | Translate (languages)
                           │  Talk: Lex (chatbots)   Suggest: Personalize   Search: Kendra
                           │
  SECURITY & GOVERNANCE    │  Who: IAM, AgentCore Identity    Keys: KMS    Secrets: Secrets Manager
                           │  Find PII: Macie   Network: VPC, PrivateLink
                           │  Logs: CloudTrail (who) | CloudWatch (health) | Invocation logging (content)
                           │  Compliance: Config (settings) | Artifact (reports) | Audit Manager (evidence)
                           │  Risk: Inspector (vulns) | GuardDuty (threats) | Trusted Advisor (advice)
                           └─────────────────────────────────────────────────┘
```

### Sensory memory trick for AI services
- 👁 **Eyes:** Rekognition (pictures), Textract (paper)
- 👂 **Ears:** Transcribe
- 👄 **Mouth:** Polly
- 🧠 **Brain (language):** Comprehend
- 🌍 **Passport:** Translate
- 💬 **Conversation:** Lex
- 🛒 **Shopping assistant:** Personalize
- 🔎 **Librarian:** Kendra

---

## 6.8 IN-SCOPE vs LOW PRIORITY SUMMARY

**HIGH PRIORITY (study deeply):** Bedrock (all features), Knowledge Bases, Agents, AgentCore, Guardrails, Model Evaluation, Prompt Management, Nova, SageMaker AI (+ Clarify, Model Monitor, Model Cards, JumpStart, Canvas, Ground Truth, A2I), Rekognition, Textract, Transcribe, Polly, Translate, Comprehend, Lex, Personalize, Kendra, OpenSearch, Aurora/RDS pgvector, Neptune, S3, IAM, KMS, Secrets Manager, Macie, CloudTrail, CloudWatch, Config, Inspector, Artifact, Trusted Advisor, PrivateLink/VPC, Quick, Kiro, Strands Agents, Q Developer.

**MEDIUM:** Lambda, EC2 (Trainium/Inferentia), Glue, Lake Formation, Audit Manager, GuardDuty, Bedrock Flows, Data Automation, Connect, PartyRock, DocumentDB, MemoryDB, S3 Vectors.

**LOW PRIORITY / OUT OF SCOPE:** Deep networking (Direct Connect, Transit Gateway), EMR/Kinesis internals, Amazon Forecast, Fraud Detector, Lookout family, DeepRacer/DeepLens/DeepComposer, Panorama, Monitron, HealthLake, coding syntax, hyperparameter math, infrastructure sizing.

**➡ Continue to PART 7 — Top 100 AIF-C01 Exam Traps**
