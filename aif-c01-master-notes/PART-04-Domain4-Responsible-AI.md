# PART 4 — AIF-C01 MASTER NOTES

# DOMAIN 4 — GUIDELINES FOR RESPONSIBLE AI (14%)

The guide has two task statements:
- **4.1** Explain the development of AI systems that are responsible
- **4.2** Recognize the importance of transparent and explainable models

---

## 4.0 RESPONSIBLE AI — THE BIG PICTURE

### Responsible AI
- **Simple meaning:** Building and using AI in a way that is **fair, safe, honest, private, and accountable**, so it helps people and doesn't harm them.
- **Technical meaning:** A set of principles and practices applied across the whole AI lifecycle (design → data → training → evaluation → deployment → monitoring) to manage risks such as bias, harmful content, privacy violations, lack of transparency, and misuse.
- **AWS's core dimensions of responsible AI (MEMORIZE):**
  | Dimension | Simple meaning |
  |---|---|
  | **Fairness** | Treats all groups of people equitably |
  | **Explainability** | Humans can understand why the model gave an output |
  | **Privacy & security** | Data is protected and used appropriately |
  | **Safety** | Prevents harmful outputs and misuse |
  | **Controllability** | Humans can monitor and steer the AI's behavior |
  | **Veracity & robustness** | Correct outputs, even with unexpected or adversarial inputs |
  | **Governance** | Policies, processes, and accountability across the AI lifecycle |
  | **Transparency** | Stakeholders know how the AI works, its limits, and when they're interacting with AI |
- **Memory trick:** **"FEPS-CVGT" → "Friendly Engineers Protect Society; Careful Validation Guarantees Trust."**
- **AWS tools for responsible AI (MEMORIZE):**
  | Tool | Responsible AI job |
  |---|---|
  | **Amazon Bedrock Guardrails** | Safety filters for GenAI inputs/outputs (harmful content, PII, topics, prompt attacks, hallucination/grounding) |
  | **SageMaker Clarify** | Detect **bias** in data/models + **explainability** (feature importance); also FM evaluation |
  | **SageMaker Model Monitor** | Monitor for drift, including **bias drift** in production |
  | **Amazon Augmented AI (A2I)** | **Human review** of ML predictions (human oversight) |
  | **SageMaker Model Cards** | **Document** a model's intended use, risks, training details, and evaluation (transparency/governance) |
  | **AWS AI Service Cards** | AWS's own **transparency documentation** for its AI services (intended use, limitations, responsible AI design) |
  | **Bedrock Model Evaluation** | Evaluate FMs for accuracy, robustness, **toxicity**, plus human evaluation |
  | **SageMaker Ground Truth** | Human labeling / human feedback (RLHF data) |
  | **Watermarking** (Amazon Nova Canvas/Titan Image) | Invisible watermarks / content credentials to identify AI-generated images (transparency) |

---

## 4.1 RESPONSIBLE AI FEATURES

