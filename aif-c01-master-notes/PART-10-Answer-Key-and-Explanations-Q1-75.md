# PART 10 — AIF-C01 MASTER NOTES

# ANSWER KEY + DETAILED EXPLANATIONS (Q1–Q75)

(Explanations for Q76–Q150 are in **PART 11**.)

---

## ANSWER KEY (ALL 150)

### Section A — Basic
| Q | Ans | Q | Ans | Q | Ans | Q | Ans | Q | Ans |
|---|---|---|---|---|---|---|---|---|---|
| 1 | B | 11 | A | 21 | B | 31 | B | 41 | B |
| 2 | D | 12 | A | 22 | C | 32 | B | 42 | C |
| 3 | C | 13 | D | 23 | B | 33 | A | 43 | B |
| 4 | A | 14 | C | 24 | D | 34 | D | 44 | B |
| 5 | D | 15 | B | 25 | C | 35 | C | 45 | C |
| 6 | A | 16 | A | 26 | A | 36 | B | 46 | A |
| 7 | B | 17 | B | 27 | D | 37 | D | 47 | A |
| 8 | D | 18 | D | 28 | C | 38 | A | 48 | B |
| 9 | B | 19 | A | 29 | A | 39 | B | 49 | B |
| 10 | C | 20 | D | 30 | C | 40 | B | 50 | C, E |

### Section B — Medium
| Q | Ans | Q | Ans | Q | Ans | Q | Ans | Q | Ans |
|---|---|---|---|---|---|---|---|---|---|
| 51 | A | 61 | D | 71 | 1-d, 2-b, 3-a, 4-c | 81 | D | 91 | 2 → 4 → 5 → 1 → 3 |
| 52 | C | 62 | D | 72 | D | 82 | C | 92 | C |
| 53 | A, D | 63 | D | 73 | D | 83 | D | 93 | C |
| 54 | D | 64 | A | 74 | D | 84 | B | 94 | A |
| 55 | D | 65 | C | 75 | C | 85 | C | 95 | C |
| 56 | 2 → 6 → 4 → 5 → 1 → 3 | 66 | B | 76 | C | 86 | A | 96 | C |
| 57 | B | 67 | B | 77 | A | 87 | B, D | 97 | A, D |
| 58 | D | 68 | C | 78 | B | 88 | B | 98 | D |
| 59 | D | 69 | D | 79 | A | 89 | A | 99 | 1-b, 2-c, 3-d, 4-a |
| 60 | B, E | 70 | C | 80 | A | 90 | A | 100 | B |

### Section C — Difficult
| Q | Ans | Q | Ans | Q | Ans | Q | Ans | Q | Ans |
|---|---|---|---|---|---|---|---|---|---|
| 101 | B | 111 | A | 121 | C | 131 | D | 141 | C |
| 102 | A | 112 | D | 122 | A, D | 132 | B, E | 142 | C |
| 103 | A | 113 | D, E | 123 | B | 133 | A | 143 | B |
| 104 | C | 114 | D | 124 | B, C | 134 | A | 144 | A |
| 105 | C | 115 | A | 125 | B, E | 135 | A, C | 145 | 4 → 2 → 5 → 3 → 1 |
| 106 | C | 116 | 3 → 6 → 2 → 7 → 5 → 1 → 4 | 126 | A | 136 | B, C, E | 146 | A, B, D |
| 107 | A, E | 117 | C | 127 | B | 137 | A, D | 147 | A |
| 108 | B, D | 118 | C | 128 | 1-c, 2-b, 3-a, 4-d | 138 | A, E | 148 | 1-b, 2-c, 3-d, 4-a |
| 109 | A | 119 | D | 129 | D | 139 | B | 149 | D |
| 110 | C | 120 | B | 130 | B, E | 140 | B | 150 | C, D, E |

---

## DETAILED EXPLANATIONS — SECTION A (BASIC)

**Q1 — B**
- ✅ ML is the part of AI where systems **learn patterns from data** instead of following hand-written rules.
- ❌ A: Encryption is security (KMS), not ML. C: If/then rules are rule-based AI, not ML. D: That's a database.
- 🔑 Keyword: "learn patterns from data".

