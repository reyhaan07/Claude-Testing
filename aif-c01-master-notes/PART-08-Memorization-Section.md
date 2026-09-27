# PART 8 — AIF-C01 MASTER NOTES

# MEMORIZATION SECTION

---

## 8.1 ONE-PAGE AIF-C01 CHEAT SHEET

**EXAM:** 65 Qs (50 scored) · 90 min · pass 700/1000 · no guessing penalty · D1 20% · D2 24% · **D3 28%** · D4 14% · D5 14%

**HIERARCHY:** AI ⊃ ML ⊃ Deep Learning (neural nets) ⊃ GenAI (FMs → LLMs, diffusion) → Agentic AI (FM + tools + memory + planning → **acts**)

**LEARNING:** Supervised = labels (classification = category, regression = number) · Unsupervised = no labels (clustering, anomaly) · RL = rewards · Self-supervised = how FMs pre-train

**INFERENCE:** Real-time (now, steady) · Serverless (intermittent, cold start) · Async (large ≤1 GB / long ≤1 h, queue) · Batch (whole dataset, cheapest)

**FIT:** Overfit = train ✅ test ❌ (more data, simplify, regularize) · Underfit = both ❌ (more features, complex model)

**METRICS:** Precision = avoid false alarms · Recall = avoid misses · F1 = balance (imbalanced) · Accuracy misleading on imbalance · MAE/RMSE = regression · **ROUGE = summaries · BLEU = translation · BERTScore = meaning**

**LIFECYCLE:** Business goal → Collect → Prepare → Features → Train → Tune → Evaluate → Deploy → Monitor → Retrain · **FM:** Data sel. → Model sel. → Pre-train → Fine-tune → Evaluate → Deploy → Feedback

**GENAI BLOCKS:** Token = text piece (billing) · Embedding = meaning as numbers · Vector = number list · Chunking = split docs · Context window = max tokens per request · Transformer = attention · Diffusion = image from noise

**PARAMETERS:** Temperature ↓ = consistent, ↑ = creative · Top-p/Top-k = word-choice range · Max tokens = output length · Prompt caching = reuse identical prefix → cheaper/faster

**CUSTOMIZATION LADDER (cheap→expensive):** Prompt/few-shot → RAG → Fine-tune (labeled) → Continued pre-train (unlabeled) → Pre-train · Distillation = teacher→student (cheaper/faster) · **Weights change only when "training" happens** (not prompt, not RAG)

**RAG:** Docs(S3) → chunk → embed → vector DB → query embed → retrieve → augment → generate (citations) · **Bedrock Knowledge Bases** · Vector stores: **OpenSearch** (default/hybrid), **Aurora/RDS PostgreSQL pgvector**, **Neptune** (graph), S3 Vectors (cheap), MemoryDB (fast)

**PROMPTING:** Zero/one/few-shot · CoT = step by step · Negative prompt = what NOT to include · Templates + **Prompt Management** (versioning) · Specific, concise, clear, iterate

**ATTACKS:** Injection = override instructions · Hijacking = redirect goal · Jailbreak = bypass safety · Poisoning = bad data · Leakage = secrets exposed → **Guardrails** + least privilege + validation

**AGENTS:** Brain (FM) + Tools + Memory + Instructions · ReAct loop · Multi-agent = supervisor + specialists · **MCP = USB-C for AI tools** · **Bedrock Agents** (managed) · **AgentCore** (Runtime, Memory, Gateway→MCP, Identity, Policy, Code Interpreter, Browser, Observability) · **Strands** (SDK) · **Kiro** (AI IDE) · **Quick** (employee assistant)

**LIMITATIONS:** Hallucination (RAG + grounding check) · Nondeterminism (↓ temperature) · Interpretability (simple models) · Knowledge cutoff (RAG) · Bias · Toxicity · Cost/latency

**PRICING:** On-demand (per input/output token; output costs more) · Batch (~50% off) · Provisioned Throughput (custom models / guaranteed) · Prompt caching · Smaller model = cheaper/faster

**RESPONSIBLE AI:** Fairness · Explainability · Privacy/security · Safety · Controllability · Veracity/robustness · Governance · Transparency · Tools: **Guardrails, Clarify (bias/explain), Model Monitor (drift), A2I (human review), Model Cards, AI Service Cards**

