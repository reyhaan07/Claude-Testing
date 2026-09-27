# PART 7 — AIF-C01 MASTER NOTES

# TOP 100 AIF-C01 EXAM TRAPS

Each trap: the confusing pair → the difference in 2–5 lines → the tie-breaker.

---

## A. AI/ML FUNDAMENTALS (1–25)

**1. AI vs ML**
AI is the umbrella: any machine that mimics human intelligence, including hard-coded rules. ML is a subset that **learns patterns from data**.
→ A rules engine is AI but **not** ML.

**2. ML vs Deep Learning**
ML includes simple algorithms (linear regression, decision trees, XGBoost). DL is the part of ML that uses **many-layered neural networks**, needs lots of data and compute, and excels at unstructured data.
→ Tabular + small data → ML. Images/audio/text at scale → DL.

**3. Deep Learning vs Neural Network**
A neural network is the **structure** (nodes, layers, weights). Deep learning is **using neural networks with many hidden layers**.
→ All DL uses NNs, but a 1-hidden-layer NN isn't "deep".

**4. GenAI vs Traditional ML**
Traditional ML **predicts** labels or numbers for one task using labeled data. GenAI **creates** new content with pre-trained FMs and handles many tasks.
→ "Predict churn from a table" = traditional ML. "Write a retention email" = GenAI.

**5. Foundation Model vs LLM**
An FM is any large pre-trained, general-purpose model (text, image, audio, embeddings). An LLM is an FM **for language**.
→ Image generators (Nova Canvas, Stable Diffusion) are FMs but **not LLMs**.

**6. Training vs Inference**
Training = the model **learns** and weights change (expensive, occasional). Inference = the model **predicts on new data** and weights are fixed (every request).
→ "Slow responses in production" is an inference problem, not a training one.

**7. Classification vs Regression**
Classification predicts a **category** (yes/no, A/B/C). Regression predicts a **continuous number** (price, temperature).
→ "Will the customer churn?" = classification. "How much will they spend?" = regression.

**8. Classification vs Clustering**
Classification uses **labels** (supervised). Clustering discovers groups **without labels** (unsupervised).
→ "Segments are not known in advance" = clustering.

**9. Supervised vs Unsupervised**
Supervised = **labeled** data (input + correct answer). Unsupervised = **unlabeled** data, finding hidden structure.
→ Look for the word "labeled" or "historical outcomes".

**10. Unsupervised vs Reinforcement**
Both lack labels. RL has an **agent, environment, and rewards/penalties** and learns by trial and error.
→ "Reward" = RL.

**11. Logistic regression = classification**
Despite the name, logistic regression predicts **probabilities of classes**.
→ Don't pick "regression task" just because of the word.

**12. Precision vs Recall**
Precision = of predicted positives, how many were right (avoid **false positives**). Recall = of actual positives, how many were found (avoid **false negatives**).
→ Disease/fraud "must not miss" = recall. "Don't bother innocent customers" = precision.

**13. Accuracy on imbalanced data**
With 99% negatives, a model that always says "negative" is 99% accurate but useless.
→ Imbalanced → **F1 / precision / recall**, not accuracy.

**14. F1 vs Accuracy**
F1 balances precision and recall (harmonic mean). Accuracy counts all correct predictions.
→ Imbalanced classes → F1.

**15. Overfitting vs Underfitting**
Overfitting = great on training, poor on test (memorized; high variance). Underfitting = poor on both (too simple; high bias).
→ Overfit fix: more/diverse data, regularization, simpler model, early stopping. Underfit fix: more features, a more complex model, train longer.

**16. "Train longer" trap**
Training longer helps **underfitting** but worsens **overfitting**.
→ Read which problem is described.

**17. Statistical bias vs ethical bias**
Statistical bias = model too simple (underfitting). Ethical/societal bias = unfair outcomes for groups (from skewed data).
→ Domain 4 questions mean the **ethical** kind.

**18. Real-time vs Serverless inference**
Real-time = always-on endpoint, consistent low latency, steady traffic. Serverless = scales to zero, pay per use, **cold starts**, intermittent traffic.
→ "Unpredictable traffic with idle periods" = serverless.

**19. Asynchronous vs Batch inference**
Async = individual **large (up to 1 GB) or long-running** requests, queued, near-real-time. Batch = a **whole dataset** processed offline, no endpoint.
→ "Entire dataset nightly" = batch. "Large payload per request" = async.

**20. Batch vs Real-time cost**
Batch is cheaper (no always-on endpoint; ~50% cheaper in Bedrock).
→ "Not time-sensitive + lowest cost" = batch.