**Q2 — D**
- ✅ Each email has a **label** (spam/not spam), so this is **supervised** learning (binary classification).
- ❌ A: Unsupervised uses no labels. B: Self-supervised creates its own labels from raw data (FM pre-training). C: RL uses rewards, not labeled examples.
- 🔑 Keyword: "labeled".

**Q3 — C**
- ✅ A price is a **continuous number**, so this is regression.
- ❌ A: Classification predicts categories. B: Anomaly detection finds outliers. D: Clustering groups unlabeled data.
- 🔑 Keyword: "predict the selling price" (a number).

**Q4 — A**
- ✅ There are no predefined categories, so the model must **discover groups**: clustering (unsupervised).
- ❌ B: RL needs rewards. C: Regression predicts numbers. D: Classification needs known labels.
- 🔑 Keyword: "no predefined categories", "group".

**Q5 — D**
- ✅ Positive and negative **points (rewards/penalties)** for actions = reinforcement learning.
- ❌ A: Supervised needs labeled examples. B: Transfer learning reuses a pre-trained model. C: Unsupervised finds structure; it has no rewards.
- 🔑 Keyword: "positive points… negative points".

**Q6 — A**
- ✅ High training accuracy + low test accuracy = the model **memorized** the training data = **overfitting**.
- ❌ B: Latency is about speed, not accuracy. C: Underfitting = poor on both. D: A good fit performs well on both.
- 🔑 Keyword: "98% on training… 60% on test".

**Q7 — B**
- ✅ Inference = **using a trained model on new data** to get predictions.
- ❌ A: That's training. C: That's hyperparameter selection. D: That's data labeling.
- 🔑 Keyword: "predictions on new data".

**Q8 — D**
- ✅ **Transcribe** = speech → text.
- ❌ A: Comprehend analyzes text. B: Polly does text → speech (the opposite). C: Translate converts between languages.
- 🔑 Keyword: "speech… to text".

**Q9 — B**
- ✅ **Polly** = text → lifelike speech.
- ❌ A: Transcribe is speech → text. C: Rekognition analyzes images. D: Lex builds chatbots.
- 🔑 Keyword: "text into lifelike speech".

**Q10 — C**
- ✅ **Textract** extracts text, **key-value pairs (forms), and tables** from scanned documents.
- ❌ A: Kendra is enterprise search. B: Comprehend analyzes text it is given; it doesn't read scans. D: Rekognition analyzes general images and isn't built for forms or tables.
- 🔑 Keyword: "scanned forms", "tables", "key-value pairs".

**Q11 — A**
- ✅ **Comprehend** does sentiment analysis out of the box, with no ML expertise needed.
- ❌ B: Translate changes language. C: Lex builds chatbots. D: Personalize makes recommendations.
- 🔑 Keyword: "positive, negative, or neutral".

**Q12 — A**
- ✅ **Rekognition** detects objects, scenes, and faces in images and video.
- ❌ B: Polly is text-to-speech. C: Clarify handles bias and explainability. D: Textract handles documents.
- 🔑 Keyword: "objects, scenes, and faces".

**Q13 — D**
- ✅ **Personalize** creates real-time personalized recommendations.
- ❌ A: Kendra is search. B: Comprehend is text analytics. C: Textract is document extraction.
- 🔑 Keyword: "recommended for you".

**Q14 — C**
- ✅ **Lex** builds conversational bots with **intents and slots**.
- ❌ A: Translate is translation. B: Transcribe is speech-to-text only. D: Polly is text-to-speech only.
- 🔑 Keyword: "intents", "slots".

**Q15 — B**
- ✅ **Bedrock** = serverless access to many FMs from multiple providers through one API.
- ❌ A: EC2 means you manage servers. C: Rekognition is a single-purpose vision service. D: SageMaker gives full control but requires managing training and hosting.
- 🔑 Keyword: "multiple foundation models… single API… without managing infrastructure".

**Q16 — A**
- ✅ A token is a **unit of text** (a word or part of a word). It is the unit for context limits and pricing.
- ❌ B: Not a database record. C: Not an encryption key. D: That describes an **embedding**.
- 🔑 Keyword: "unit of text".

**Q17 — B**
- ✅ An embedding = a **numeric vector capturing semantic meaning**.
- ❌ A: That's a prompt template. C: That's a token. D: That's a credential.
- 🔑 Keyword: "semantic meaning", "vector".