**GUARDRAILS:** Content filters (+prompt attack) · Denied topics · Word filters · PII filters (block/mask) · Contextual grounding · Automated Reasoning · inputs AND outputs · any model (ApplyGuardrail)

**SECURITY:** Shared responsibility (AWS = OF cloud; you = IN cloud) · IAM (who/what; roles; least privilege) · KMS (keys) · Secrets Manager (passwords) · Macie (PII in S3) · PrivateLink (no internet) · CloudTrail (who did what) · CloudWatch (metrics/logs) · Config (config compliance) · Inspector (vulns) · Artifact (reports) · Trusted Advisor (advice) · AgentCore Identity (agent creds) · Policy in AgentCore (tool-call rules)

**SCOPING MATRIX:** 1 Consumer app · 2 Enterprise app · 3 Pre-trained model (Bedrock API) · 4 Fine-tuned · 5 Self-trained

**DATA GOVERNANCE:** Lineage (history) · Catalog (inventory) · Quality · Integrity · Access control · Lifecycle/Retention (S3 Lifecycle) · Residency (Region)

**AI SERVICES:** Rekognition (images) · Textract (docs) · Transcribe (speech→text) · Polly (text→speech) · Translate · Comprehend (text analytics) · Lex (chatbots) · Personalize (recs) · Kendra (search)

---

## 8.2 AWS SERVICES MEMORY MAP (COMPACT)

| Category | Service → one-word job |
|---|---|
| **GenAI core** | Bedrock → models · Knowledge Bases → RAG · Agents → actions · AgentCore → agent-ops · Guardrails → safety · Model Evaluation → compare · Prompt Management → versions · Flows → workflows · Nova → Amazon FMs · Titan Embeddings → vectors |
| **Agent tools** | Strands → SDK · Kiro → IDE · MCP → protocol · AgentCore Gateway → MCP tools · AgentCore Identity → credentials · Policy → tool rules · AgentCore Memory → remember · Observability → trace |
| **Apps** | Quick / Q Business → employee assistant · Q Developer → coding · PartyRock → learn |
| **ML platform** | SageMaker → build/train/deploy · JumpStart → pre-trained · Canvas → no-code · Ground Truth → labels · Clarify → bias/explain · Model Monitor → drift · Model Cards → docs · Registry → versions · Pipelines → MLOps · A2I → human review |
| **AI services** | Rekognition → see · Textract → read docs · Transcribe → hear · Polly → speak · Translate → languages · Comprehend → understand text · Lex → converse · Personalize → recommend · Kendra → search |
| **Data** | S3 → store · OpenSearch → vector search · Aurora/RDS → SQL + pgvector · Neptune → graph · Glue → ETL/catalog · Lake Formation → data permissions |
| **Compute** | EC2 → servers · Lambda → functions · Trainium → train · Inferentia → infer |
| **Security** | IAM → access · KMS → keys · Secrets Manager → secrets · Macie → PII in S3 · VPC → private network · PrivateLink → private tunnel |
| **Audit/Compliance** | CloudTrail → who did what · CloudWatch → health · Config → settings compliance · Inspector → vulnerabilities · Artifact → reports · Trusted Advisor → advice · Audit Manager → evidence · GuardDuty → threats |

---

## 8.3 ALL IMPORTANT DEFINITIONS (GLOSSARY A–Z)

