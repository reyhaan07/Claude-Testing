# PART 11 — AIF-C01 MASTER NOTES

# DETAILED EXPLANATIONS (Q76–Q150)

(The full answer key is at the top of **PART 10**.)

---

## SECTION B — MEDIUM (continued), Q76–Q100

**Q76 — C**
- ✅ **AgentCore Gateway** converts existing APIs and Lambda functions into **MCP-compatible tools** that agents can discover.
- ❌ A: Guardrails is content safety. B: AgentCore Memory stores memory, not tools. D: Lex builds chatbots.
- 🔑 Keyword: "turn… APIs and Lambda functions into tools… MCP".

**Q77 — A**
- ✅ Remembering preferences **across sessions** requires **long-term memory** (AgentCore Memory).
- ❌ B: Polly is speech. C: Max tokens controls output length. D: Temperature controls randomness.
- 🔑 Keyword: "across sessions over many weeks".

**Q78 — B**
- ✅ An **interface VPC endpoint (PrivateLink)** keeps traffic to Bedrock on the AWS network.
- ❌ A: Public IPs use the internet. C: An internet gateway is the internet. D: CloudFront is a CDN, not private service access.
- 🔑 Keyword: "without traffic going over the public internet".

**Q79 — A**
- ✅ **CloudTrail** records which identity called `InvokeModel` and when.
- ❌ B: CloudWatch metrics show counts and latency, not who. C: Trusted Advisor gives recommendations. D: Macie scans S3 data.
- 🔑 Keyword: "which IAM user invoked… last Tuesday".

**Q80 — A**
- ✅ **Model invocation logging** captures full prompt and response **content** to CloudWatch Logs or S3. It must be enabled.
- ❌ B: CloudTrail records the API call, not the full content. C: Config tracks configurations. D: Trusted Advisor gives recommendations.
- 🔑 Keyword: "full text of prompts and responses".

**Q81 — D**
- ✅ Custom (fine-tuned) Bedrock models are typically served with **Provisioned Throughput** (the classic exam answer).
- ❌ A: Prompt caching reduces the cost of repeated input and isn't a hosting option. B: "Batch only" is not the typical requirement. C: SageMaker Serverless is a different service.
- 🔑 Keyword: "fine-tuned… run inference on the custom model".

**Q82 — C**
- ✅ Building your own app on a **pre-trained FM via API** (even with RAG) = **Scope 3**. RAG doesn't change weights.
- ❌ A: Scope 1 = public consumer apps. B: Scope 2 = enterprise SaaS apps. D: Scope 4 requires **fine-tuning**.
- 🔑 Keyword: "calls Claude on Bedrock… does NOT fine-tune".

**Q83 — D**
- ✅ **Clarify** provides feature attributions (e.g., SHAP) that explain predictions.
- ❌ A: A2I is human review. B: Model Cards document the model; they don't explain individual predictions. C: Model Monitor detects drift.
- 🔑 Keyword: "which factors most influenced".

**Q84 — B**
- ✅ **Model Cards** document intended use, risk rating, training details, and evaluation for governance.
- ❌ A: Artifact holds AWS compliance reports. C: Debugger debugs training. D: Feature Store stores features.
- 🔑 Keyword: "document… intended use, risk rating… auditors".