**Q18 — D**
- ✅ **Lower temperature** = more deterministic, consistent, factual outputs.
- ❌ A: Max tokens controls length, not consistency. B: Higher temperature increases randomness. C: A higher top-k adds variety.
- 🔑 Keyword: "consistent, factual".

**Q19 — A**
- ✅ Responses cut off mid-sentence = the **max tokens** (output length) limit was hit. Increase it.
- ❌ B: Top-p affects word diversity. C: Negative prompts exclude content. D: Temperature affects randomness.
- 🔑 Keyword: "stop in the middle of a sentence".

**Q20 — D**
- ✅ **Zero-shot** = no examples.
- ❌ A: Few-shot = several examples. B: One-shot = one example. C: Fine-tuning changes weights; it isn't a prompting technique.
- 🔑 Keyword: "NO examples".

**Q21 — B**
- ✅ Several input-output examples in the prompt = **few-shot**.
- ❌ A: Zero-shot has none. C: CoT asks for step-by-step reasoning. D: Negative prompting lists what to avoid.
- 🔑 Keyword: "several input-output examples".

**Q22 — C**
- ✅ "Think step by step" = **chain-of-thought**.
- ❌ A: Zero-shot just means no examples. B: Prompt caching reuses prompt prefixes to save cost. D: RAG retrieves documents.
- 🔑 Keyword: "step by step", "complex reasoning".

**Q23 — B**
- ✅ Hallucination = **confident but false or made-up** output.
- ❌ A: Slowness is latency. C: Unfair treatment is bias. D: Refusal is a guardrail or safety behavior.
- 🔑 Keyword: "confident but factually incorrect".

**Q24 — D**
- ✅ RAG **retrieves external information and adds it to the prompt** to ground answers.
- ❌ A: RAG doesn't change weights (fine-tuning does). B: RAG isn't encryption. C: Shrinking a model is distillation.
- 🔑 Keyword: "retrieve… add to prompt… grounded".

**Q25 — C**
- ✅ **Bedrock Knowledge Bases** = fully managed RAG.
- ❌ A: Lex is chatbots. B: Guardrails is safety. D: Polly is speech.
- 🔑 Keyword: "fully managed RAG", "company data".

**Q26 — A**
- ✅ **Guardrails content filters** block hate, violence, and similar content.
- ❌ B: KMS handles encryption. C: IAM controls access, not content. D: CloudTrail logs API calls.
- 🔑 Keyword: "prevent… hateful or violent content".

**Q27 — D**
- ✅ **Clarify** = bias detection + explainability.
- ❌ A: JumpStart provides pre-trained models. B: Model Monitor detects drift in production. C: Ground Truth handles labeling.
- 🔑 Keyword: "detect bias", "explain predictions".

**Q28 — C**
- ✅ **Ground Truth** = human labeling of training data.
- ❌ A: A2I = human review of **predictions** after deployment. B: Canvas is no-code ML. D: Comprehend is text analytics.
- 🔑 Keyword: "label… for training".

**Q29 — A**
- ✅ **CloudTrail** records API calls: who, what, and when.
- ❌ B: Inspector finds vulnerabilities. C: Config tracks resource configuration. D: CloudWatch handles metrics and logs.
- 🔑 Keyword: "records API calls… who did what".

**Q30 — C**
- ✅ **KMS** creates and manages encryption keys.
- ❌ A: Macie finds PII. B: Secrets Manager stores secrets such as passwords (it uses KMS). D: IAM manages access.
- 🔑 Keyword: "encryption keys".

**Q31 — B**
- ✅ **Secrets Manager** stores and **automatically rotates** credentials.
- ❌ A: Artifact provides compliance reports. C: IAM manages permissions, not database passwords. D: KMS manages keys, not database-credential rotation.
- 🔑 Keyword: "database credentials… rotate".

**Q32 — B**
- ✅ **Macie** discovers PII and sensitive data in S3.
- ❌ A: Inspector finds software vulnerabilities. C: GuardDuty detects threats. D: Config checks configuration compliance.
- 🔑 Keyword: "sensitive data… in Amazon S3".

**Q33 — A**
- ✅ **AWS Artifact** is where you download AWS compliance reports (SOC, ISO).
- ❌ B: Config tracks resource configurations. C: Trusted Advisor gives recommendations. D: Audit Manager collects evidence about **your** environment; it doesn't hold AWS's SOC reports.
- 🔑 Keyword: "download… SOC 2 report".