| Term | Definition (simple) |
|---|---|
| **A2A (Agent-to-Agent)** | Protocol for agents to communicate with other agents |
| **Accuracy** | % of all predictions that are correct |
| **Agent (AI agent)** | FM-powered system that plans and takes actions using tools and memory |
| **Agentic AI** | AI that autonomously pursues goals via multi-step reasoning and actions |
| **AgentCore** | AWS platform to deploy/operate agents securely at scale |
| **Algorithm** | The learning procedure/recipe |
| **Anomaly detection** | Finding unusual data points |
| **Asynchronous inference** | Queued inference for large/long requests |
| **AUC-ROC** | How well a classifier separates classes (0.5 random, 1 perfect) |
| **Automated Reasoning checks** | Guardrails feature that logically verifies responses against policies |
| **Batch inference** | Offline predictions on a whole dataset |
| **Benchmark dataset** | Standard dataset for comparing models |
| **BERTScore** | Semantic similarity metric using embeddings |
| **Bias (ethical)** | Unfair outcomes across groups |
| **Bias (statistical)** | Error from overly simple model → underfitting |
| **BLEU** | Translation metric (n-gram precision) |
| **Chain-of-thought** | Prompting the model to reason step by step |
| **Chunking** | Splitting documents into pieces for RAG |
| **Classification** | Predicting a category |
| **Clustering** | Grouping unlabeled data by similarity |
| **Computer vision** | AI for images/video |
| **Concept drift** | Relationship between inputs and outputs changes over time |
| **Confidence score** | How sure the model is about an output |
| **Confusion matrix** | Table of TP, FP, FN, TN |
| **Context engineering** | Curating what information fills the context window |
| **Context window** | Max tokens a model can process per request |
| **Contextual grounding check** | Guardrails check that responses are grounded & relevant to source |
| **Continued pre-training** | Further training an FM on unlabeled domain data |
| **Data drift** | Input data distribution changes after deployment |
| **Data lineage** | History of data's origin and transformations |
| **Data residency** | Where (geographically) data is stored |
| **Data retention** | How long data is kept |
| **Deep learning** | ML with many-layered neural networks |
| **Diffusion model** | Generates images by denoising noise |
| **Distillation** | Training a small student model from a large teacher's outputs |
| **Domain adaptation** | Adapting a model to a specific field |
| **Embedding** | Numeric vector that captures meaning |
| **Epoch** | One full pass through training data |
| **Explainability** | Explaining why a specific output was produced |
| **F1 score** | Harmonic mean of precision and recall |
| **Fairness** | Equitable outcomes across groups |
| **Feature** | Input variable used by a model |
| **Feature engineering** | Creating/transforming features |
| **Few-shot** | Several examples in the prompt |
| **Fine-tuning** | Further training an FM on labeled task data (weights change) |
| **Foundation model** | Large pre-trained general-purpose model |
| **Generative AI** | AI that creates new content |
| **Grounding** | Anchoring outputs in trusted source data |
| **Guardrails** | Configurable safety filters for GenAI inputs/outputs |
| **Hallucination** | Confident but false/made-up output |
| **Human-in-the-loop** | Humans review/approve AI outputs |
| **Hyperparameter** | Setting chosen before training |
| **In-context learning** | Model adapts from examples in the prompt |
| **Inference** | Using a trained model on new data |
| **Instruction tuning** | Fine-tuning on instruction-response pairs |
| **Interpretability** | How understandable a model's internals are |
| **Jailbreaking** | Tricking a model into bypassing safety rules |
| **Knowledge base** | Managed store of documents for RAG |
| **Knowledge cutoff** | Date after which the model has no knowledge |
| **Label** | The correct answer attached to training data |
| **Latency** | Time taken to get a response |
| **Least privilege** | Grant only minimum required permissions |
| **LLM** | Large language model (text FM) |
| **LLM-as-a-judge** | Using an LLM to evaluate another model's outputs |
| **Max tokens** | Limit on output length |
| **MCP** | Open protocol to connect AI agents to tools/data |
| **MLOps** | Practices to automate/manage the ML lifecycle |
| **Model** | Trained artifact that makes predictions |
| **Multi-agent system** | Several specialized agents collaborating |
| **Multimodal** | Handles multiple data types (text, image, audio, video) |
| **Negative prompt** | Tells the model what not to include |
| **Neural network** | Layers of connected nodes with weights |
| **NLP** | AI for human language |
| **Nondeterminism** | Different outputs for the same input |
| **One-shot** | One example in the prompt |
| **Overfitting** | Good on training data, poor on new data |
| **Parameters (weights)** | Values learned during training |
| **Poisoning** | Corrupting training/knowledge data maliciously |
| **Precision** | TP / (TP + FP): correctness of positive predictions |
| **Pre-training** | Initial large-scale self-supervised training of an FM |
| **Prompt** | Input given to an FM |
| **Prompt caching** | Reusing processed identical prompt prefixes |
| **Prompt engineering** | Designing prompts for better outputs |
| **Prompt hijacking** | Redirecting a model to an attacker's task |
| **Prompt injection** | Malicious input overriding instructions |
| **Prompt template** | Reusable prompt with variables |
| **Provisioned Throughput** | Reserved Bedrock capacity (needed for custom models) |
| **RAG** | Retrieve relevant data and add it to the prompt |
| **Real-time inference** | Low-latency, always-on endpoint predictions |
| **Recall** | TP / (TP + FN): share of actual positives found |
| **Regression** | Predicting a number |
| **Reinforcement learning** | Learning via rewards/penalties |
| **Reranking** | Re-ordering retrieved results by relevance |
| **Reproducibility** | Ability to recreate results |
| **RLHF** | Aligning models using human preference feedback + RL |
| **Robustness** | Reliable under unexpected/adversarial inputs |
| **ROI** | (Gain − Cost) / Cost |
| **ROUGE** | Summarization metric (recall-oriented overlap) |
| **Semantic search** | Search by meaning using embeddings |
| **Serverless inference** | Scales to zero; pay per use; cold starts |
| **Shared responsibility** | AWS secures the cloud; customer secures in the cloud |
| **Structured data** | Rows/columns with fixed schema |
| **Supervised learning** | Learning from labeled data |
| **Technical debt** | Future cost of shortcuts |
| **Temperature** | Controls randomness/creativity |
| **Token** | Unit of text processed/billed by an FM |
| **Tokenization** | Splitting text into tokens |
| **Tool use** | Model requests external functions/APIs |
| **Top-k** | Sample only from the k most likely tokens |
| **Top-p** | Sample from tokens within cumulative probability p |
| **Toxicity** | Harmful/offensive content |
| **Transfer learning** | Reusing a pre-trained model for a new task |
| **Transformer** | Attention-based architecture behind LLMs |
| **Transparency** | Openness about how AI works and its limits |
| **Underfitting** | Poor on both training and test data |
| **Unstructured data** | Text, images, audio, video without fixed schema |
| **Unsupervised learning** | Finding patterns in unlabeled data |
| **Vector** | A list of numbers |
| **Vector database** | Stores vectors and performs similarity search |
| **Veracity** | Truthfulness/accuracy of outputs |
| **Zero-shot** | No examples in the prompt |