**21. Parameters vs Hyperparameters**
Parameters (weights) are **learned** during training. Hyperparameters (learning rate, epochs) are **set before** training.
→ "Tune automatically" → SageMaker Automatic Model Tuning.

**22. Ground Truth vs A2I**
Ground Truth = humans **label training data** (before training). A2I = humans **review predictions** (after deployment, e.g., low confidence).
→ Before training = Ground Truth. After prediction = A2I.

**23. Model Monitor vs Clarify**
Model Monitor = watches production for **drift** (data, quality, bias drift). Clarify = **detects bias** and **explains** predictions (feature importance).
→ "Why this prediction?" = Clarify. "Accuracy dropping over time" = Model Monitor.

**24. Model Registry vs Model Cards**
Model Registry = **versions & approval status** for deployment (MLOps). Model Cards = **documentation** of intended use, risks, and evaluation (governance).
→ "Document for auditors" = Model Cards.

**25. When NOT to use ML**
If a deterministic rule/formula solves it, or exact answers are required, or there's no good data, don't use ML.
→ "Calculate tax with a fixed formula" = traditional code.

---

## B. GENERATIVE AI CONCEPTS (26–50)

**26. Token vs Embedding**
A token is a **piece of text** (the unit for limits and billing). An embedding is a **numeric vector capturing meaning**.
→ "Priced per…" = tokens. "Semantic similarity" = embeddings.

**27. Vector vs Embedding**
A vector is just a **list of numbers** (the format). An embedding is a vector **produced by a model to represent meaning**.
→ Embeddings are stored as vectors in a vector DB.

**28. Tokenization vs Chunking**
Tokenization splits text into tokens **for the model**. Chunking splits **documents** into passages **for RAG retrieval**.
→ "Split documents before embedding" = chunking.

**29. Context window vs Max tokens**
Context window = total tokens the model can handle per request (input + output). Max tokens = an inference parameter capping **output** length.
→ "Document too long to process" = context window. "Answer cut off" = max tokens.

**30. Temperature vs Token limit (max tokens)**
Temperature controls **randomness/creativity**. Max tokens controls **length**.
→ "Inconsistent answers" → lower temperature. "Truncated answers" → raise max tokens.

**31. Temperature vs Top-p vs Top-k**
Temperature reshapes probabilities (creativity). Top-p keeps the words within a **cumulative probability** p. Top-k keeps the **k most likely** words.
→ All three control diversity. Temperature is the most common exam answer.

**32. High temperature ≠ better accuracy**
Higher temperature = more creative but **more hallucination risk**.
→ Factual/compliance tasks → low temperature.

**33. Input tokens vs Output tokens pricing**
Both are billed; output tokens usually cost **more**.
→ Reduce cost by shortening outputs (max tokens, "be concise") and prompts.

**34. Transformer vs Diffusion**
Transformers (attention) power LLMs/text. Diffusion models generate **images** by denoising random noise.
→ "Image from noise" = diffusion.

**35. Multimodal model vs Multiple models**
A multimodal model handles **several data types in one model** (text + image).
→ "Answer questions about an uploaded photo" = multimodal FM.

**36. Generative vs Predictive AI**
Predictive outputs a label/score. Generative outputs new content.
→ "Detect spam" = predictive. "Write a reply" = generative.

**37. Hallucination vs Bias**
Hallucination = **made-up/false** facts. Bias = **unfair** treatment of groups.
→ Hallucination fix: RAG + grounding. Bias fix: diverse data + Clarify.

**38. Hallucination vs Toxicity**
Hallucination = false content. Toxicity = **offensive/harmful** content.
→ Toxicity → Guardrails content filters.

**39. Nondeterminism**
The same prompt can give different outputs because of sampling.
→ Lower temperature (and use fixed templates) for consistency.

**40. Knowledge cutoff vs Hallucination**
Knowledge cutoff = the model **doesn't know** recent events. Hallucination = the model **invents** facts.
→ Both are commonly fixed by RAG. Recent info → RAG/tools, not fine-tuning.

**41. Chatbot vs Agent**
A chatbot **answers**. An agent **plans and acts** using tools and APIs (e.g., processes a refund).
→ "Update records / call APIs / complete tasks" = agent.

**42. RAG vs Agent**
RAG = **retrieve knowledge** to answer. Agent = **take actions**, possibly using RAG as a tool.
→ "Look up policy" = RAG. "Look up policy AND file the claim" = agent.

**43. Bedrock Knowledge Bases vs Bedrock Agents**
Knowledge Bases = managed RAG (retrieve and answer with citations). Agents = orchestrate multi-step tasks and call APIs via action groups (can include a KB).
→ Info only → KB. Actions → Agents.