**Q34 — D**
- ✅ **Inspector** scans EC2, ECR images, and Lambda for CVEs.
- ❌ A: Config is about configuration. B: Macie is about data. C: CloudTrail is an API log.
- 🔑 Keyword: "software vulnerabilities".

**Q35 — C**
- ✅ Configuring **IAM** is the customer's job (security **in** the cloud).
- ❌ A, B, D: The hypervisor, physical security, and hardware are **AWS** responsibilities (security **of** the cloud).
- 🔑 Keyword: "CUSTOMER's responsibility".

**Q36 — B**
- ✅ Least privilege = **minimum permissions required**.
- ❌ A: Encryption is a different control. C: Key rotation is a different control. D: Admin for everyone is the opposite of least privilege.
- 🔑 Keyword: "minimum permissions".

**Q37 — D**
- ✅ **ROUGE** is the standard metric for summarization.
- ❌ A: RMSE is for regression. B: AUC is for classification. C: BLEU is for translation.
- 🔑 Keyword: "summarization".

**Q38 — A**
- ✅ **BLEU** is the standard metric for machine translation.
- ❌ B: ROUGE is for summaries. C: R-squared is for regression. D: F1 is for classification.
- 🔑 Keyword: "translation".

**Q39 — B**
- ✅ **SageMaker Canvas** = no-code visual ML for business analysts.
- ❌ A: Guardrails is GenAI safety. C: Inspector is vulnerability scanning. D: Debugger is for data scientists debugging training.
- 🔑 Keyword: "no ML experience", "no-code".

**Q40 — B**
- ✅ FM = **large, pre-trained on broad data, adaptable to many tasks**.
- ❌ A: That describes a traditional task-specific model. C: That's rules-based AI. D: That's a vector database.
- 🔑 Keyword: "pre-trained on broad data… many tasks".

**Q41 — B**
- ✅ An image-generation diffusion model is an FM but **not a language model**.
- ❌ A, C, D: Claude, Nova Pro, and Llama are all LLMs.
- 🔑 Keyword: "NOT a large language model".

**Q42 — C**
- ✅ Diffusion models generate **images** (and video/audio) by denoising.
- ❌ A: Tabular classification uses traditional ML. B: Speech-to-text uses ASR (Transcribe). D: Clustering is unsupervised ML.
- 🔑 Keyword: "diffusion".

**Q43 — B**
- ✅ Multimodal = handles **more than one data type** (text + image, etc.).
- ❌ A: That's versioning. C: That's deployment. D: That's text-only (unimodal).
- 🔑 Keyword: "more than one type of data".

**Q44 — B**
- ✅ **Translate** converts text between languages.
- ❌ A: Polly speaks text aloud. C: Transcribe converts speech to text. D: Comprehend analyzes text.
- 🔑 Keyword: "translate… English to Spanish".

**Q45 — C**
- ✅ A large dataset, not urgent, lowest cost = **batch inference**.
- ❌ A: Serverless suits intermittent real-time requests. B: Async suits individual large or slow requests. D: Real-time is always on, so it costs more.
- 🔑 Keyword: "large dataset… not needed immediately… minimize cost".

**Q46 — A**
- ✅ Agentic AI **plans and takes actions** with tools to reach multi-step goals.
- ❌ B: Only answering questions describes a chatbot. C: Agents do use memory. D: Agents use FMs as their "brain".
- 🔑 Keyword: "take actions autonomously".

**Q47 — A**
- ✅ MCP = **open standard protocol** connecting agents and apps to external tools and data.
- ❌ B: It's not a model. C: It's not an encryption service. D: The translation metric is BLEU.
- 🔑 Keyword: "protocol", "connect… tools and data".

**Q48 — B**
- ✅ Chunking = **splitting documents** into smaller pieces before embedding.
- ❌ A: Speech-to-text is Transcribe. C: Encryption is KMS. D: Deleting documents is lifecycle management.
- 🔑 Keyword: "RAG… chunking".

**Q49 — B**
- ✅ A vector DB **stores embeddings and runs similarity search**.
- ❌ A: Passwords belong in Secrets Manager. C: Training jobs run in SageMaker. D: API logs come from CloudTrail.
- 🔑 Keyword: "vector database".