---

## 8.4 ALL IMPORTANT COMPARISONS (INDEX)

| Comparison | Where |
|---|---|
| AI vs ML vs DL vs NN vs GenAI vs Agentic AI | Part 1 §1.12 |
| Supervised vs Unsupervised vs RL | Part 1 §1.3 |
| Classification vs Regression vs Clustering | Part 1 §1.4 |
| Training vs Inference | Part 1 §1.1 |
| Real-time vs Serverless vs Async vs Batch | Part 1 §1.2 |
| Overfitting vs Underfitting | Part 1 §1.6 |
| Precision vs Recall | Part 1 §1.7 |
| Traditional ML vs FMs | Part 1 §1.9, Part 2 §2.9 |
| LLM vs Foundation Model | Part 2 §2.1 |
| Tokens vs Embeddings vs Vectors vs Chunking | Part 2 §2.1 |
| Generative vs Predictive AI | Part 2 §2.9 |
| Temperature vs Top-p vs Top-k vs Max tokens | Part 3 §3.2 |
| RAG vs Fine-tuning vs ICL vs Pre-training vs Distillation | Part 3 §3.5 |
| Vector store options | Part 3 §3.4.3 |
| Prompt injection vs Jailbreaking | Part 3 §3.7 |
| ROUGE vs BLEU vs BERTScore | Part 3 §3.9 |
| Transparency vs Explainability vs Interpretability | Part 4 §4.4 |
| Guardrails vs IAM | Part 4 §4.3 |
| Hallucination vs Bias vs Toxicity | Part 4 §4.5 |
| IAM vs KMS vs Secrets Manager vs Macie vs CloudTrail vs Config vs Inspector vs Artifact vs Trusted Advisor | Part 5 §5.4 |
| AuthN vs AuthZ | Part 5 §5.1 |
| Scoping Matrix scopes 1–5 | Part 5 §5.6 |
| 100 confusing pairs | Part 7 |

---

## 8.5 ALL IMPORTANT EXAM KEYWORDS → ANSWER