**44. Bedrock Agents vs AgentCore**
Bedrock Agents = **managed, configuration-based** agents inside Bedrock. AgentCore = **infrastructure/services to deploy and operate any agent** (any framework, any model) at scale.
→ "Open-source framework agents in production" = AgentCore.

**45. MCP vs API**
An API is one system's specific interface. MCP is an **open standard protocol** so agents can connect to **many tools/data sources in one consistent way**.
→ "Standardized tool connectivity for agents" = MCP.

**46. MCP vs A2A**
MCP connects **agents ↔ tools/data**. A2A (Agent-to-Agent) connects **agents ↔ agents**.
→ Tools/data = MCP.

**47. MCP is not a service or a model**
MCP is a **protocol**. AWS provides **AgentCore Gateway** to expose tools via MCP.
→ If asked for the AWS service that turns APIs into MCP tools → AgentCore Gateway.

**48. Workflow (Flows) vs Agent**
Flows/Step Functions = **predefined, fixed** sequence. Agents = the **model decides steps dynamically**.
→ "Same steps every time" = Flows. "Decide which tools to use" = agent.

**49. Prompt engineering vs Context engineering**
Prompt engineering = **how** you phrase the request. Context engineering = **what information** (docs, memory, tool results, history) goes into the context window.
→ "Manage which history/documents/memory to include" = context engineering.

**50. Short-term vs Long-term agent memory**
Short-term = current session/conversation. Long-term = persists **across sessions** (preferences, facts).
→ "Remember preferences next week" = long-term memory (AgentCore Memory).

---

## C. APPLICATIONS OF FMs (51–75)

**51. RAG vs Fine-tuning**
RAG adds **knowledge at query time** (no weight change; easy to update). Fine-tuning changes **weights** to learn **style/format/task behavior**.
→ Frequently changing facts = RAG. Brand voice = fine-tuning.

**52. Fine-tuning vs Continued pre-training**
Fine-tuning = **labeled** prompt-completion pairs (task/style). Continued pre-training = **unlabeled** domain text (domain knowledge/vocabulary).
→ Check whether the data is labeled.

**53. Fine-tuning vs Pre-training**
Pre-training builds an FM **from scratch** (hugely expensive). Fine-tuning **adapts** an existing FM.
→ Pre-training is almost never the answer.

**54. In-context learning vs Fine-tuning**
In-context learning = examples **in the prompt**, no weight change, temporary. Fine-tuning = persistent weight change.
→ "Without training" = in-context/few-shot.

**55. Distillation vs Fine-tuning**
Both train a model. Distillation trains a **small student on a large teacher's outputs** to cut **cost/latency**. Fine-tuning trains on **your labeled data** for task quality.
→ "Smaller, faster, near-same accuracy" = distillation.

**56. Transfer learning vs Fine-tuning**
Transfer learning is the **general concept** of reusing a pre-trained model for a new task. Fine-tuning is a **method** of doing it.
→ "Reuse knowledge from a model trained on a different task" = transfer learning.

**57. RLHF vs Fine-tuning**
RLHF uses **human preference rankings** and a reward model (reinforcement learning) to align outputs with human values. Standard fine-tuning uses labeled examples.
→ "Humans rank responses" = RLHF.

**58. Instruction tuning**
Fine-tuning on instruction→response pairs to make the model **follow instructions**.
→ "Model doesn't follow directions well" = instruction tuning.

**59. Zero-shot vs Few-shot**
Zero-shot = no examples. Few-shot = several examples in the prompt.
→ "Provide examples to guide format" = few-shot.

**60. One-shot vs Few-shot**
One-shot = exactly **one** example. Few-shot = **2+** examples.

**61. Chain-of-thought vs Few-shot**
CoT = ask for **step-by-step reasoning** (complex logic/math). Few-shot = give **examples** to copy.
→ "Multi-step reasoning accuracy" = CoT.

**62. Negative prompt**
Specifies what **not** to include (common in image generation).
→ "Exclude blurry backgrounds/text in images" = negative prompt.

**63. Prompt template vs Prompt Management**
A prompt template is a **reusable prompt with variables**. Bedrock Prompt Management is the **service feature to store, version, test, and share** templates.
→ "Version and share prompts" = Prompt Management.

**64. Prompt caching vs RAG**
Prompt caching reuses an **identical static prompt prefix** to save cost/latency. RAG retrieves **different relevant content** per query.
→ "Same long document included in every request" = prompt caching.

**65. Prompt caching vs fine-tuning for cost**
Caching lowers the cost of repeated context without training. Fine-tuning has training and hosting costs.
→ "Reduce cost of repeated context" = caching.