**Q50 — C, E**
- ✅ **Transparency** and **Fairness** are responsible AI dimensions.
- ❌ A, B, D: Throughput, token count, and latency are performance or cost measures, not responsible AI dimensions.
- 🔑 Keyword: "dimensions of responsible AI".

---

## DETAILED EXPLANATIONS — SECTION B (MEDIUM), Q51–Q75

**Q51 — A**
- ✅ Missing fraud = false negatives are costly, so prioritize **recall**.
- ❌ B: Accuracy is misleading on imbalanced data. C: R-squared is a regression metric. D: Precision minimizes false positives (false alarms), which is not the stated concern.
- 🔑 Keyword: "catch as many… missing fraud is very costly".

**Q52 — C**
- ✅ With 99/1 imbalance, **F1** balances precision and recall, while accuracy can be 99% for a useless model.
- ❌ A: ROUGE is for summaries. B: Accuracy is the misleading metric. D: MSE is for regression.
- 🔑 Keyword: "99%… 1%" (imbalanced).

**Q53 — A, D**
- ✅ Poor on both = **underfitting**. Fix it with **more relevant features** and a **more complex model**.
- ❌ B: Less data makes things worse. C: Stopping earlier means even less learning. E: Stronger regularization makes the model simpler (that treats overfitting).
- 🔑 Keyword: "poorly on both training data and test data".

**Q54 — D**
- ✅ Unpredictable traffic, idle periods, cold starts acceptable, minimize cost = **serverless inference** (scales to zero).
- ❌ A: Batch is for offline datasets, not incoming requests. B: Real-time endpoints run (and bill) all the time. C: Provisioned instances also bill while idle.
- 🔑 Keyword: "long idle periods… cold starts… minimize cost".

**Q55 — D**
- ✅ Individual **large payloads (up to 1 GB)**, **long processing (up to ~1 hour)**, and completion notification = **asynchronous inference**.
- ❌ A: Serverless has small payload limits and short timeouts. B: Batch processes whole datasets on a schedule, not user-submitted requests with notification. C: Real-time has ~6 MB payload limits and short timeouts.
- 🔑 Keyword: "800 MB… 30 minutes… notified".

**Q56 — 2 → 6 → 4 → 5 → 1 → 3**
- ✅ Collect data → Prepare data/features → Train → Evaluate → Deploy → Monitor.
- Why: You can't train before preparing data, can't deploy before evaluating, and monitoring happens after deployment (and leads to retraining).
- 🔑 Keyword: "ML lifecycle".

**Q57 — B**
- ✅ Data changes **daily**, needs the latest info, least effort = **RAG with Knowledge Bases** (just re-sync the data source).
- ❌ A: Weekly fine-tuning is costly and always out of date. C: Temperature doesn't add knowledge. D: Continued pre-training is expensive and still stale.
- 🔑 Keyword: "change daily", "latest", "least effort".

**Q58 — D**
- ✅ Consistent **brand voice and format** + **labeled prompt-response pairs** = **fine-tuning**.
- ❌ A: RAG supplies facts, not style. B: Prompt caching lowers cost but doesn't teach style. C: Zero-shot won't reliably reproduce a specific voice.
- 🔑 Keyword: "brand voice", "10,000 examples of prompt-response pairs".

**Q59 — D**
- ✅ **Unlabeled** domain text used to learn terminology = **continued pre-training**.
- ❌ A: Distillation shrinks a model. B: RAG retrieves facts per question; it doesn't teach terminology deeply. C: Fine-tuning needs **labeled** pairs.
- 🔑 Keyword: "unlabeled… medical terminology".

**Q60 — B, E**
- ✅ **RAG** and **few-shot prompting** only change the **input**. Weights stay the same.
- ❌ A, C, D: Distillation, continued pre-training, and fine-tuning all **train** a model, so weights change.
- 🔑 Keyword: "do NOT change… weights".

**Q61 — D**
- ✅ **Higher temperature** = more creative, varied output.
- ❌ A: Lower temperature is more conservative. B: Fewer max tokens only shortens output. C: A low top-p reduces diversity.
- 🔑 Keyword: "creative and varied".