| Keyword in question | Answer |
|---|---|
| "labeled data / historical outcomes" | Supervised learning |
| "no labels / segments / group" | Clustering (unsupervised) |
| "reward / penalty / trial and error" | Reinforcement learning |
| "category / yes-no" | Classification |
| "numeric value / price / amount" | Regression |
| "good on training, bad on new data" | Overfitting |
| "bad on both" | Underfitting |
| "must not miss positives" | Recall |
| "false alarms costly" | Precision |
| "imbalanced dataset" | F1 score |
| "immediate / low latency" | Real-time inference |
| "intermittent / idle / unpredictable" | Serverless inference |
| "large payload / long processing" | Asynchronous inference |
| "entire dataset / nightly / not urgent" | Batch inference |
| "drift / degraded over time" | SageMaker Model Monitor → retrain |
| "no ML expertise / no code" | SageMaker Canvas (or AI services) |
| "automate ML workflow / CI/CD" | SageMaker Pipelines |
| "label training data" | SageMaker Ground Truth |
| "human review of low confidence" | Amazon A2I |
| "bias detection / explain prediction" | SageMaker Clarify |
| "document model for governance" | SageMaker Model Cards |
| "foundation models via API / serverless" | Amazon Bedrock |
| "open-source model in own SageMaker endpoint" | SageMaker JumpStart |
| "company documents / private data / citations" | RAG → Bedrock Knowledge Bases |
| "frequently changing data" | RAG |
| "brand voice / style / format" | Fine-tuning |
| "unlabeled domain data" | Continued pre-training |
| "no training / examples in prompt" | Few-shot / in-context learning |
| "step by step / complex reasoning" | Chain-of-thought |
| "what NOT to include" | Negative prompt |
| "version/reuse prompts" | Bedrock Prompt Management |
| "same long context in every request" | Prompt caching |
| "smaller, cheaper, similar accuracy" | Distillation |
| "human preferences / rankings" | RLHF |
| "creative / varied" | Higher temperature |
| "consistent / factual" | Lower temperature |
| "truncated responses" | Increase max tokens |
| "meaning as numbers" | Embeddings |
| "semantic search" | Embeddings + vector DB |
| "graph relationships" | Neptune |
| "existing PostgreSQL" | Aurora/RDS pgvector |
| "vector + keyword search at scale" | OpenSearch |
| "take actions / call APIs / multi-step" | Bedrock Agents / AgentCore |
| "standard way to connect agents to tools" | MCP |
| "APIs → MCP tools" | AgentCore Gateway |
| "agent OAuth / credentials on behalf of users" | AgentCore Identity |
| "control agent tool calls deterministically" | Policy in AgentCore |
| "open-source SDK for agents" | Strands Agents |
| "agentic IDE / spec-driven" | Kiro |
| "employee AI assistant, no build" | Amazon Quick / Q Business |
| "harmful content / denied topics / PII masking" | Bedrock Guardrails |
| "ungrounded / hallucination in RAG" | Guardrails contextual grounding check |
| "ignore previous instructions" | Prompt injection |
| "role-play to bypass safety" | Jailbreaking |
| "tampered training data" | Poisoning |
| "summarization metric" | ROUGE |
| "translation metric" | BLEU |
| "semantic similarity metric" | BERTScore |
| "model grades model" | LLM-as-a-judge |
| "compare FMs on our prompts" | Bedrock Model Evaluation |
| "who can access" | IAM |
| "encryption keys" | KMS |
| "passwords / API keys rotation" | Secrets Manager |
| "PII in S3" | Macie |
| "API activity / who did what" | CloudTrail |
| "metrics / alarms / logs" | CloudWatch |
| "configuration compliance" | AWS Config |
| "vulnerabilities / CVEs" | Inspector |
| "compliance reports (SOC/ISO)" | Artifact |
| "best-practice recommendations" | Trusted Advisor |
| "no public internet" | PrivateLink |
| "data must stay in country" | Data residency (Region) |
| "delete after X days" | S3 Lifecycle (retention) |
| "data origin & transformations" | Data lineage |
| "inventory of datasets" | Data catalog (Glue Data Catalog) |
| "images" | Rekognition |
| "scanned forms/tables" | Textract |
| "speech → text" | Transcribe |
| "text → speech" | Polly |
| "translate" | Translate |
| "sentiment / entities" | Comprehend |
| "chatbot intents" | Lex |
| "recommendations" | Personalize |
| "enterprise search" | Kendra |
| "generate video" | Nova Reel |
| "generate image" | Nova Canvas / Stability AI |
| "energy efficient / sustainable" | Reuse FMs, smaller models, Inferentia/Trainium |