### 4.1.1 Bias
- **Simple meaning:** The AI unfairly favors or disfavors certain groups of people.
- **Technical meaning:** Systematic, unfair differences in model outputs across groups. It is usually caused by **non-representative, imbalanced, or historically biased training data**, labeling bias, or design choices.
- **Types to recognize:**
  - **Sampling/representation bias:** some groups are under-represented in the data (e.g., few older people's photos)
  - **Historical bias:** the data reflects past unfair decisions (e.g., past hiring favored one gender)
  - **Measurement/label bias:** inaccurate or subjective labels
  - **Confirmation/automation bias:** humans over-trust the AI's output
- **Real-world example:** A hiring model trained on 10 years of mostly-male hires ranks female candidates lower.
- **AWS example:** **SageMaker Clarify**: **pre-training bias** metrics (in the data, e.g., class imbalance) and **post-training bias** metrics (in the predictions); **Model Monitor** for bias drift.
- **Exam keyword:** "unfair outcomes for a group", "underrepresented", "demographic", "skewed data"
- **Common confusion:** Bias vs hallucination (unfair vs made-up); ethical bias vs statistical bias (underfitting).
- **Exam trap:** The first fix for data bias is **more diverse, balanced, representative data** (plus detection with Clarify), not "a bigger model".
- **Memory trick:** **Bias = a tilted scale.**

### 4.1.2 Fairness
- **Simple meaning:** Everyone gets equally good treatment from the AI.
- **Technical meaning:** Model outcomes don't unjustly discriminate across demographic groups. It is measured with fairness/bias metrics (e.g., difference in positive-prediction rates between groups).
- **AWS:** Clarify bias metrics; diverse datasets; human review.
- **Keyword:** "equitable", "equal treatment", "non-discriminatory"
- **Memory trick:** **Fair = same rules, same quality for all.**

### 4.1.3 Inclusivity
- **Simple meaning:** The AI works well for **all kinds of people**: different languages, accents, abilities, ages, cultures.
- **Technical meaning:** Designing data, models, and interfaces to represent and serve diverse users, including people with disabilities and minority groups.
- **Example:** A voice assistant that understands many accents; a model trained with diverse skin tones.
- **Keyword:** "diverse users", "accessibility", "all accents/languages"
- **Memory trick:** **Inclusive = nobody left out.**

### 4.1.4 Robustness
- **Simple meaning:** The AI keeps working correctly even with **unusual, noisy, or tricky inputs**.
- **Technical meaning:** Reliability and consistent performance under unexpected conditions, edge cases, noisy data, distribution shifts, and **adversarial inputs** (e.g., prompt attacks, typos).
- **AWS:** Bedrock Model Evaluation measures **robustness** (e.g., performance when prompts have small perturbations like typos); Guardrails for adversarial prompts.
- **Keyword:** "consistent under unexpected inputs", "typos", "adversarial"
- **Memory trick:** **Robust = sturdy.**

### 4.1.5 Safety
- **Simple meaning:** The AI doesn't produce harmful content or cause harm.
- **Technical meaning:** Preventing harmful outputs (violence, hate, self-harm, illegal advice, dangerous instructions) and misuse. It is enforced through alignment, filters, guardrails, human oversight, and testing (**red teaming** = deliberately attacking your own system to find weaknesses).
- **AWS:** **Bedrock Guardrails** (content filters, denied topics), evaluation for toxicity.
- **Keyword:** "harmful content", "unsafe responses", "protect users"
- **Memory trick:** **Safety = seatbelt for AI.**

### 4.1.6 Veracity
- **Simple meaning:** The AI tells the **truth**: outputs are accurate and factual.
- **Technical meaning:** The correctness and truthfulness of model outputs. It is threatened by **hallucinations** and outdated knowledge, and improved with **RAG/grounding, contextual grounding checks, Automated Reasoning checks**, and human verification.
- **Keyword:** "truthful", "accurate", "factually correct"
- **Memory trick:** **Veracity = Verified truth** (like "verify").

### 4.1.7 Controllability
- **Simple meaning:** Humans can steer and correct the AI's behavior.
- **Technical meaning:** Mechanisms to monitor and guide AI behavior: guardrails, parameters, policies, human approvals, kill switches.

### 4.1.8 Privacy & security
- Protect personal/sensitive data: minimize data, mask PII (Guardrails), encrypt (KMS), control access (IAM), discover sensitive data (Macie). Details in Part 5.

### 4.1.9 Governance
- Policies, roles, accountability, documentation (Model Cards), audits, and review boards across the AI lifecycle. Details in Part 5.

---

## 4.2 RESPONSIBLE MODEL SELECTION & DATA

### 4.2.1 Selecting a model responsibly
- Consider **bias, safety, and transparency documentation** (model cards, AI Service Cards), **licensing/IP terms**, **environmental impact**, and whether the model's intended use matches yours.
- Evaluate models on **your own** data for fairness, toxicity, and robustness (Bedrock Model Evaluation, Clarify).

### 4.2.2 Environmental considerations & sustainability
- **Simple meaning:** Training and running big AI models uses lots of electricity. Choose options that waste less energy.
- **Technical meaning:** Consider the energy/carbon footprint of training and inference. Reduce it by:
  - **Reusing pre-trained FMs** instead of training from scratch
  - Choosing **smaller/efficient models** (or **distillation**) that meet requirements
  - Using **efficient hardware**: **AWS Trainium** (training chips), **AWS Inferentia** (inference chips), **Graviton** (efficient CPUs)
  - Right-sizing instances, **serverless / auto-scaling** (no idle resources), batch processing
  - Choosing Regions powered by more renewable energy
  - Prompt caching, shorter prompts/outputs
- **AWS:** **AWS Customer Carbon Footprint Tool** (see emissions), Well-Architected **Sustainability Pillar**.
- **Keyword:** "reduce environmental impact", "energy efficient", "carbon footprint", "sustainable"
- **Exam trap:** "Most sustainable way to add GenAI to a product" → **use an existing FM (don't pre-train)**, pick a smaller efficient model.
- **Memory trick:** **Green AI = Reuse, Right-size, Efficient chips.**

### 4.2.3 Legal risks of GenAI (MEMORIZE)
| Risk | Meaning | Example / mitigation |
|---|---|---|
| **Intellectual property (IP) infringement** | Generated content may copy/resemble copyrighted or trademarked material; unclear ownership of outputs | Model trained on copyrighted art produces a near-copy. Mitigation: review outputs, use providers offering **IP indemnity** (e.g., AWS uncapped IP indemnity for Amazon Nova/Titan outputs), clear policies, filters |
| **Biased model outputs** | Discriminatory outputs → legal liability (anti-discrimination laws) | Biased loan/hiring decisions. Mitigation: Clarify, diverse data, human review |
| **Loss of customer trust** | Users stop trusting the brand after wrong, harmful, or offensive outputs | Chatbot insults a customer. Mitigation: Guardrails, testing, transparency |
| **End-user risk** | Users are harmed by relying on wrong outputs | Wrong medical/financial advice. Mitigation: disclaimers, human oversight, grounding |
| **Hallucinations** | False info causes legal/reputational damage | Chatbot invents a refund policy that the company must honor. Mitigation: RAG + grounding checks |
| **Privacy violations** | PII exposed | Guardrails PII filters, Macie |

- **Exam keyword:** "copyright", "trademark", "ownership of generated content", "reputational damage", "liability"

### 4.2.4 Characteristics of good datasets (from the guide)
| Characteristic | Meaning |
|---|---|
| **Inclusivity** | Represents all relevant groups |
| **Diversity** | Covers varied scenarios, demographics, edge cases |
| **Curated data sources** | From trusted, vetted, authorized sources |
| **Balanced datasets** | No group/class heavily over- or under-represented |
| **Accuracy/quality** | Correct labels, cleaned, deduplicated |
| **Privacy-respecting** | Consent obtained, PII protected |
| **Relevance / timeliness** | Matches the use case and is up to date |

- **Exam trap:** "Model performs worse for a minority group" → the **dataset lacks inclusivity/balance**.

### 4.2.5 Effects of bias and variance (from the guide)
- **Effects on demographic groups:** unfair outcomes, discrimination
- **Inaccuracy:** wrong predictions
- **Overfitting (high variance)** & **underfitting (high bias)** (see Part 1)

### 4.2.6 Tools to detect & monitor bias, trustworthiness, truthfulness
| Need | Tool/approach |
|---|---|
| Analyze label quality | Human audits, **SageMaker Ground Truth** review workflows |
| Detect bias in data/model | **SageMaker Clarify** |
| Monitor bias drift in production | **SageMaker Model Monitor** (with Clarify) |
| Human review of predictions | **Amazon A2I** |
| Subgroup analysis | Compare metrics per demographic subgroup (Clarify) |
| Filter harmful GenAI content | **Bedrock Guardrails** |
| Detect hallucinations | **Guardrails contextual grounding check**, **Automated Reasoning checks**, RAG evaluation, LLM-as-a-judge |
| Evaluate toxicity/robustness | **Bedrock Model Evaluation** |

### IF THE QUESTION SAYS… → THINK…
102. "Detect bias in training data before training" → **SageMaker Clarify (pre-training bias metrics)**
103. "Monitor a deployed model for bias drift over time" → **SageMaker Model Monitor (+ Clarify)**
104. "Reduce the environmental impact of an AI solution" → **Use pre-trained FM, smaller/efficient model, Inferentia/Trainium, serverless**
105. "Generated image closely resembles a copyrighted artwork" → **Intellectual property risk**
106. "Chatbot gave wrong policy info; customers stopped trusting the company" → **Loss of customer trust (from hallucination)**

---

## 4.3 AMAZON BEDROCK GUARDRAILS (DEEP DIVE, VERY IMPORTANT)

### What it is
- **Simple meaning:** A **safety filter** that sits around your GenAI app. It checks **what users send in** and **what the model sends out**, and blocks or masks anything harmful, off-topic, private, or made-up, based on rules you set.
- **Technical meaning:** A Bedrock capability to implement **customizable safeguards** for GenAI applications according to your use cases and **responsible AI policies**. Guardrails evaluate **user inputs (prompts)** and **model responses** and **block, mask, or flag** content. It works with **any FM in Bedrock**, and through the **`ApplyGuardrail` API** it also works with models **outside Bedrock** (self-hosted or third-party). It can be attached to Bedrock **Agents** and **Knowledge Bases**.

### The Guardrails policies (MEMORIZE ALL)

| Policy | What it does | Example |
|---|---|---|
| **1. Content filters** | Detect & block harmful content categories with adjustable strength (none/low/medium/high): **Hate, Insults, Sexual, Violence, Misconduct**, and **Prompt Attack** (jailbreak/prompt injection detection). Works on **text and images** | Block violent or hateful language in a teen education app |
| **2. Denied topics** | Define topics the app must **not discuss** (described in natural language + examples) | Bank chatbot must not give **investment advice**; airline bot must not discuss politics |
| **3. Word filters** | Block specific **words/phrases**: custom lists (competitor names) + a built-in **profanity** filter | Block competitor product names, profanity |
| **4. Sensitive information filters** | Detect **PII** (names, emails, phone numbers, SSNs, credit card numbers, etc.) and **custom regex** patterns → **BLOCK** or **MASK (redact/anonymize)** in inputs and outputs | Mask customer phone numbers in call summaries |
| **5. Contextual grounding check** | Detects **hallucinations** in responses by checking **grounding** (is the response supported by the source/reference context?) and **relevance** (does it answer the user's query?), using score thresholds | RAG chatbot: block answers not supported by the retrieved documents |
| **6. Automated Reasoning checks** | Uses **formal logic/mathematical verification** against policies you define to validate that responses are **factually correct and consistent** with rules, and explains why | Verify HR-policy answers ("employees with 2+ years get 15 days leave") are logically correct |

- **Custom blocked messages:** you define what the user sees when content is blocked ("Sorry, I can't help with that.").
- **Tiers / other:** content filters support multiple languages; image content filtering; guardrails can be versioned; CloudWatch metrics and traces show what was blocked (audit).

### How it works (flow)
```
User prompt → [Guardrail checks INPUT] → blocked? → custom message
                     │ passes
                     ▼
                 Foundation Model
                     │
                     ▼
           [Guardrail checks OUTPUT] → blocked/masked? → custom message / redacted text
                     │ passes
                     ▼
                  User sees answer
```

### When an exam question points to Bedrock Guardrails
Choose **Guardrails** when the question says:
- "Prevent the chatbot from generating **harmful, toxic, hateful, violent, or sexual** content"
- "Chatbot must **not discuss a specific topic**" (e.g., legal/medical/investment advice, competitors, politics)
- "**Mask/redact PII** (emails, phone numbers, SSNs) in model responses or user inputs"
- "**Block profanity** or specific words"
- "Detect and block **prompt injection / jailbreak** attempts"
- "**Filter responses not grounded** in the source documents" / "**detect hallucinations** in a RAG app"
- "Enforce **responsible AI policies consistently across multiple FMs/applications**"
- "Apply the **same safety policies to models outside Bedrock**" → `ApplyGuardrail` API
- "Verify responses against business rules with **mathematical/logical** checks" → **Automated Reasoning checks**

### When NOT Guardrails
| Question asks for… | Correct answer (not Guardrails) |
|---|---|
| Who can **access/invoke** a model | **IAM** |
| **Encrypt** data | **KMS** |
| Log **API calls** | **CloudTrail** |
| Find PII **stored in S3** | **Macie** |
| Detect **bias in training data** | **SageMaker Clarify** |
| Human review of predictions | **A2I** |
| Improve factual knowledge | **RAG** |

### Guardrails vs IAM (classic trap)
| | Bedrock Guardrails | IAM |
|---|---|---|
| Controls | **What content** goes in/out of the model | **Who** can access which AWS resources/actions |
| Level | Content/semantic safety | Identity & permissions |
| Example | Block hate speech, mask SSNs | Only the "Support" role may call Bedrock InvokeModel |
| Memory | **Guardrails = WHAT is said** | **IAM = WHO can do it** |

- **Memory trick:** **Guardrails = the bouncer checking what comes in and goes out of the club.**

### IF THE QUESTION SAYS… → THINK…
107. "Prevent harmful or unsafe model responses" → **Bedrock Guardrails (content filters)**
108. "Chatbot must never provide investment/medical advice" → **Guardrails denied topics**
109. "Mask customer PII in chatbot responses" → **Guardrails sensitive information filters**
110. "Detect hallucinated answers not supported by retrieved documents" → **Guardrails contextual grounding check**
111. "Apply consistent safety policies to a model hosted outside Bedrock" → **Guardrails ApplyGuardrail API**
112. "Mathematically verify that answers comply with company policy rules" → **Automated Reasoning checks (Guardrails)**

---

## 4.4 TRANSPARENCY & EXPLAINABILITY (TASK 4.2)

### 4.4.1 Transparency
- **Simple meaning:** Being **open** about how the AI works, what data it used, its limitations, and **telling people when they're dealing with AI**.
- **Technical meaning:** Providing clear information about a model's purpose, design, training data, limitations, performance, and intended use to stakeholders (documentation, disclosures, labeling AI-generated content).
- **AWS:** **SageMaker Model Cards**, **AWS AI Service Cards**, data lineage, watermarking AI-generated images, citations in RAG.
- **Keyword:** "disclose", "document", "users know they are talking to AI", "open about limitations"
- **Memory trick:** **Transparent = glass box of information.**

### 4.4.2 Explainability
- **Simple meaning:** Being able to explain **why** the model gave a particular output, in human terms.
- **Technical meaning:** Methods that describe how inputs influenced a specific output (e.g., **feature importance/attribution** such as **SHAP** values: "income contributed most to the loan denial").
- **AWS:** **SageMaker Clarify** (feature attributions, SHAP, partial dependence plots), RAG **citations** for GenAI.
- **Keyword:** "why did the model make this decision", "which features influenced the prediction"
- **Exam trap:** "Explain to a customer why their loan was denied" → **SageMaker Clarify** (explainability), not Model Monitor.
- **Memory trick:** **Explainability = "Explain the WHY."**

### 4.4.3 Interpretability
- **Simple meaning:** How easily a human can understand **how the model works inside**.
- **Technical meaning:** The degree to which the model's internal mechanics are understandable. **Linear regression and decision trees = highly interpretable** ("white box"). **Deep neural networks and LLMs = low interpretability** ("black box").
- **Keyword:** "inherently understandable model", "white box", "simple model"
- **Common confusion:** **Interpretability = understand the model's inner logic (the whole model). Explainability = explain a specific output (post-hoc).**
- **Exam trap: the tradeoff.** More complex models are often **more accurate/performant** but **less interpretable**. If regulation requires full transparency → a simpler, interpretable model may be better, even with slightly lower accuracy.
- **Memory trick:** **Interpretable = you can read the recipe. Explainable = you can explain the dish.**

### Transparency vs Explainability vs Interpretability

| | Transparency | Explainability | Interpretability |
|---|---|---|---|
| Question | "What is this AI, what data, what limits?" | "Why this specific output?" | "How does the model work inside?" |
| Scope | Whole system & its documentation | Individual predictions | Model's internal mechanics |
| AWS | Model Cards, AI Service Cards | SageMaker Clarify (SHAP) | Choose simple models (linear, trees) |
| Example | Publishing a model card; disclosing AI use | "Income was the top reason for denial" | A decision tree anyone can follow |

### 4.4.4 Tradeoffs: model safety/transparency vs performance
| Choice | Gain | Cost |
|---|---|---|
| Simpler, interpretable model | Transparency, easier audits | May be less accurate |
| Complex model (DL/FM) | Higher accuracy/capability | Black box, harder to explain |
| Strict guardrails | Safety | May block some legitimate responses; slight latency |
| Human review | Oversight, accuracy | Slower, more expensive |

### 4.4.5 Human oversight / human-in-the-loop (HITL)
- **Simple meaning:** A human checks or approves the AI's work, especially for important decisions.
- **Technical meaning:** Integrating human review into AI workflows (e.g., review low-confidence predictions, approve high-risk agent actions, audit samples).
- **AWS:** **Amazon Augmented AI (A2I)** (built-in human review workflows for Textract, Rekognition, or custom models; trigger on low confidence); agent **user confirmation** before actions (Bedrock Agents); Ground Truth.
- **Keyword:** "human review", "low confidence", "high-stakes decisions", "approval before action"
- **Memory trick:** **HITL = Human In The Loop = a co-pilot.**

### 4.4.6 Human-centered AI (human-centered design for explainable AI)
- **Simple meaning:** Design AI **around people's needs**: easy to understand, helpful, respectful, and keeping humans in control.
- **Technical meaning:** Principles for designing AI that **augments** (not replaces) human decision-making, considers user needs and impacts, provides understandable explanations, allows users to contest or correct outputs, and emphasizes accessibility and trust.
- **Examples:** Show confidence levels, give reasons, let users give feedback, allow override.
- **Keyword:** "designed around users", "augment human decisions", "user trust"

### 4.4.7 Decision transparency
- **Simple meaning:** Making it clear **how and why** an AI-driven decision was made, and **that AI was involved**.
- **Technical meaning:** Providing traceable, understandable reasoning for AI-assisted decisions (explanations, citations, logs, documentation), so affected people and auditors can review them.
- **AWS:** Clarify explanations, RAG citations, agent traces, CloudTrail/invocation logs, Model Cards.

### 4.4.8 User feedback
- **Simple meaning:** Letting users rate or comment on AI answers (👍/👎) and using that to improve the system.
- **Technical meaning:** Collecting explicit (ratings, corrections) and implicit (clicks, abandonment) feedback to monitor quality, detect issues (bias, hallucination), and improve prompts, RAG data, or models (e.g., via RLHF/fine-tuning).
- **Keyword:** "continuous improvement", "thumbs up/down", "feedback loop"
- **Exam trap:** Feedback is part of the **FM lifecycle** (the last stage) and supports human-centered AI.

### 4.4.9 Documentation tools
| Tool | Who writes it | What it contains |
|---|---|---|
| **SageMaker Model Cards** | **You** (for your own models) | Intended uses, risk rating, training details, evaluation results, ethical considerations; **immutable versions** for audits |
| **AWS AI Service Cards** | **AWS** (for its AI services, e.g., Rekognition, Textract, Nova, Titan) | Intended use cases, limitations, responsible AI design choices, deployment best practices |
| **Data lineage / provenance** | You | Where data came from, how it was transformed (source citation) |
- **Exam trap:** "Document **your** model's intended use and risk for auditors" → **SageMaker Model Cards**. "Learn about responsible use & limitations of an **AWS** AI service" → **AWS AI Service Cards**.

### IF THE QUESTION SAYS… → THINK…
113. "Explain which features most influenced a model's prediction" → **SageMaker Clarify (explainability, SHAP)**
114. "Document intended use, risks, and evaluation of a model for governance" → **SageMaker Model Cards**
115. "Understand intended use and limitations of an AWS AI service" → **AWS AI Service Cards**
116. "Humans must review predictions with low confidence scores" → **Amazon Augmented AI (A2I)**
117. "Regulation requires a model whose logic is easy to understand" → **Interpretable model (e.g., decision tree/linear), accepting a possible accuracy tradeoff**
118. "Users should know content was AI-generated" → **Transparency (disclosure, watermarking)**

---

## 4.5 HALLUCINATIONS IN RESPONSIBLE AI (RECAP)
- **Why it matters:** Hallucinations harm **veracity**, create **end-user risk**, **legal liability**, and **loss of customer trust**.
- **Mitigations (memorize the list):**
  1. **RAG** (ground in trusted data) + citations
  2. **Guardrails contextual grounding check**
  3. **Automated Reasoning checks**
  4. **Lower temperature**
  5. Prompt instructions ("answer only from the provided context; otherwise say you don't know")
  6. **Human review** (A2I) for high-stakes outputs
  7. **Evaluation** (LLM-as-a-judge, RAG faithfulness)
  8. User feedback + monitoring

### Hallucination vs Bias vs Toxicity
| | Hallucination | Bias | Toxicity |
|---|---|---|---|
| Problem | **False/made-up** facts | **Unfair** treatment of groups | **Offensive/harmful** language |
| Cause | Probabilistic generation, missing knowledge | Skewed data | Harmful training content, prompts |
| Fix | RAG, grounding check, low temperature | Diverse data, Clarify | Guardrails content filters |

---

## DOMAIN 4 — FAST RECAP
- Responsible AI dimensions: Fairness, Explainability, Privacy & security, Safety, Controllability, Veracity & robustness, Governance, Transparency.
- Bias → Clarify (detect), Model Monitor (drift), diverse/balanced data (fix).
- Guardrails = content filters (incl. prompt attacks), denied topics, word filters, PII filters (block/mask), contextual grounding check, Automated Reasoning. Works on inputs AND outputs, any model (ApplyGuardrail).
- Explainability = why this output (Clarify/SHAP). Interpretability = understand the model's internals (simple models). Transparency = disclose & document (Model Cards, AI Service Cards).
- Human oversight = A2I. Human-centered AI = design around people; feedback loops.
- Legal risks: IP, biased outputs, loss of trust, end-user risk, hallucinations.
- Sustainability: reuse FMs, smaller models, Inferentia/Trainium, serverless, right-size.

**➡ Continue to PART 5 — Domain 5: Security, Compliance, and Governance for AI Solutions**