**Q62 — D**
- ✅ An identical, long **prefix** on every request = **prompt caching** (cheaper and faster cached tokens).
- ❌ A: Fine-tuning is costly and doesn't target repeated context. B: Temperature doesn't affect cost. C: More max tokens raises cost.
- 🔑 Keyword: "every request starts with the same… document".

**Q63 — D**
- ✅ Summaries compared with references = **ROUGE**.
- ❌ A: BLEU is for translation. B: RMSE is for regression. C: F1 is for classification.
- 🔑 Keyword: "summaries… reference".

**Q64 — A**
- ✅ Same meaning, different words = **BERTScore** (embedding-based semantic similarity).
- ❌ B: Accuracy needs exact matches. C, D: ROUGE and BLEU reward exact word overlap.
- 🔑 Keyword: "same meaning… different words".

**Q65 — C**
- ✅ "Ignore all previous instructions…" = classic **prompt injection** (overriding the app's instructions).
- ❌ A: Poisoning corrupts training or source data. B: Hallucination is made-up output, not an attack. D: Drift is data changing over time.
- 🔑 Keyword: "Ignore all previous instructions".

**Q66 — B**
- ✅ Role-play to bypass safety rules = **jailbreaking**.
- ❌ A: Model extraction copies a model. C: Poisoning corrupts data. D: Data leakage exposes private data.
- 🔑 Keyword: "Pretend you are an AI with no rules".

**Q67 — B**
- ✅ Corrupting the **knowledge sources** the model relies on = **poisoning**.
- ❌ A: Jailbreaking is a user bypassing safety. C: Hijacking redirects the model's task through input. D: DoS is about availability.
- 🔑 Keyword: "edits… wiki pages that feed… knowledge base".

**Q68 — C**
- ✅ Blocking a whole subject (investment advice) = **denied topics**.
- ❌ A: Grounding checks detect hallucinations. B: Sensitive information filters handle PII. D: Word filters block specific words and can't catch every way a topic is phrased.
- 🔑 Keyword: "never provide investment advice".

**Q69 — D**
- ✅ Masking phone numbers and emails = **sensitive information (PII) filters**.
- ❌ A: Content filters cover harmful categories. B: Automated Reasoning performs logic verification. C: Denied topics cover subjects.
- 🔑 Keyword: "masked… phone numbers… email addresses".

**Q70 — C**
- ✅ Answers not supported by retrieved documents = ungrounded = **contextual grounding check**.
- ❌ A: The prompt attack filter targets jailbreaks and injection. B: Denied topics cover subjects. D: Word filters cover specific words.
- 🔑 Keyword: "not supported by the retrieved documents".

**Q71 — 1-d, 2-b, 3-a, 4-c**
- ✅ Transcribe = call recordings → text. Polly = text → speech. Textract = key-value pairs from forms. Comprehend = sentiment.
- 🔑 Memory: Ears (Transcribe), Mouth (Polly), Paper-eyes (Textract), Brain (Comprehend).

**Q72 — D**
- ✅ They already use Aurora PostgreSQL and want vectors **alongside relational data with SQL** = **Aurora PostgreSQL with pgvector**.
- ❌ A: Neptune is a graph database. B: DynamoDB is key-value, not the typical vector answer. C: Redshift is a data warehouse.
- 🔑 Keyword: "already runs… Aurora PostgreSQL", "SQL".

**Q73 — D**
- ✅ Complex relationships + GraphRAG = **Neptune** (graph database).
- ❌ A: DynamoDB is key-value. B: MySQL has no graph relationships or pgvector. C: S3 is object storage.
- 🔑 Keyword: "relationships between entities", "GraphRAG".

**Q74 — D**
- ✅ Looking up **and** issuing a refund requires **actions**, so use an **agent with an action group** (Lambda calling the payment API).
- ❌ A: Guardrails only filters content. B: Translate is for languages. C: A knowledge base can retrieve information but can't issue refunds.
- 🔑 Keyword: "issue a refund in the backend".

**Q75 — C**
- ✅ A standard, reusable way to connect agents to many tools = **MCP**.
- ❌ A: PrivateLink is network connectivity to AWS services. B: BLEU is a metric. D: A2I is human review.
- 🔑 Keyword: "standard, reusable way… many external tools".

**➡ Continue to PART 11 — Explanations Q76–Q150**