---

## 8.6 TOP 50 THINGS I MUST MEMORIZE

1. Domain weights: 20 / 24 / **28** / 14 / 14. Pass = 700.
2. AI ⊃ ML ⊃ DL ⊃ GenAI; agentic AI **acts**.
3. Supervised = labels; unsupervised = no labels; RL = rewards.
4. Classification = category; regression = number; clustering = groups without labels.
5. Overfit = train good/test bad; underfit = both bad.
6. Precision = avoid false positives; recall = avoid false negatives; F1 = balance.
7. Accuracy is misleading for imbalanced data.
8. Real-time / Serverless / Async (1 GB, 1 hr) / Batch.
9. ML lifecycle order ending in Monitor → Retrain.
10. FM lifecycle: Data sel → Model sel → Pre-train → Fine-tune → Evaluate → Deploy → Feedback.
11. SageMaker features: Canvas (no-code), JumpStart (pre-trained), Ground Truth (labels), Clarify (bias/explain), Model Monitor (drift), Model Cards (docs), Pipelines (MLOps), A2I (human review).
12. Token ≈ 4 chars ≈ ¾ word; billing unit; output tokens cost more.
13. Embedding = meaning as vector; vector DB = similarity search.
14. Chunking = split docs before embedding.
15. Context window = max input+output tokens.
16. Transformer = attention (LLMs); diffusion = denoising (images).
17. Temperature ↓ = consistent; ↑ = creative. Max tokens = length.
18. Prompt caching = identical prefix reused → cheaper and faster.
19. RAG = no weight change; private/current data; citations; Bedrock Knowledge Bases.
20. RAG order: chunk → embed → store → embed query → retrieve → augment → generate.
21. Vector stores: OpenSearch (default), Aurora/RDS pgvector, Neptune (graph), S3 Vectors, MemoryDB.
22. Fine-tuning = labeled pairs (JSONL in S3), weights change, style/format; needs Provisioned Throughput.
23. Continued pre-training = unlabeled domain data.
24. Distillation = teacher → student; cheaper and faster.
25. RLHF = human rankings → reward model → RL.
26. Zero/one/few-shot; CoT = step by step; negative prompt = exclusions.
27. Bedrock Prompt Management = versioning prompts.
28. Prompt injection ≠ jailbreak ≠ poisoning ≠ leakage.
29. ROUGE = summarization; BLEU = translation; BERTScore = semantic.
30. Bedrock Model Evaluation: automatic, human, LLM-as-a-judge, RAG evaluation.
31. Agent = FM + tools + memory + instructions; ReAct loop.
32. MCP = open protocol, "USB-C for AI tools"; AgentCore Gateway exposes MCP tools.
33. AgentCore components: Runtime, Memory, Gateway, Identity, Policy, Code Interpreter, Browser, Observability.
34. Bedrock Agents = managed; AgentCore = any framework at scale; Strands = SDK; Kiro = IDE; Quick = employee assistant.
35. Multi-agent = supervisor + specialists.
36. Limitations: hallucination, nondeterminism, interpretability, knowledge cutoff, bias, toxicity.
37. Bedrock: data not used to train base models; stays in Region; KMS; PrivateLink; CloudTrail.
38. Pricing: on-demand, batch (~50% off), provisioned throughput, caching.
39. Business metrics: conversion rate, CLV, ARPU, CSAT, productivity, task completion, ROI.
40. Responsible AI dimensions: fairness, explainability, privacy/security, safety, controllability, veracity/robustness, governance, transparency.
41. Guardrails 6 policies: content (+prompt attack), denied topics, words, PII (block/mask), grounding, Automated Reasoning.
42. Explainability (why this output) vs interpretability (how the model works) vs transparency (documentation/disclosure).
43. Model Cards (yours) vs AI Service Cards (AWS's).
44. Legal risks: IP, biased outputs, loss of trust, end-user risk, hallucinations.
45. Shared responsibility: AWS OF, customer IN.
46. IAM roles for services; least privilege; AuthN vs AuthZ.
47. KMS keys · Secrets Manager secrets · Macie PII in S3 · PrivateLink private access.
48. CloudTrail who · CloudWatch health · Config configuration · Inspector vulns · Artifact reports · Trusted Advisor advice.
49. Scoping Matrix: 1 Consumer, 2 Enterprise, 3 Pre-trained, 4 Fine-tuned, 5 Self-trained.
50. Data governance: lineage, catalog, quality, integrity, residency, retention, lifecycle.

---

## 8.7 NIGHT-BEFORE-EXAM REVISION (≈60–90 MINUTES)

**Step 1 (15 min): Read the 1-page cheat sheet (§8.1) twice.** Say each line out loud.

**Step 2 (15 min): Re-read these tables only:**
- Inference types (Part 1 §1.2)
- RAG vs Fine-tuning vs ICL vs Pre-training vs Distillation (Part 3 §3.5)
- Guardrails 6 policies (Part 4 §4.3)
- Security services comparison (Part 5 §5.4)
- "Which service do I choose?" (Part 6 §6.6)

**Step 3 (15 min): Skim the Top 100 traps (Part 7).** Read only the "→" tie-breaker lines.

**Step 4 (15 min): Re-do the practice questions you got wrong.**

**Step 5: Stop. Sleep.** A rested brain beats 2 extra hours of cramming.

**Exam-day strategy:**
- Read the **last sentence** of the question first (what is actually asked?).
- Underline mentally: **"MOST cost-effective", "LEAST operational overhead", "MOST secure", "with minimal effort"**. These decide between two correct-looking answers.
  - "Least operational overhead" → **managed/serverless** (Bedrock, AI services, Knowledge Bases).
  - "Most cost-effective" → **simplest approach** (prompting < RAG < fine-tuning; smaller model; batch).
  - "Most secure" → **least privilege, encryption, PrivateLink, Guardrails**.
- Eliminate answers with **wrong service categories** first (e.g., Inspector for PII).
- Multiple response: the question tells you how many to pick ("Select TWO").
- Flag hard questions, move on, come back. **Answer everything.**
- Watch for **absolute words** ("always", "guarantees", "eliminates"). They are often wrong for GenAI (e.g., "RAG eliminates hallucinations" ❌; it **reduces** them).

---

## 8.8 30-MINUTE FINAL REVISION SHEET (EXAM MORNING)

**Minute 0–5: Fundamentals**
- Labels → supervised. No labels → clustering. Rewards → RL.
- Category → classification. Number → regression.
- Overfit: train ✅ test ❌. Underfit: ❌❌.
- Recall = don't miss. Precision = no false alarms. F1 = imbalanced.
- Real-time / Serverless (idle) / Async (big, slow) / Batch (bulk, cheap).

**Minute 5–12: GenAI**
- Token = billing. Embedding = meaning. Chunking = split docs. Context window = capacity.
- Temperature: low = consistent, high = creative. Max tokens = length.
- Hallucination → RAG + grounding check. Inconsistency → lower temperature.
- Agent = acts (tools + memory). MCP = USB-C for tools. AgentCore Gateway = MCP tools. Identity = agent creds. Policy = tool-call rules.
- On-demand / Batch (cheap) / Provisioned (custom models) / Caching (repeated prefix).

**Minute 12–20: Applications**
- Prompt → RAG → Fine-tune → Continued pre-train → Pre-train (cost ↑).
- Private/changing docs → RAG (Knowledge Bases). Style → fine-tune. Unlabeled domain → continued pre-train. Cheaper clone → distillation.
- Few-shot = examples. CoT = step by step. Negative prompt = don't include.
- Injection = override. Jailbreak = bypass safety. Poisoning = bad data.
- ROUGE = summary. BLEU = translation. BERTScore = meaning. LLM-as-judge = scale.

**Minute 20–25: Responsible AI**
- Guardrails: content, topics, words, PII, grounding, Automated Reasoning.
- Clarify = bias + explain. Model Monitor = drift. A2I = human review. Model Cards = documentation.
- Explainability = why. Interpretability = how inside. Transparency = disclose.

**Minute 25–30: Security**
- AWS = OF, you = IN.
- IAM = who. KMS = keys. Secrets Manager = passwords. Macie = PII in S3.
- CloudTrail = who did what. CloudWatch = health. Config = settings. Inspector = vulns. Artifact = reports. Trusted Advisor = advice.
- PrivateLink = no internet. Scopes: Consumer, Enterprise, Pre-trained, Fine-tuned, Self-trained.

**You're ready. Go pass it.** ✅

**➡ Continue to PART 9 — Practice Questions**