**66. Provisioned Throughput vs On-demand**
On-demand = pay per token, no commitment, variable use. Provisioned = reserved model units for **guaranteed throughput**, usually **required for custom models**.
→ "Fine-tuned model deployment" or "guaranteed capacity" = provisioned.

**67. Batch inference vs Provisioned Throughput**
Batch = cheap, asynchronous, large non-urgent jobs. Provisioned = dedicated capacity for steady, high, real-time traffic.

**68. Bigger model ≠ always better**
Bigger = more capable but higher cost/latency.
→ "Lowest cost/latency for simple task" = smaller model.

**69. OpenSearch vs Aurora/RDS pgvector**
OpenSearch = dedicated search engine (vector + keyword **hybrid search**, scale; default for KBs). Aurora/RDS PostgreSQL = **relational DB** with pgvector (use when you already use PostgreSQL / need SQL + vectors).
→ "Existing PostgreSQL" = Aurora/RDS.

**70. Neptune vs OpenSearch**
Neptune = **graph relationships** (GraphRAG). OpenSearch = similarity/keyword search.
→ "Relationships between entities" = Neptune.

**71. Kendra vs Bedrock Knowledge Bases**
Kendra = intelligent **enterprise search service** (returns documents/answers). Bedrock KBs = managed **RAG for FMs** (retrieve + generate with an FM).
→ "Generate answers with an FM from documents" = KBs. "Enterprise search" = Kendra.

**72. Prompt injection vs Jailbreaking**
Injection = malicious input **overrides the app's instructions** (direct or hidden in documents). Jailbreaking = tricking the model to **bypass its safety rules** (often role-play).
→ "Ignore previous instructions" = injection. "Pretend you have no rules" = jailbreak.

**73. Prompt injection vs Poisoning**
Injection happens at **inference time** via input. Poisoning **corrupts training/fine-tuning data or knowledge sources** ahead of time.
→ "Tampered training data" = poisoning.

**74. Prompt hijacking vs Prompt leaking**
Hijacking = **redirecting the model's task** to the attacker's goal. Leaking = extracting the **hidden system prompt/data**.

**75. ROUGE vs BLEU vs BERTScore**
ROUGE = **summarization** (recall of overlapping words). BLEU = **translation** (precision of n-grams). BERTScore = **semantic similarity** via embeddings.
→ Summaries → ROUGE. Translations → BLEU. Meaning → BERTScore.

---

## D. RESPONSIBLE AI (76–85)

**76. Human evaluation vs LLM-as-a-judge**
Human evaluation = most nuanced for subjective quality, but slow and expensive. LLM-as-a-judge = scalable, cheaper, human-like scoring, but the judge can be biased.
→ "Brand voice judged by experts" = human. "Evaluate thousands quickly" = LLM-as-a-judge.

**77. Benchmark datasets vs custom datasets**
Benchmarks compare models on standard public tasks. Custom datasets reflect **your** use case.
→ "Our specific domain" = custom prompt dataset in Bedrock Model Evaluation.

**78. Explainability vs Interpretability**
Explainability = explain **why a specific output** happened (post-hoc; Clarify/SHAP). Interpretability = how understandable the **model's inner workings** are (simple models).
→ "Why was this loan denied?" = explainability.

**79. Transparency vs Explainability**
Transparency = **openness/documentation** about the system (data, purpose, limits, AI disclosure). Explainability = reasons for **individual** decisions.
→ Model Cards/AI Service Cards = transparency.

**80. SageMaker Model Cards vs AWS AI Service Cards**
Model Cards = **you** document **your** models. AI Service Cards = **AWS** documents **its** AI services.

**81. Fairness vs Inclusivity**
Fairness = equitable **outcomes** across groups. Inclusivity = **representing and serving diverse users** (data, design, accessibility).

**82. Robustness vs Veracity**
Robustness = works reliably under **unexpected/adversarial inputs**. Veracity = outputs are **true/accurate**.

**83. Guardrails vs Fine-tuning for safety**
Guardrails = configurable filters applied to inputs/outputs, with no retraining, consistent across models. Fine-tuning changes the model but doesn't guarantee blocking.
→ "Block harmful content quickly and consistently" = Guardrails.

**84. Guardrails denied topics vs word filters**
Denied topics = block **whole subjects** by meaning (e.g., investment advice). Word filters = block **specific words/phrases** (profanity, competitor names).

**85. Contextual grounding check vs Automated Reasoning checks**
Grounding check = compares the response to the **source context** (grounded? relevant?). Automated Reasoning = **formal logic verification** against defined **policy rules**.
→ RAG hallucinations = grounding. "Mathematically verify policy compliance" = Automated Reasoning.