**Q85 — C**
- ✅ **A2I** routes low-confidence predictions (including Textract's) to human reviewers.
- ❌ A: Macie is PII discovery. B: Config is configuration compliance. D: Ground Truth labels **training** data.
- 🔑 Keyword: "humans to review… confidence score is below 80%".

**Q86 — A**
- ✅ Reusing a pre-trained FM and choosing the **smallest adequate model** minimizes energy use.
- ❌ B, C, D: Continuous training, pre-training from scratch, and daily fine-tuning of the largest model all waste compute and energy.
- 🔑 Keyword: "MOST environmentally sustainable".

**Q87 — B, D**
- ✅ Behavior change = **drift**. **Detect it (Model Monitor)** and **retrain on recent data**.
- ❌ A: Artifact is compliance reports. C: A bigger instance doesn't fix accuracy. E: Temperature is a GenAI parameter and doesn't fix drift.
- 🔑 Keyword: "accuracy has dropped because customer behavior changed".

**Q88 — B**
- ✅ **Top-p** = cumulative probability threshold (nucleus sampling).
- ❌ A: Temperature reshapes the probabilities. C: Max tokens sets length. D: Stop sequences end generation.
- 🔑 Keyword: "cumulative probability".

**Q89 — A**
- ✅ A handful of examples, a specific format, lowest cost = **few-shot prompting**.
- ❌ B: Distillation requires training. C: Pre-training is extremely expensive. D: Continued pre-training needs large unlabeled data.
- 🔑 Keyword: "handful of examples… lowest cost and effort".

**Q90 — A**
- ✅ **Conversion rate** = the share of users who buy, which directly measures purchase impact.
- ❌ B: BLEU is a translation metric. C: Token count is a cost measure. D: Perplexity is a language-model quality measure.
- 🔑 Keyword: "increases purchases".

**Q91 — 2 → 4 → 5 → 1 → 3**
- ✅ Chunk documents → create embeddings → store in the vector DB → retrieve similar chunks → generate with the augmented prompt.
- Why: Ingestion (chunk, embed, store) happens before any query. Retrieval comes before generation.
- 🔑 Memory: **C-E-S-R-G** = "Cats Eat Sardines, Rarely Grapes".

**Q92 — C**
- ✅ **Secrets Manager** stores API keys securely and supports rotation. The app retrieves the key at runtime.
- ❌ A: Emailing secrets is insecure. B: A function name is visible and insecure. D: KMS manages **encryption keys**, not third-party API secrets.
- 🔑 Keyword: "hard-coded… API key".

**Q93 — C**
- ✅ **AWS Config** continuously evaluates resource configuration (e.g., the encryption setting) and keeps change history.
- ❌ A: Artifact has AWS compliance reports. B: Inspector finds software vulnerabilities. D: Polly is speech.
- 🔑 Keyword: "encryption enabled… track configuration changes".

**Q94 — A**
- ✅ **Trusted Advisor** gives best-practice checks across cost, security, performance, and limits.
- ❌ B: Secrets Manager stores secrets. C: CloudTrail is an API log. D: Macie finds PII.
- 🔑 Keyword: "recommendations across cost… security… service limits".

**Q95 — C**
- ✅ A smaller model that mimics a larger one for a task = **distillation**.
- ❌ A: Temperature doesn't change speed or cost much. B: Continued pre-training adds domain knowledge; it doesn't shrink the model. D: Zero-shot doesn't make a model smaller.
- 🔑 Keyword: "smaller model with nearly the same accuracy".

**Q96 — C**
- ✅ Human rankings → reward model → RL optimization = **RLHF**.
- ❌ A: Few-shot is prompting. B: Clustering is unsupervised. D: Transfer learning reuses a model for a new task.
- 🔑 Keyword: "rank… reward model".

**Q97 — A, D**
- ✅ Bedrock supports **PrivateLink** and **encrypts data in transit and at rest**.
- ❌ B: Bedrock is serverless, so there are no EC2 instances to manage. C: It offers many providers' models. E: Prompts are **not** used to train base models.
- 🔑 Keyword: "true about Amazon Bedrock".

**Q98 — D**
- ✅ Context engineering = managing **what information fills the context window** (retrieved docs, memory, tools, history).
- ❌ A: It isn't encryption. B: It isn't Region selection. C: Changing weights is fine-tuning.
- 🔑 Keyword: "what information goes into… context window".

**Q99 — 1-b, 2-c, 3-d, 4-a**
- ✅ Real-time = card-swipe fraud check (instant). Serverless = rarely used internal tool. Async = 500 MB video with notification. Batch = nightly 10M records.
- 🔑 Memory: Real-time = Right now. Serverless = Sometimes. Async = Await. Batch = Bulk.

**Q100 — B**
- ✅ **Bedrock Prompt Management** = create, version, test, and share prompts, and roll back.
- ❌ A: Guardrails is safety. C: Model Monitor detects drift. D: Config handles resource configuration.
- 🔑 Keyword: "standardize, version… prompts".

---

## SECTION C — DIFFICULT SCENARIOS, Q101–Q150

**Q101 — B**
- ✅ Private PDFs in S3, weekly updates, citations, least overhead = **Bedrock Knowledge Bases** (S3 data source, sync, RetrieveAndGenerate with citations).
- ❌ A: Weekly fine-tuning is costly and gives no citations. C: Comprehend classification doesn't answer questions. D: Training an LLM from scratch is the most expensive option.
- 🔑 Keywords: "PDF documents… updated weekly… cite… LEAST operational overhead".

**Q102 — A**
- ✅ It needs both **knowledge** (policy docs → KB) and **action** (create labels → action group with Lambda). A **Bedrock agent with a KB and an action group** covers both with minimal code.
- ❌ B: Lex + Polly offers no document grounding or GenAI answers here. C: A KB alone can't take actions. D: A model without tools can't call the shipping system.
- 🔑 Keyword: "answer… AND create return shipping labels".

**Q103 — A**
- ✅ **AgentCore** runs agents from **any framework** with Runtime (session isolation), Memory, Identity, Gateway, and Observability, all serverless.
- ❌ B: Knowledge Bases provide RAG, not agent hosting. C: Canvas is no-code ML. D: EC2 means managing servers.
- 🔑 Keyword: "open-source framework… production… without managing servers".

**Q104 — C**
- ✅ **Policy in AgentCore** evaluates **deterministic Cedar rules on every tool call** outside the model, so prompt injection can't bypass it.
- ❌ A: Temperature is irrelevant. B: System-prompt instructions **can be overridden** by injection. D: A word filter on "$500" doesn't enforce an amount limit on actions.
- 🔑 Keywords: "NEVER… even if… prompt injection" → deterministic control outside the model.

**Q105 — C**
- ✅ **AgentCore Identity** manages OAuth tokens and API keys so agents can act **on behalf of users** without hard-coded credentials.
- ❌ A: Macie is PII discovery. B: Artifact is compliance reports. D: Prompt Management handles prompts.
- 🔑 Keyword: "on that user's behalf using OAuth".

**Q106 — C**
- ✅ Large volume + not time-sensitive + minimize cost = **Bedrock batch inference** (about 50% cheaper).
- ❌ A: More max tokens adds cost. B: On-demand real-time costs more per token. D: Provisioned Throughput is for guaranteed real-time capacity and costs more when utilization is bursty.
- 🔑 Keyword: "not time-sensitive… cost must be minimized".

**Q107 — A, E**
- ✅ 400 pages in one request needs a **large context window**. Consistency needs a **low temperature**.
- ❌ B: A 4K context can't fit 400 pages. C: High temperature causes variability. D: Negative prompts don't solve length or consistency.
- 🔑 Keywords: "400-page… single request" + "consistent".

**Q108 — B, D**
- ✅ **Sensitive information filters** mask or block patient identifiers. **Denied topics** block diagnoses.
- ❌ A: A single-word filter is easy to bypass and doesn't capture the topic. C: Image filters aren't relevant. E: A grounding check targets hallucinations, not these requirements.
- 🔑 Keywords: "never reveal patient identifiers" (PII) + "refuse… diagnoses" (topic).

**Q109 — A**
- ✅ Brand voice and friendliness are **subjective**, so use **human evaluation** in Bedrock Model Evaluation.
- ❌ B: Public benchmarks don't measure your brand voice. C, D: ROUGE and BLEU measure word overlap, not tone.
- 🔑 Keyword: "brand voice and friendliness".

**Q110 — C**
- ✅ **LLM-as-a-judge** scales human-like quality scoring to large volumes.
- ❌ A: BLEU is a translation overlap metric. B: Five samples isn't representative. D: Temperature isn't an evaluation method.
- 🔑 Keywords: "50,000… human review too slow and expensive".

**Q111 — A**
- ✅ Regulators need explanations. An **interpretable tree model + Clarify feature attributions** meets that, even with slightly lower accuracy.
- ❌ B: Clustering doesn't make loan decisions. C: A black box without explanations fails the requirement. D: LLM decisions are hard to explain and nondeterministic.
- 🔑 Keyword: "clearly explain every loan decision" → interpretability/explainability tradeoff.

**Q112 — D**
- ✅ Worse performance for one group = **non-representative training data (bias)**. Fix it with **diverse data** and measure with **Clarify**.
- ❌ A: Overfitting isn't group-specific. B: Encryption doesn't affect accuracy. C: Temperature isn't a vision-model concept here.
- 🔑 Keyword: "performs worse for people with darker skin tones".

**Q113 — D, E**
- ✅ Private subnets without internet → **PrivateLink interface endpoint**. Company-controlled keys → **KMS customer managed key**.
- ❌ A: Secrets Manager isn't for storing datasets. B, C: A NAT gateway or public endpoint uses internet paths.
- 🔑 Keywords: "no internet gateway" + "keys that the company controls".

**Q114 — D**
- ✅ **Macie** scans S3 for sensitive data such as credit card numbers.
- ❌ A: Trusted Advisor gives recommendations. B: Polly is speech. C: Inspector scans software vulnerabilities, not data.
- 🔑 Keyword: "S3 documents… no credit card numbers".

**Q115 — A**
- ✅ AWS SOC 2 report → **Artifact**. Who changed the guardrail → **CloudTrail**.
- ❌ B: Inspector and Macie cover vulnerabilities and PII. C: Config shows configuration state, and CloudWatch has no SOC reports. D: Trusted Advisor gives recommendations, and Audit Manager covers your own evidence, not AWS's SOC report.
- 🔑 Keywords: "SOC 2… AWS data centers" + "who changed".

**Q116 — 3 → 6 → 2 → 7 → 5 → 1 → 4**
- ✅ Data selection → Model selection → Pre-training → Fine-tuning → Evaluation → Deployment → Feedback.
- 🔑 Memory: "**D**on't **M**ake **P**izza **F**or **E**veryone **D**uring **F**asting".

**Q117 — C**
- ✅ Fine-tuning with your data = **Scope 4**. You must secure the **training data** and **access to the custom model** (on top of Scope 3 duties).
- ❌ A: Scope 5 = training from scratch, and data centers are never the customer's job. B: Scope 1 = consumer apps. D: Scope 2 = enterprise SaaS.
- 🔑 Keyword: "fine-tunes… with proprietary customer data".

**Q118 — C**
- ✅ Too much irrelevant context hurts quality and raises cost. **Context engineering** (summarize or trim history, include relevant context only) fixes both.
- ❌ A: Temperature doesn't address context overload. B: Fine-tuning on chat history is costly and doesn't address per-request context. D: A bigger window keeps the cost and the noise.
- 🔑 Keywords: "entire 200-message chat history… quality dropped… cost increased".

**Q119 — D**
- ✅ Specialist agents coordinated by a delegating agent = **multi-agent system with a supervisor**.
- ❌ A: Continued pre-training is model training. B: Batch inference is offline processing. C: A single prompt can't orchestrate specialists.
- 🔑 Keyword: "coordinating agent… delegate to the specialists".

**Q120 — B**
- ✅ **Kiro** = agentic IDE with **spec-driven development** (requirements → design → tasks → code).
- ❌ A: Polly is speech. C: Canvas is no-code ML. D: Artifact is compliance.
- 🔑 Keyword: "AI-powered IDE… specifications… before it generates code".

**Q121 — C**
- ✅ **Amazon Quick** = ready-made agentic workspace for employees: chat across company data, research, dashboards, and automations, with nothing to build.
- ❌ A: Lex is for building chatbots. B: JumpStart is for deploying ML models. D: AgentCore is infrastructure for **building** agents.
- 🔑 Keyword: "without the company building a custom application".

**Q122 — A, D**
- ✅ **Temperature near 0** + **standardized prompt templates** give the most consistent outputs.
- ❌ B, C: Higher top-p or temperature increases variability. E: Removing the system prompt reduces control.
- 🔑 Keyword: "different answers to identical… questions".

**Q123 — B**
- ✅ **JumpStart** deploys open-source models to **your SageMaker endpoints** on instances you choose, with full control.
- ❌ A: Bedrock is serverless, so you don't choose instances. C: PartyRock is a learning playground. D: Comprehend is text analytics.
- 🔑 Keyword: "own AWS account… GPU instance types it chooses… full control".

**Q124 — B, C**
- ✅ Malicious instructions hidden in content the agent reads = **indirect prompt injection**. **Least-privilege tools and deterministic tool-call policies** (AgentCore Identity/Policy) limit the damage.
- ❌ A: BLEU is a translation metric. D: Max tokens is irrelevant. E: Nothing is training on the page, so it's not poisoning.
- 🔑 Keyword: "web page… hidden text… instructs".

**Q125 — B, E**
- ✅ Loosely related long passages → **tune chunking** (size/strategy) and **add reranking**.
- ❌ A: Changing the metric doesn't improve answers. C: Higher temperature adds randomness. D: Removing the vector store breaks RAG.
- 🔑 Keywords: "long passages… loosely related".

**Q126 — A**
- ✅ **S3 Vectors** = lowest-cost, massive-scale vector storage for infrequent queries.
- ❌ B: MemoryDB is fastest but expensive (in-memory). C: A large provisioned OpenSearch cluster is costly when idle. D: DynamoDB isn't a vector store answer.
- 🔑 Keywords: "LOWEST-cost… billions… infrequently".

**Q127 — B**
- ✅ **OpenSearch Service** = scalable low-latency vector + keyword (hybrid) search, and the default choice for Knowledge Bases.
- ❌ A: Glacier is archival storage. C: Neptune is for graph relationships. D: RDS for MySQL isn't a vector option here.
- 🔑 Keyword: "hybrid search".

**Q128 — 1-c, 2-b, 3-a, 4-d**
- ✅ Injection → validate inputs, use delimiters, limit tools. PII leakage → Guardrails PII filters. Poisoning → validate source provenance and restrict write access. Jailbreak → Guardrails prompt-attack and content filters.
- 🔑 Memory: Injection = input; Leakage = PII filter; Poisoning = protect the well; Jailbreak = prompt-attack filter.

**Q129 — D**
- ✅ Data residency → **deploy in EU Regions** and avoid routing (e.g., cross-region inference) outside the EU.
- ❌ A: Artifact doesn't move data. B: Max tokens is irrelevant. C: Encryption doesn't satisfy residency laws.
- 🔑 Keyword: "keep customer data within the EU".

**Q130 — B, E**
- ✅ Auto-delete after 2 years → **S3 Lifecycle policies** (retention). Trace data to model version → **SageMaker ML Lineage Tracking**.
- ❌ A: Rekognition analyzes images. C: Trusted Advisor gives recommendations. D: Polly is speech.
- 🔑 Keywords: "deleted automatically" + "trace which data trained each model".

**Q131 — D**
- ✅ Mathematically verifiable consistency with policy rules = **Automated Reasoning checks** (Guardrails).
- ❌ A: Word filters block words. B: Translate handles languages. C: Top-k controls sampling.
- 🔑 Keyword: "mathematically verifiable… policy rules".

**Q132 — B, E**
- ✅ **User satisfaction** and **productivity** measure business value.
- ❌ A, C, D: BLEU, perplexity, and ROUGE-L are technical model metrics.
- 🔑 Keyword: "business value".

**Q133 — A**
- ✅ Simple, high-volume tasks rarely need the biggest model. **Evaluate smaller models** and use the smallest one that meets the quality bar.
- ❌ B: More max tokens raises cost. C: Chain-of-thought adds output tokens and cost. D: Provisioned Throughput for the largest model doesn't reduce per-task cost.
- 🔑 Keywords: "largest model… simple… costs too high".

**Q134 — A**
- ✅ The **ApplyGuardrail API** evaluates text against a guardrail for **any model**, including ones outside Bedrock.
- ❌ B: Config rules check AWS resource configuration. C: Inspector scans vulnerabilities. D: Guardrails **can** be used outside Bedrock via ApplyGuardrail.
- 🔑 Keyword: "model hosted on… SageMaker AI endpoint".

**Q135 — A, C**
- ✅ Images → **Rekognition content moderation**. Text → **Comprehend toxicity detection**.
- ❌ B: Personalize makes recommendations. D: Polly is speech. E: Textract extracts document text.
- 🔑 Keywords: "moderate… images" + "toxic language in text".

**Q136 — B, C, E**
- ✅ **Transcribe** (speech → text with PII redaction), **Bedrock** (summaries), **Comprehend** (sentiment).
- ❌ A: Rekognition is images and video. D: Polly is text → speech.
- 🔑 Keywords: "call recordings to text… summaries… sentiment".

**Q137 — A, D**
- ✅ **Pipelines** automate reproducible workflows. **Model Registry** provides versioning and an **approval step** before deployment.
- ❌ B: Canvas is no-code ML for analysts. C: Polly is speech. E: Artifact is compliance reports.
- 🔑 Keywords: "automated, reproducible workflow… approval step".

**Q138 — A, E**
- ✅ The customer configures **IAM access** and **guardrails** (security **in** the cloud).
- ❌ B, C, D: Data center security, the virtualization layer, and patching the hosting servers are **AWS** responsibilities.
- 🔑 Keyword: "customer responsibilities… Bedrock".

**Q139 — B**
- ✅ Resemblance to copyrighted work = **IP risk**. Mitigate with **human review** and **IP-indemnified models/providers**.
- ❌ A: This isn't a latency issue. C: Hallucination is false facts, not copying. D: Residency is about data location.
- 🔑 Keyword: "resemble copyrighted artworks".

**Q140 — B**
- ✅ Long-term revenue from customers staying longer = **Customer lifetime value (CLV)**.
- ❌ A: BLEU is a translation metric. C: Latency is technical. D: Tokens per response is a cost measure.
- 🔑 Keyword: "long-term revenue… staying… longer".

**Q141 — C**
- ✅ No ML team + quick + least overhead = **Bedrock** (serverless FM API).
- ❌ A, D: EC2 or SageMaker training need ML skills and ops work. B: Pre-training is the most expensive option.
- 🔑 Keywords: "no ML team… quickly… LEAST operational overhead".

**Q142 — C**
- ✅ Per-department document access → **metadata filtering + access controls** on retrieval (prevents data leakage).
- ❌ A: Temperature is irrelevant. B: A larger context window doesn't restrict access. D: Polly is speech.
- 🔑 Keyword: "only the documents it is authorized to see".

**Q143 — B**
- ✅ **AgentCore Observability** traces each step and tool call (latency, errors) through CloudWatch.
- ❌ A: Artifact is compliance. C: Macie finds PII. D: Translate handles languages.
- 🔑 Keyword: "trace each reasoning step and each tool call's latency".

**Q144 — A**
- ✅ Guardrails = **what content** goes in and out. IAM = **who** can access **which resources and actions**.
- ❌ B: Neither only logs API calls (that's CloudTrail). C, D: These swap or invent responsibilities.
- 🔑 Memory: Guardrails = WHAT is said. IAM = WHO can do it.

**Q145 — 4 → 2 → 5 → 3 → 1**
- ✅ Curate and label examples → upload JSONL to S3 → run the fine-tuning job → purchase Provisioned Throughput → invoke from the app.
- Why: Data must exist before the job. The custom model must be hosted (Provisioned Throughput) before the app can call it.

**Q146 — A, B, D**
- ✅ **Lower temperature**, **grounding check**, and "**answer only from the context / say I don't know**" instructions all reduce hallucinations.
- ❌ C: Removing citations reduces transparency and verification. E: Higher temperature increases hallucination risk.
- 🔑 Keyword: "reduce hallucinations… RAG".

**Q147 — A**
- ✅ **Nova Sonic** = real-time **speech-to-speech** conversational FM.
- ❌ B: Polly only converts text → speech and doesn't understand speech. C: Textract handles documents. D: Nova Reel generates video.
- 🔑 Keyword: "speech in, speech out… real-time".

**Q148 — 1-b, 2-c, 3-d, 4-a**
- ✅ Inspector = CVE scanning of Lambda. Config = non-compliant encryption rule. Trusted Advisor = delete idle resources to save cost. GuardDuty = compromised credentials and malicious activity.
- 🔑 Memory: Inspector = cracks, Config = settings, Trusted Advisor = consultant, GuardDuty = guard dog.

**Q149 — D**
- ✅ Whether an agent "does its job" = **task completion (goal success) rate**.
- ❌ A: Input tokens is a cost measure. B: Parameter count is model size. C: BLEU is a translation metric.
- 🔑 Keyword: "agent… does its job".

**Q150 — C, D, E**
- ✅ Product manuals → **Knowledge Bases** (RAG). Block competitor names → **Guardrails word filters**. Who changed configuration → **CloudTrail**.
- ❌ A: Macie finds PII in S3, which isn't asked for. B: Polly is speech.
- 🔑 Keywords: "product manuals" + "competitor product names" + "who changed".

---

## HOW TO USE YOUR RESULTS

| Score | What to do |
|---|---|
| **135–150** | You're ready. Revise Part 8 (cheat sheet) only. |
| **120–134** | Re-read the explanations for your wrong answers + Part 7 traps. |
| **105–119** | Re-study Parts 3 (Domain 3) and 5 (Domain 5), then retake Section C. |
| **< 105** | Re-study Parts 2, 3, 4, 5 fully; redo all 150 after 24 hours. |

**Mistakes by topic → where to review:**
- Inference types, metrics, ML basics → Part 1
- Tokens, embeddings, agents, MCP, pricing → Part 2
- RAG, customization, prompting, attacks, evaluation → Part 3
- Guardrails, bias, explainability → Part 4
- IAM, KMS, logging, compliance, scoping matrix → Part 5
- "Which service?" confusion → Part 6

**🎯 Good luck on September 30, 2026. You've got this.**