---

## E. SECURITY, COMPLIANCE, GOVERNANCE (86–100)

**86. IAM vs KMS**
IAM = **who can access what**. KMS = **encryption keys** to protect data.
→ "Restrict access" = IAM. "Encrypt with our own keys" = KMS.

**87. KMS vs Secrets Manager**
KMS = manages **cryptographic keys**. Secrets Manager = stores and **rotates credentials/API keys/passwords** (encrypted by KMS).
→ "Database password rotation" = Secrets Manager.

**88. Macie vs Inspector**
Macie = finds **sensitive data (PII) in S3**. Inspector = finds **software vulnerabilities** in EC2/ECR/Lambda.
→ Data = Macie. Software = Inspector.

**89. Macie vs Guardrails PII filter vs Comprehend PII**
Macie scans **S3 data at rest**. Guardrails masks PII in **GenAI prompts/responses**. Comprehend detects PII in **text you send to it**.

**90. CloudTrail vs CloudWatch**
CloudTrail = **who did what** (API audit log). CloudWatch = **performance metrics, logs, alarms**.
→ "Who deleted the model?" = CloudTrail. "Latency spike alarm" = CloudWatch.

**91. Config vs CloudTrail**
Config = **what the resource configuration is/was** and whether it's compliant. CloudTrail = **who made the change** (API call).
→ "Is encryption enabled on all buckets?" = Config.

**92. CloudTrail vs Bedrock invocation logging**
CloudTrail records that an API was called. Invocation logging records the **prompt and response content** (must be enabled).

**93. Artifact vs Audit Manager**
Artifact = download **AWS's** compliance reports (SOC, ISO). Audit Manager = collects evidence about **your** environment for **your** audits.

**94. Trusted Advisor vs Config vs Inspector**
Trusted Advisor = best-practice **recommendations** (cost, security, limits). Config = **configuration compliance tracking**. Inspector = **vulnerability scans**.

**95. Guardrails vs IAM**
Guardrails = controls **content** (what is said). IAM = controls **access** (who can call which API).
→ "Block toxic output" = Guardrails. "Only admins can invoke" = IAM.

**96. Guardrails vs Policy in AgentCore**
Guardrails = filter **content** of prompts/responses. Policy in AgentCore = **deterministic allow/deny rules on agent tool calls** (Cedar, default-deny).
→ "Agent may only refund under $500" = Policy in AgentCore.

**97. AgentCore Identity vs IAM vs Secrets Manager**
AgentCore Identity = identity and **OAuth/API credential management for agents** acting on behalf of users. IAM = AWS principals' permissions. Secrets Manager = general secret storage.
→ "Agent accesses user's Salesforce securely" = AgentCore Identity.

**98. Authentication vs Authorization**
Authentication = **who you are** (login, MFA). Authorization = **what you can do** (permissions).
→ AuthN first, then AuthZ.

**99. Shared responsibility for Bedrock**
AWS secures the infrastructure and model hosting. **You** manage IAM, data, encryption choices, guardrails, and app security.
→ "Who configures access to the model?" = customer.

**100. Scoping Matrix: Scope 3 vs Scope 4**
Scope 3 = app using a **pre-trained FM** as is (e.g., Bedrock + RAG). Scope 4 = **fine-tuned** FM with your data. RAG does **not** move you to Scope 4, because weights don't change.

---

### BONUS TRAPS (quick-fire)
- **Bedrock vs SageMaker:** Bedrock = serverless FM API (least effort). SageMaker = build/train/host your own (full control). → "Least operational overhead" = Bedrock.
- **JumpStart vs Bedrock:** JumpStart deploys models **into your SageMaker endpoints** (you manage instances). Bedrock is **serverless**.
- **Lex vs Bedrock chatbot:** Lex = intent/slot-based conversational bots (IVR, structured flows). Bedrock = free-form generative answers. (They can be combined.)
- **Textract vs Rekognition:** documents vs general images/video.
- **Transcribe vs Polly:** speech→text vs text→speech.
- **Comprehend vs Bedrock for sentiment:** Comprehend = purpose-built, cheaper, simpler.
- **Personalize vs Bedrock for recommendations:** Personalize = purpose-built recommendation engine.
- **PrivateLink vs VPC:** A VPC is your private network. PrivateLink is the private connection **from** it to AWS services.
- **Data residency vs retention:** residency = **where** data lives. Retention = **how long** it's kept.
- **Lineage vs Catalog:** lineage = data's history/transformations. Catalog = inventory/metadata of datasets.

**➡ Continue to PART 8 — Memorization Section**
