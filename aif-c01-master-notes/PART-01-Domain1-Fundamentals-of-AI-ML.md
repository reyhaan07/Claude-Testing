# PART 1 — AIF-C01 MASTER NOTES

## AWS Certified AI Practitioner (AIF-C01) — Exam Guide v1.1 (2026)

> **How to use these notes:** Read each concept once. Focus on **Exam keyword**, **Exam trap**, and **Memory trick**. Those three lines are what win points on exam day.

---

## 0. EXAM FACTS (KNOW THESE BEFORE YOU START)

| Item | Detail |
|---|---|
| Exam code | AIF-C01 (Foundational level) |
| Questions | 65 total: **50 scored + 15 unscored**. You cannot tell which ones are unscored. |
| Time | 90 minutes |
| Passing score | **700 out of 1000** (scaled score) |
| Question types | Multiple choice (1 correct answer), Multiple response (2+ correct answers), **Ordering** (put steps in order), **Matching** (match items to descriptions) |
| Penalty for guessing | **None. Never leave a question blank.** |
| Guide version | v1.1 (updated April 30, 2026). It adds agentic AI, MCP, context engineering, token pricing, distillation, Prompt Management, grounding/hallucination detection, audit logging, and AgentCore Identity/Policy. |

### Domain weights

| Domain | Weight | Approx. scored questions |
|---|---|---|
| 1. Fundamentals of AI and ML | 20% | ~10 |
| 2. Fundamentals of Generative AI | 24% | ~12 |
| 3. Applications of Foundation Models | **28%** | ~14 |
| 4. Guidelines for Responsible AI | 14% | ~7 |
| 5. Security, Compliance, and Governance for AI Solutions | 14% | ~7 |

**Domains 2 + 3 = 52%.** If you are short on time, master those first.

### What the exam does NOT test (LOW PRIORITY / OUT OF SCOPE)
- Writing code, building ML pipelines by hand, or tuning hyperparameters yourself
- Math formulas (backpropagation, gradient math, loss function derivations)
- Deep architecture details (number of layers, attention equations)
- Building data pipelines or infrastructure in detail

The exam tests whether you **understand concepts** and can **pick the right AWS service or approach for a business scenario**.

---

# DOMAIN 1 — FUNDAMENTALS OF AI AND ML (20%)

The guide has three task statements:
- **1.1** Explain basic AI concepts and terminology
- **1.2** Identify practical use cases for AI
- **1.3** Describe the ML development lifecycle

---

## 1.1 CORE AI TERMS

### 1.1.1 Artificial Intelligence (AI)
- **Simple meaning:** Making computers do things that normally need human intelligence, like understanding language, recognizing faces, or making decisions.
- **Technical meaning:** The broad field of computer science that builds systems able to perform tasks that normally require human intelligence (perception, reasoning, learning, problem-solving). It is the **umbrella term** that covers ML, deep learning, and generative AI.
- **Real-world example:** A spam filter, a voice assistant, a self-driving car, a chess program.
- **AWS example:** Every AWS AI service (Rekognition, Comprehend, Bedrock) is an AI service.
- **Exam keyword:** "mimic human intelligence", "broad field", "umbrella"
- **Common confusion:** People use "AI" and "ML" as if they mean the same thing. ML is only **one way** to build AI. A rule-based system (if/else) is AI but NOT ML.
- **Exam trap:** A question describes a system with hard-coded rules and asks if it is ML. It is **not ML**, because it doesn't learn from data. It can still be called AI.
- **Memory trick:** **AI = the whole ocean.** ML, DL, and GenAI are fish inside it.

### 1.1.2 Machine Learning (ML)
- **Simple meaning:** Instead of writing rules, you show the computer many examples and it **learns the pattern** by itself.
- **Technical meaning:** A subset of AI where algorithms learn patterns from data to make predictions or decisions **without being explicitly programmed** with rules.
- **Real-world example:** Show a model 10,000 past house sales and it learns to predict the price of a new house.
- **AWS example:** Amazon SageMaker AI (build, train, and deploy your own ML models).
- **Exam keyword:** "learn from data", "patterns", "predict", "without explicit programming"
- **Common confusion:** ML ≠ deep learning. Many ML models (like decision trees and linear regression) are simple and are not neural networks.
- **Exam trap:** "The company has historical labeled data and wants to predict a number/category" → that's classic ML. It doesn't need GenAI.
- **Memory trick:** **ML = Learn from Examples, not from Rules.**

### 1.1.3 Deep Learning (DL)
- **Simple meaning:** A type of ML that uses big, layered "brain-like" networks. It is very good at messy data like images, audio, and text.
- **Technical meaning:** A subset of ML that uses **neural networks with many layers** ("deep") to learn complex patterns automatically from large amounts of (often unstructured) data.
- **Real-world example:** Face recognition on your phone; speech-to-text.
- **AWS example:** Amazon Rekognition (image analysis) and Amazon Transcribe (speech-to-text) use deep learning under the hood.
- **Exam keyword:** "many layers", "neural network", "unstructured data (images, audio, text)", "large amounts of data", "high compute (GPUs)"
- **Common confusion:** Deep learning vs neural network. A **neural network** is the structure. **Deep learning** means using neural networks that have *many* layers.
- **Exam trap:** DL needs **lots of data and compute**. If the question says "small tabular dataset, needs explainability", deep learning is usually the WRONG choice. Pick a simpler ML model.
- **Memory trick:** **Deep = many layers deep.**

### 1.1.4 Neural Networks
- **Simple meaning:** A computer structure loosely inspired by the brain. Many small "neurons" are connected in layers and pass numbers to each other.
- **Technical meaning:** A model made of interconnected nodes (neurons) organized in an **input layer, hidden layer(s), and an output layer**. Each connection has a **weight** (a number that is adjusted during training).
- **Real-world example:** Recognizing handwritten digits (0–9).
- **AWS example:** Models you train in SageMaker AI; the FMs in Bedrock are huge neural networks.
- **Exam keyword:** "layers", "nodes/neurons", "weights", "input / hidden / output"
- **Common confusion:** Neural network = the **architecture**. Deep learning = the **approach** of using deep (many-layer) neural networks.
- **Exam trap:** "Model weights change" = the neural network's parameters change. That happens in **training and fine-tuning**, NOT in RAG or prompting.
- **Memory trick:** **Neurons → Layers → Network.** Weights are the "knobs" that training turns.

> **Parameters / weights:** the internal numbers a model learns. "A 70B model" = 70 billion parameters. More parameters = usually more capable, but slower and more expensive.

### 1.1.5 Generative AI (GenAI)
- **Simple meaning:** AI that **creates new content** (text, images, code, audio, video) instead of just labeling or predicting.
- **Technical meaning:** A subset of deep learning that uses large pre-trained models (foundation models) to **generate new content** similar to the data it was trained on, usually in response to a **prompt**.
- **Real-world example:** ChatGPT-style chatbots writing emails; tools that create images from text.
- **AWS example:** **Amazon Bedrock** (API access to FMs); Amazon Nova; Amazon Q / Amazon Quick; Kiro.
- **Exam keyword:** "generate", "create", "draft", "summarize", "write", "new content", "prompt"
- **Common confusion:** GenAI vs predictive (traditional) AI. Predictive AI outputs a **label or number** ("fraud: yes/no"). GenAI outputs **new content** ("write an email explaining the fraud alert").
- **Exam trap:** Don't pick GenAI for a simple, deterministic prediction task with structured data (e.g., "predict churn yes/no from a table"). Traditional ML is cheaper, more accurate, and more explainable there.
- **Memory trick:** **Generative = Generates.** Predictive = Predicts.

### 1.1.6 Agentic AI
- **Simple meaning:** AI that doesn't just answer. It **takes actions** for you, step by step, to finish a goal. It's like an assistant who can plan, use tools, and do tasks.
- **Technical meaning:** AI systems (agents) that use an FM to **reason, plan multi-step tasks, call tools/APIs, keep memory, and act autonomously** (with some human oversight) to reach a goal.
- **Real-world example:** "Book me a flight under $400 next Tuesday." The agent searches flights, compares prices, books the ticket, and emails you the confirmation.
- **AWS example:** **Amazon Bedrock Agents** (managed agents), **Amazon Bedrock AgentCore** (infrastructure to run agents at scale), **Strands Agents** (open-source SDK to build agents), **Kiro** (agentic coding IDE), **Amazon Quick** (agentic workplace assistant).
- **Exam keyword:** "take actions", "multi-step tasks", "autonomously", "call APIs", "use tools", "complete tasks", "orchestrate"
- **Common confusion:** A chatbot **answers**. An agent **acts**. A RAG system *retrieves info*. An agent *does things* (and may use RAG as one of its tools).
- **Exam trap:** "The assistant must look up the order AND issue a refund in the backend system" → that is an **agent** (it takes an action), not just RAG.
- **Memory trick:** **Agent = Acts.** Chatbot = Chats.

### 1.1.7 Large Language Models (LLMs)
- **Simple meaning:** A huge AI model trained on enormous amounts of text so it can read and write human language.
- **Technical meaning:** A type of foundation model, usually based on the **transformer** architecture, with billions of parameters. It is trained on massive text data to understand and generate language by **predicting the next token**.
- **Real-world example:** A model that writes, summarizes, translates, and answers questions.
- **AWS example:** Models in Amazon Bedrock: Amazon Nova (Micro/Lite/Pro/Premier), Anthropic Claude, Meta Llama, Mistral, Cohere Command, AI21 Jamba, DeepSeek, OpenAI open-weight models, and others.
- **Exam keyword:** "text", "language", "next token", "billions of parameters"
- **Common confusion:** **All LLMs are foundation models, but not all foundation models are LLMs.** Image-generation models (such as Stable Diffusion or Nova Canvas) are FMs but not LLMs.
- **Exam trap:** "Which is a foundation model that generates images?" → NOT an LLM.
- **Memory trick:** **LLM = Language only. FM = Foundation for anything.**

### 1.1.8 Foundation Models (FMs)
- **Simple meaning:** A giant, general-purpose model trained once on huge data. You can then reuse it for many different tasks.
- **Technical meaning:** Large models **pre-trained on broad, massive (mostly unlabeled) datasets** using self-supervised learning. They can be adapted to many downstream tasks through prompting, RAG, or fine-tuning.
- **Real-world example:** One model that can summarize, translate, write code, and answer questions.
- **AWS example:** Amazon Bedrock gives access to FMs; SageMaker JumpStart lets you deploy open FMs.
- **Exam keyword:** "pre-trained", "general-purpose", "adapt to many tasks", "large", "broad data"
- **Common confusion:** FM vs LLM (see above). FM vs traditional ML model: a traditional model is trained for **one task**, while an FM handles **many tasks**.
- **Exam trap:** Building an FM from scratch (pre-training) is **extremely expensive**. The exam almost never wants you to pre-train. Prefer prompting → RAG → fine-tuning.
- **Memory trick:** **Foundation = the base of a house.** Build many different rooms (tasks) on top of it.

### 1.1.9 Computer Vision (CV)
- **Simple meaning:** Teaching computers to "see" and understand images and videos.
- **Technical meaning:** The field of AI that analyzes and extracts information from images and video (object detection, image classification, facial analysis, segmentation, OCR).
- **Real-world example:** Detecting defects on a factory line; identifying people in photos; reading license plates.
- **AWS example:** **Amazon Rekognition** (images/video), **Amazon Textract** (text from documents), Amazon Lookout for Vision (industrial defects; being retired, so LOW PRIORITY).
- **Exam keyword:** "images", "video", "detect objects", "faces", "labels", "content moderation of images"
- **Common confusion:** Rekognition (general images/video) vs Textract (**documents**: forms, tables, text).
- **Exam trap:** "Extract text and tables from scanned invoices" → **Textract**, NOT Rekognition (even though Rekognition can detect text in images).
- **Memory trick:** **Rekognition = Recognize things. Textract = extract Text.**

### 1.1.10 Natural Language Processing (NLP)
- **Simple meaning:** Teaching computers to understand and work with human language (text and speech).
- **Technical meaning:** The AI field for processing, analyzing, and generating human language: sentiment analysis, entity extraction, translation, summarization, classification, question answering.
- **Real-world example:** Analyzing customer reviews to find whether they're positive or negative.
- **AWS example:** **Amazon Comprehend** (sentiment, entities, key phrases, language, PII), **Amazon Translate**, **Amazon Transcribe**, **Amazon Polly**, **Amazon Lex**; LLMs in Bedrock.
- **Exam keyword:** "text", "sentiment", "entities", "language", "reviews", "documents"
- **Common confusion:** Comprehend (analyzes text) vs Bedrock LLM (generates text). If the task is standard text analytics like sentiment, **Comprehend** is simpler and cheaper.
- **Exam trap:** "Detect sentiment in customer reviews with the least effort/no ML expertise" → **Comprehend**, not a custom SageMaker model.
- **Memory trick:** **Comprehend = comprehend (understand) text.**

### 1.1.11 Algorithm vs Model
- **Simple meaning:** An **algorithm** is the *recipe* (learning method). A **model** is the *cooked dish*: the result after the recipe is applied to data.
- **Technical meaning:** An *algorithm* is the mathematical procedure used to learn from data (e.g., linear regression, XGBoost, k-means). A *model* is the **trained artifact** (algorithm + learned parameters) that makes predictions.
- **Real-world example:** "Decision tree" is the algorithm. "The loan-approval tree trained on our bank's data" is the model.
- **AWS example:** SageMaker built-in algorithms (XGBoost, k-means, Linear Learner) produce model artifacts stored in S3.
- **Exam keyword:** "trained artifact", "procedure", "learned parameters"
- **Common confusion:** People say "model" for both.
- **Exam trap:** "What is produced by training?" → a **model** (not an algorithm).
- **Memory trick:** **Algorithm + Data + Training = Model.**

### 1.1.12 Training
- **Simple meaning:** The "study" phase, where the model learns from examples.
- **Technical meaning:** The process of feeding data to an algorithm so it adjusts its internal parameters (weights) to minimize errors. The output is a trained model.
- **Real-world example:** Showing a model 1 million cat/dog photos with labels.
- **AWS example:** SageMaker AI training jobs; Bedrock model customization jobs (fine-tuning).
- **Exam keyword:** "learn", "fit", "adjust weights", "training data", "training job"
- **Common confusion:** Training vs inference (see table below).
- **Exam trap:** Training is **expensive and happens rarely**. Inference happens **every time** a user makes a request.
- **Memory trick:** **Training = school. Inference = the job.**

### 1.1.13 Inference
- **Simple meaning:** Using the trained model to make a prediction or generate an answer on **new** data.
- **Technical meaning:** The process of running new input through a trained model to get an output (a prediction, classification, or generated content).
- **Real-world example:** You upload a new photo and the model says "dog".
- **AWS example:** Calling a SageMaker endpoint; calling the Bedrock `InvokeModel` / `Converse` API.
- **Exam keyword:** "predict on new data", "serve", "endpoint", "invoke", "production requests"
- **Common confusion:** Some people think the model keeps "learning" during inference. It does **NOT**. The weights are fixed.
- **Exam trap:** "Model responses are slow for users" = an **inference latency** problem. Fix it with a smaller model, provisioned throughput, prompt caching, or shorter outputs, NOT by retraining.
- **Memory trick:** **Inference = Instant use of the trained model.**

### Training vs Inference

| | Training | Inference |
|---|---|---|
| What | Model **learns** from data | Model **uses** what it learned |
| When | Once / occasionally (retraining) | Every request, continuously |
| Data | Historical (often labeled) data | New, unseen data |
| Weights | **Change** | **Fixed** |
| Cost | High, one-time burst | Ongoing, per request (per token for FMs) |
| AWS | SageMaker training job, Bedrock customization job | SageMaker endpoint, Bedrock InvokeModel/Converse |

---

## 1.2 TYPES OF INFERENCE (VERY TESTABLE)

### 1.2.1 Real-time inference
- **Simple meaning:** Instant answers, one request at a time, while the user waits.
- **Technical meaning:** A persistent, always-on endpoint that returns predictions with **low latency** (milliseconds to seconds) for interactive applications.
- **Real-world example:** Fraud check while a card is being swiped; a chatbot answer.
- **AWS example:** SageMaker **real-time endpoint**; Bedrock on-demand invocation.
- **Exam keyword:** "immediately", "low latency", "interactive", "real-time", "milliseconds"
- **Common confusion:** Real-time vs serverless. Both return quick answers, but real-time endpoints are **always running** (you pay even when idle).
- **Exam trap:** Steady, high traffic that needs low latency → real-time. Unpredictable traffic with idle gaps → **serverless**.
- **Memory trick:** **Real-time = Right now.**

### 1.2.2 Batch inference (Batch Transform)
- **Simple meaning:** Process a big pile of data all at once, not instantly. Results come later.
- **Technical meaning:** Offline inference on a **large dataset** in one job. No persistent endpoint is needed. It is cost-efficient when immediate results aren't required.
- **Real-world example:** Every night, score all 5 million customers for churn risk.
- **AWS example:** SageMaker **Batch Transform**; **Amazon Bedrock batch inference** (often about **50% cheaper** than on-demand for supported models).
- **Exam keyword:** "large dataset", "nightly", "no need for immediate results", "offline", "entire dataset", "most cost-effective"
- **Common confusion:** Batch vs asynchronous. Batch = **a whole dataset** at once. Async = **individual requests** that are large or slow and get queued.
- **Exam trap:** "Summarize 1 million documents overnight at the lowest cost" → **batch inference**, not real-time.
- **Memory trick:** **Batch = Bulk.**

### 1.2.3 Asynchronous inference
- **Simple meaning:** You send a big request, it goes into a queue, and you get notified when it's done.
- **Technical meaning:** Requests are **queued** and processed as resources allow. It suits **large payloads (up to 1 GB)** and **long processing times (up to ~1 hour)**. Results go to S3, with an optional SNS notification. The endpoint can **scale to zero** when idle.
- **Real-world example:** Uploading a long video for analysis and getting an email when the analysis is done.
- **AWS example:** SageMaker **Asynchronous Inference**.
- **Exam keyword:** "large payload", "long processing time", "queue", "near real-time", "notify when complete", "scale to zero"
- **Common confusion:** Async vs batch (see above).
- **Exam trap:** "Payload is 500 MB and processing takes 20 minutes per request" → **asynchronous**. (Real-time endpoints have small payload limits (~6 MB) and short timeouts.)
- **Memory trick:** **Async = Await the answer.**

### 1.2.4 Serverless inference
- **Simple meaning:** AWS runs the model only when a request comes in. You don't manage servers and you don't pay when nobody is using it.
- **Technical meaning:** Fully managed inference that **automatically scales, including to zero**. You pay per use. It suits **intermittent or unpredictable traffic** that can tolerate **cold starts** (a delay on the first request after idle time).
- **Real-world example:** An internal HR tool used a few times a day.
- **AWS example:** SageMaker **Serverless Inference**. (Bedrock on-demand is also "serverless" from your point of view: no servers to manage.)
- **Exam keyword:** "intermittent traffic", "unpredictable", "idle periods", "no infrastructure management", "pay only when used"
- **Common confusion:** Serverless vs async. Both can scale to zero. Serverless is for **small, quick** requests. Async is for **large, slow** requests.
- **Exam trap:** Serverless has **cold starts**, so it is not ideal for strict, consistent low-latency needs.
- **Memory trick:** **Serverless = Sometimes used.**

### Inference comparison table

| Type | Latency | Payload | Traffic pattern | Endpoint always on? | Keyword |
|---|---|---|---|---|---|
| **Real-time** | ms–seconds | Small (~6 MB) | Steady, continuous | Yes | "immediate", "interactive" |
| **Serverless** | Seconds (cold start) | Small (~4 MB) | Intermittent / spiky | No (scales to 0) | "unpredictable", "idle" |
| **Asynchronous** | Minutes (queued) | **Large (up to 1 GB)** | Bursty, long jobs | Can scale to 0 | "large payload", "long processing" |
| **Batch** | Hours (offline) | Whole dataset | Scheduled | No endpoint | "entire dataset", "nightly", "cheapest" |

### IF THE QUESTION SAYS… → THINK…
1. "Predictions needed immediately while the customer waits" → **Real-time inference**
2. "Traffic is unpredictable with long idle periods; minimize cost" → **Serverless inference**
3. "Large input files (hundreds of MB) and long processing time" → **Asynchronous inference**
4. "Score the entire dataset once a week; results not needed immediately" → **Batch inference / Batch Transform**
5. "Process many prompts in Bedrock at lower cost, not time-sensitive" → **Bedrock batch inference**

---

## 1.3 TYPES OF MACHINE LEARNING

### 1.3.1 Supervised learning
- **Simple meaning:** Learning with an "answer key". Every training example comes with the correct answer (a label).
- **Technical meaning:** ML that trains on **labeled data** (input + known output) to learn a mapping from inputs to outputs. The two main tasks are **classification** and **regression**.
- **Real-world example:** Emails labeled "spam" or "not spam" → the model learns to classify new emails.
- **AWS example:** SageMaker built-in XGBoost / Linear Learner; data labeled with **SageMaker Ground Truth**.
- **Exam keyword:** "labeled data", "historical outcomes", "known answers", "predict a category/number"
- **Common confusion:** Supervised ≠ "a human supervises the training". It means the **data has labels**.
- **Exam trap:** If the question mentions **labels** or "historical records with the outcome", it is supervised.
- **Memory trick:** **Supervised = Solutions provided.**

### 1.3.2 Unsupervised learning
- **Simple meaning:** Learning **without** an answer key. The model finds hidden groups or patterns by itself.
- **Technical meaning:** ML on **unlabeled data** to discover structure: **clustering**, **dimensionality reduction**, **anomaly detection**, association.
- **Real-world example:** Group customers into segments based on buying behavior without predefined groups.
- **AWS example:** SageMaker **k-means** (clustering), **Random Cut Forest** (anomaly detection), **PCA** (dimensionality reduction).
- **Exam keyword:** "unlabeled", "find groups", "segments", "patterns", "anomalies", "no predefined categories"
- **Common confusion:** Clustering (unsupervised, **no** labels) vs classification (supervised, labels **exist**).
- **Exam trap:** "Group customers into segments; the company doesn't know the segments in advance" → **clustering (unsupervised)**, not classification.
- **Memory trick:** **Unsupervised = Undiscovered groups.**

### 1.3.3 Reinforcement learning (RL)
- **Simple meaning:** Learning by trial and error, like training a dog with treats. Good actions get rewards; bad actions get penalties.
- **Technical meaning:** An **agent** interacts with an **environment**, takes **actions**, and receives **rewards/penalties**, learning a **policy** that maximizes cumulative reward.
- **Real-world example:** A robot learning to walk; a game-playing AI; warehouse robot routing.
- **AWS example:** **AWS DeepRacer** (a car racing simulator for learning RL; retired from console, but still a classic example); RLHF uses RL to align LLMs.
- **Exam keyword:** "reward", "penalty", "trial and error", "agent", "environment", "maximize cumulative reward"
- **Common confusion:** RL "agent" vs agentic AI "agent". Different ideas that share a word. RLHF (for LLM alignment) *uses* RL.
- **Exam trap:** No labeled data, but there IS a reward signal → **RL** (not unsupervised).
- **Memory trick:** **Reinforcement = Rewards.**

### 1.3.4 Self-supervised learning (bonus, important for FMs)
- **Simple meaning:** The model creates its own labels from raw data, for example by hiding a word and guessing it.
- **Technical meaning:** Training on unlabeled data where the target is derived from the data itself (next-token prediction, masked words). This is **how foundation models are pre-trained**.
- **Exam keyword:** "pre-training on unlabeled data", "predict next word"
- **Memory trick:** **Self-supervised = it quizzes itself.**

### 1.3.5 Semi-supervised learning (LOW PRIORITY)
- A small amount of labeled data plus a lot of unlabeled data. Know only the name.

### Supervised vs Unsupervised vs Reinforcement Learning

| | Supervised | Unsupervised | Reinforcement |
|---|---|---|---|
| Data | **Labeled** | **Unlabeled** | No dataset; **environment + rewards** |
| Goal | Predict label/number | Find hidden structure | Learn best actions |
| Tasks | Classification, regression | Clustering, anomaly detection, dimensionality reduction | Control, games, robotics, optimization |
| Example | Spam detection, price prediction | Customer segmentation | Robot navigation, DeepRacer |
| Keyword | "labeled", "historical outcomes" | "group", "segment", "no labels" | "reward", "trial and error" |
| Memory | Solutions provided | Undiscovered groups | Rewards |

---

## 1.4 ML PROBLEM TYPES

### 1.4.1 Classification
- **Simple meaning:** Predict **which category** something belongs to.
- **Technical meaning:** A supervised task that predicts a **discrete label (class)**. **Binary** = 2 classes (yes/no). **Multi-class** = 3+ classes (one of several). **Multi-label** = several labels at the same time.
- **Real-world example:** Is this transaction fraud? (yes/no). Which animal is in the image? (cat/dog/bird).
- **AWS example:** SageMaker XGBoost; Amazon Comprehend custom classification; Amazon Fraud Detector (legacy, LOW PRIORITY).
- **Exam keyword:** "category", "class", "yes/no", "which type", "approve/deny", "fraud or not"
- **Common confusion:** Classification vs clustering (labels vs no labels).
- **Exam trap:** "Predict whether a customer will churn" = **binary classification** (NOT regression, even though the model may output a probability).
- **Memory trick:** **Classification = Categories.**

### 1.4.2 Regression
- **Simple meaning:** Predict **a number** (a continuous value).
- **Technical meaning:** A supervised task that predicts a **continuous numeric value**.
- **Real-world example:** Predict house price, tomorrow's temperature, or next month's sales.
- **AWS example:** SageMaker Linear Learner / XGBoost regression.
- **Exam keyword:** "how much", "how many", "price", "amount", "quantity", "forecast a value"
- **Common confusion:** "Logistic regression" is actually a **classification** algorithm (despite its name).
- **Exam trap:** "Predict the number of units to sell" → regression. "Predict high/medium/low demand" → classification.
- **Memory trick:** **Regression = Real numbers.**

### 1.4.3 Clustering
- **Simple meaning:** Automatically put similar things into groups, without being told the groups.
- **Technical meaning:** An unsupervised task that groups data points by similarity (e.g., **k-means**).
- **Real-world example:** Customer segmentation for marketing.
- **AWS example:** SageMaker k-means.
- **Exam keyword:** "segment", "group similar", "no labels", "discover groups"
- **Common confusion:** Classification.
- **Exam trap:** Clustering needs **no labels**. If labels exist, it's classification.
- **Memory trick:** **Clustering = Crowds of similar things.**

### 1.4.4 Other problem types to recognize
| Problem | Meaning | Example | Keyword |
|---|---|---|---|
| **Anomaly detection** | Find unusual data points | Fraud, equipment failure | "unusual", "outlier", "abnormal" |
| **Forecasting (time-series)** | Predict future values over time | Demand, sales, traffic | "future", "over time", "seasonal" |
| **Recommendation** | Suggest items a user may like | "Customers also bought" | "personalize", "recommend" (→ **Amazon Personalize**) |
| **Dimensionality reduction** | Reduce the number of features | Compress 500 columns to 20 | "reduce features", PCA |

### Classification vs Regression vs Clustering

| | Classification | Regression | Clustering |
|---|---|---|---|
| Output | Category/label | Number | Group ID (discovered) |
| Learning type | Supervised | Supervised | Unsupervised |
| Labels needed? | Yes | Yes | **No** |
| Example | Fraud yes/no | House price | Customer segments |
| Metrics | Accuracy, precision, recall, F1, AUC | MAE, MSE, RMSE, R² | Silhouette score (LOW PRIORITY) |
| Memory | Categories | Real numbers | Crowds |

### IF THE QUESTION SAYS… → THINK…
6. "Historical data with known outcomes; predict yes/no" → **Supervised, binary classification**
7. "Predict a numeric value such as price or revenue" → **Regression**
8. "Group customers without predefined labels" → **Clustering (unsupervised)**
9. "Learn through rewards and penalties" → **Reinforcement learning**
10. "Detect unusual transactions" → **Anomaly detection**

---

## 1.5 DATA TYPES

### 1.5.1 Labeled vs Unlabeled data
- **Simple meaning:** Labeled data has the answer attached. Unlabeled data is raw, with no answer.
- **Technical meaning:** *Labeled* = each record has a target/ground-truth value (used for supervised learning). *Unlabeled* = no target (used for unsupervised or self-supervised learning).
- **Real-world example:** Labeled: photo + "cat". Unlabeled: just the photo.
- **AWS example:** **SageMaker Ground Truth** creates labels using human workers (your own team, vendors, or Amazon Mechanical Turk) plus automatic labeling. **Ground Truth Plus** is a fully managed labeling service.
- **Exam keyword:** "annotate", "tag", "ground truth", "human labelers"
- **Common confusion:** Ground Truth (labels data **before** training) vs Amazon Augmented AI (A2I) (human review of predictions **after** deployment).
- **Exam trap:** "Need humans to label thousands of images for training" → **SageMaker Ground Truth**.
- **Memory trick:** **Ground Truth = the true answers on the ground floor (before training).**

### 1.5.2 Structured vs Unstructured data
- **Simple meaning:** Structured data fits neatly in rows and columns (a spreadsheet). Unstructured data doesn't (images, emails, audio).
- **Technical meaning:** *Structured* = organized with a fixed schema (tables, databases). *Unstructured* = no predefined format (text documents, images, audio, video). *Semi-structured* = partly organized (JSON, XML, logs).
- **Real-world example:** Structured: a sales table. Unstructured: customer call recordings.
- **AWS example:** Structured → Amazon RDS, Redshift. Unstructured → **Amazon S3**. GenAI is especially good at **unstructured** data.
- **Exam keyword:** "rows and columns", "schema" (structured); "PDFs, images, emails, audio" (unstructured)
- **Common confusion:** JSON is **semi-structured**.
- **Exam trap:** Traditional ML shines on structured/tabular data. Deep learning/GenAI shines on unstructured data.
- **Memory trick:** **Structured = Spreadsheet.**

### 1.5.3 Tabular data
- **Simple meaning:** Data in a table: rows = records, columns = features.
- **Technical meaning:** Structured data where each row is an observation and each column is a **feature** (an input variable).
- **Example:** A customer table with age, income, and churned (yes/no).
- **AWS example:** SageMaker XGBoost, SageMaker Canvas (no-code), SageMaker Autopilot (AutoML).
- **Exam keyword:** "CSV", "spreadsheet", "columns", "features"
- **Exam trap:** For tabular prediction, **traditional ML (e.g., XGBoost)** usually beats an LLM on cost, speed, and explainability.
- **Memory trick:** **Tabular = Table.**

### 1.5.4 Time-series data
- **Simple meaning:** Data points recorded in order over time.
- **Technical meaning:** Sequential data indexed by timestamps. It is used for **forecasting** and trend/seasonality analysis.
- **Example:** Daily sales, stock prices, sensor readings every second.
- **AWS example:** SageMaker (DeepAR algorithm), SageMaker Canvas forecasting. (Amazon Forecast is closed to new customers, so LOW PRIORITY.)
- **Exam keyword:** "over time", "timestamps", "forecast", "seasonal", "trend"
- **Exam trap:** Order matters. You can't randomly shuffle time-series data when splitting it.
- **Memory trick:** **Time-series = Timeline.**

### 1.5.5 Image data
- **Meaning:** Pixels, such as photos, scans, and medical images.
- **AWS:** Rekognition, Textract (documents), Bedrock multimodal models (Nova, Claude), Nova Canvas (generation).
- **Keyword:** "photos", "scans", "visual inspection".

### 1.5.6 Text data
- **Meaning:** Words, such as documents, emails, reviews, and chat logs.
- **AWS:** Comprehend, Translate, Bedrock LLMs, Kendra (enterprise search).
- **Keyword:** "documents", "reviews", "emails".

### 1.5.7 Audio / Video data
- **Audio → Transcribe** (speech to text), **Polly** (text to speech).
- **Video → Rekognition Video**; Nova Reel (video generation); Bedrock Data Automation (multimodal content extraction).

### Training / validation / test split
- **Training set** (~70–80%): the model learns from it.
- **Validation set** (~10–15%): used to tune the model and choose between versions.
- **Test set** (~10–15%): final, unbiased check on data the model has **never seen**.
- **Trap:** Evaluating on training data gives falsely high scores. Always evaluate on **held-out** data.

### Features & feature engineering
- **Feature** = an input column the model uses (age, income).
- **Label/target** = what you want to predict (churned: yes/no).
- **Feature engineering** = creating or transforming features to improve the model (e.g., "age" from "birth date").
- **AWS:** **SageMaker Feature Store** (store and share features), **SageMaker Data Wrangler** (prepare/transform data visually; now part of SageMaker Canvas).

---

## 1.6 MODEL FIT, BIAS, VARIANCE

### 1.6.1 Fit (model fit)
- **Simple meaning:** How well the model has learned the real pattern. Not too little, not too much.
- **Technical meaning:** The degree to which a model captures the underlying patterns of the data and **generalizes** to new data.
- **Memory trick:** **Good fit = good on training AND good on new data.**

### 1.6.2 Overfitting
- **Simple meaning:** The model **memorized** the training data instead of learning the general pattern. Like a student who memorizes past exam answers and fails a new exam.
- **Technical meaning:** **High accuracy on training data, low accuracy on new/test data.** The model is too complex and learned noise. This is called **high variance**.
- **Real-world example:** 99% accuracy in training, 60% in production.
- **AWS example:** Detect it with SageMaker Debugger or by comparing training vs validation metrics. Fix it with early stopping or regularization (SageMaker Automatic Model Tuning helps).
- **Exam keyword:** "performs well on training data but poorly on new data", "does not generalize"
- **Fixes:** More (diverse) training data, **data augmentation**, **simpler model**, **regularization**, **early stopping**, fewer features, dropout, cross-validation.
- **Common confusion:** Overfitting vs underfitting.
- **Exam trap:** "Train longer" makes overfitting **worse**. "More diverse data" helps.
- **Memory trick:** **Overfit = Over-memorized.**

### 1.6.3 Underfitting
- **Simple meaning:** The model is too simple and didn't learn enough. It does badly everywhere.
- **Technical meaning:** **Poor performance on both training and test data.** The model can't capture the pattern. This is called **high bias**.
- **Example:** Using a straight line to model a curvy relationship.
- **Fixes:** More complex model, **more/better features**, **train longer**, less regularization.
- **Exam keyword:** "performs poorly on both training and test data"
- **Memory trick:** **Underfit = Under-learned.**

### 1.6.4 Bias (two meanings, careful!)
1. **Statistical bias (model fit):** error from overly simple assumptions, which leads to underfitting.
2. **Societal/ethical bias (Responsible AI):** the model treats groups unfairly (e.g., by gender or race), usually because the **training data** is unbalanced or not representative.
- **Exam keyword (ethical):** "unfair to a demographic group", "underrepresented", "skewed training data"
- **AWS example:** **SageMaker Clarify** detects bias in data (pre-training) and in model predictions (post-training).
- **Exam trap:** "The model performs poorly for one age group because training data had few examples of that group" → **data bias / non-representative data**. Fix: collect **more diverse, representative data**; check with **Clarify**.
- **Memory trick:** **Bias = a tilted scale.**

### 1.6.5 Variance
- **Meaning:** How much a model's predictions change with different training data. **High variance → overfitting.**
- **Bias–variance tradeoff:** Simple model = high bias (underfit). Complex model = high variance (overfit). The goal is a balance.

### 1.6.6 Fairness
- **Simple meaning:** The model gives equally good and just outcomes to all groups of people.
- **Technical meaning:** The absence of unjustified discrimination in model outcomes across demographic groups (measured with bias metrics).
- **AWS:** SageMaker Clarify.
- **Exam keyword:** "equitable", "all demographic groups", "discrimination"

### Overfitting vs Underfitting

| | Overfitting | Underfitting | Good fit |
|---|---|---|---|
| Training performance | **High** | Low | High |
| Test performance | **Low** | Low | High |
| Cause | Too complex, memorized noise | Too simple | Balanced |
| Also called | High variance | High bias | — |
| Fix | More data, simplify, regularize, early stop | More features, complex model, train longer | — |

### IF THE QUESTION SAYS… → THINK…
11. "Model is accurate on training data but inaccurate on new data" → **Overfitting**
12. "Model is inaccurate on both training and test data" → **Underfitting**
13. "Model predictions are unfair to a demographic group" → **Bias → SageMaker Clarify + more representative data**
14. "Need humans to label training data" → **SageMaker Ground Truth**

---

## 1.7 EVALUATION METRICS (CLASSIFICATION)

First understand the **confusion matrix** (a table comparing predictions against reality):

| | Predicted Positive | Predicted Negative |
|---|---|---|
| **Actually Positive** | **TP** (True Positive) ✅ | **FN** (False Negative) ❌ missed it |
| **Actually Negative** | **FP** (False Positive) ❌ false alarm | **TN** (True Negative) ✅ |

Example: Fraud model. Positive = fraud.
- TP = caught real fraud. FN = **missed** real fraud. FP = flagged an innocent transaction. TN = correctly passed a normal transaction.

### 1.7.1 Accuracy
- **Simple meaning:** What percentage of all predictions were right?
- **Formula:** (TP + TN) / Total
- **Exam trap:** Accuracy is **misleading on imbalanced data**. If 99% of transactions are not fraud, a model that always says "not fraud" is 99% accurate but useless.
- **Memory trick:** **Accuracy = All correct / All.**

### 1.7.2 Precision
- **Simple meaning:** Of everything the model flagged as positive, how many really were positive?
- **Formula:** TP / (TP + FP)
- **When it matters:** When **false positives are costly**. Examples: a spam filter (don't send important email to spam); flagging innocent people.
- **Keyword:** "minimize false positives", "false alarms are expensive"
- **Memory trick:** **Precision = "When I say YES, am I right?"** (P for Predicted-positive purity)

### 1.7.3 Recall (Sensitivity, True Positive Rate)
- **Simple meaning:** Of all the real positives, how many did the model catch?
- **Formula:** TP / (TP + FN)
- **When it matters:** When **missing a positive is costly (false negatives)**. Examples: cancer detection, fraud detection, safety defects.
- **Keyword:** "must not miss", "minimize false negatives", "catch all cases"
- **Memory trick:** **Recall = "Did I Recall (find) them all?"**

### 1.7.4 F1 score
- **Simple meaning:** One number that balances precision and recall.
- **Formula:** Harmonic mean = 2 × (Precision × Recall) / (Precision + Recall)
- **When:** Imbalanced data, when you need **both** precision and recall.
- **Keyword:** "balance precision and recall", "imbalanced dataset"
- **Memory trick:** **F1 = the Fair referee between P and R.**

### 1.7.5 AUC-ROC (know the name)
- A measure (0–1) of how well a model separates classes across all thresholds. 1.0 = perfect, 0.5 = random guessing.
- **Keyword:** "compare binary classifiers across thresholds".

### Regression metrics (know the names)
| Metric | Meaning | Keyword |
|---|---|---|
| **MAE** (Mean Absolute Error) | Average size of errors | "average error" |
| **MSE** (Mean Squared Error) | Squares errors, so it punishes big errors more | "penalize large errors" |
| **RMSE** (Root MSE) | MSE in the original units | "error in same units as target" |
| **R²** (R-squared) | How much variance the model explains (0–1; higher = better) | "goodness of fit" |

### Precision vs Recall (classic exam pair)

| | Precision | Recall |
|---|---|---|
| Question it answers | Of predicted positives, how many were right? | Of actual positives, how many did we find? |
| Protects against | **False positives** | **False negatives** |
| Use when | False alarms are costly | Misses are costly |
| Example | Spam filter, legal accusations | Disease screening, fraud, safety |

### IF THE QUESTION SAYS… → THINK…
15. "Missing a fraudulent transaction/disease is very costly" → **Recall**
16. "Flagging legitimate customers as fraud is very costly" → **Precision**
17. "Dataset is highly imbalanced; need a balanced metric" → **F1 score** (not accuracy)
18. "Measure average prediction error of a price model" → **MAE / RMSE**

---

## 1.8 BUSINESS METRICS & ROI

### 1.8.1 Business metrics
- **Simple meaning:** Numbers the *business* cares about, not the model's technical scores.
- **Technical meaning:** KPIs that measure whether the AI solution delivers business value. Examples: **cost per user, development cost, customer feedback/satisfaction, ROI, revenue, conversion rate, average handle time, churn reduction, productivity**.
- **Example:** The chatbot model's accuracy is 92% (technical), but the business metric is "call-center cost dropped 30%".
- **Exam keyword:** "business value", "measure success", "KPI", "impact on the business"
- **Exam trap:** "How should the company measure if the AI project is successful for the business?" → a **business metric** (cost savings, revenue, customer satisfaction), NOT F1 score.
- **Memory trick:** **Model metrics = is the model good? Business metrics = is the business better?**

### 1.8.2 ROI (Return on Investment)
- **Simple meaning:** Did we get more money/value back than we spent?
- **Formula:** (Gain − Cost) / Cost
- **In AI:** Compare value created (saved labor hours, more sales) against costs (development, inference/token costs, data, maintenance).
- **Exam keyword:** "justify the investment", "cost vs benefit"

---

## 1.9 AI/ML USE CASES & WHEN (NOT) TO USE AI

### 1.9.1 When AI/ML is appropriate
- The problem involves **patterns in lots of data** that are too complex for manual rules.
- You need to **scale** decisions (millions of predictions).
- The rules **change often** (fraud patterns evolve).
- You need to **automate** repetitive human judgment (document processing, image review).
- You need **personalization** (recommendations).
- You have enough **good-quality data**.

### 1.9.2 When AI/ML is NOT appropriate
- A **simple rule or formula** solves it (e.g., calculate sales tax). Use regular code.
- You need a **100% deterministic, exact, auditable** answer every time (e.g., the account balance calculation).
- **Not enough (or poor-quality) data.**
- **Cost exceeds benefit** (negative ROI).
- Strict **explainability** is legally required and the model is a black box.
- **Exam trap:** "The company needs to calculate the exact total of an invoice using a fixed formula" → **no ML needed**. ML gives **probabilistic** answers (predictions), not guaranteed exact ones.
- **Memory trick:** **If you can write the rule, don't train a model.**

### 1.9.3 When traditional ML is better than foundation models
| Choose **traditional ML** when… | Choose **foundation models (GenAI)** when… |
|---|---|
| Structured/tabular data | Unstructured data (text, images, audio) |
| Single, narrow prediction task (churn, price, fraud) | Many tasks, or open-ended generation |
| Need high explainability | Explainability less critical |
| Need low cost & low latency at huge scale | Need natural language interaction |
| You have labeled historical data | Little labeled data (use prompting) |
| Deterministic, consistent outputs required | Creative / varied outputs acceptable |
- **Exam trap:** Using an LLM to predict "loan default yes/no" from a table of numbers is overkill. A traditional classification model is cheaper, faster, and more explainable.

### 1.9.4 Common AI use cases & AWS services

| Use case | Example | AWS service |
|---|---|---|
| Computer vision | Detect objects, faces, unsafe images | Rekognition |
| Document processing | Extract text/tables/forms | Textract (+ Comprehend, Bedrock Data Automation) |
| Speech recognition | Call transcripts, subtitles | Transcribe |
| Text-to-speech | Voice for apps | Polly |
| Translation | Multilingual websites | Translate |
| Text analytics | Sentiment, entities, PII | Comprehend |
| Conversational interface | Chatbots, IVR | Lex (+ Bedrock) |
| Recommendations | Product suggestions | Personalize |
| Fraud detection | Transaction scoring | SageMaker (Fraud Detector is legacy) |
| Forecasting | Demand planning | SageMaker (DeepAR/Canvas) |
| Enterprise search | Search internal docs | Kendra, Bedrock Knowledge Bases, Amazon Quick |
| Content generation | Marketing copy, summaries | Bedrock |
| Code generation | Developer assistant | Kiro, Amazon Q Developer |
| Medical text | Extract medical entities | Comprehend Medical, Transcribe Medical |

### IF THE QUESTION SAYS… → THINK…
19. "Calculation with fixed rules; needs exact results" → **No ML; use traditional programming**
20. "Tabular data, predict churn, need explainability and low cost" → **Traditional ML (e.g., XGBoost in SageMaker)**, not an FM
21. "How to measure whether the chatbot helped the business?" → **Business metrics** (cost per interaction, CSAT, handle time)

---

## 1.10 ML DEVELOPMENT LIFECYCLE (ML PIPELINE)

**Memorize the order (ordering questions!):**

1. **Business goal / problem identification** → define the problem and success metrics
2. **ML problem framing** → decide it's classification/regression/etc.; is ML even needed?
3. **Data collection** → gather data (S3, databases)
4. **Data preprocessing / preparation** → clean, handle missing values, label, split
5. **Exploratory data analysis (EDA)** → understand the data, find patterns and issues
6. **Feature engineering** → create/select the best input features
7. **Model training** → train the algorithm on the training data
8. **Hyperparameter tuning** → adjust settings (learning rate, number of trees)
9. **Model evaluation** → test on held-out data with metrics
10. **Deployment** → put the model on an endpoint or batch job
11. **Monitoring** → watch for **drift** and performance drops
12. **Retraining** → update the model with new data (loop back)

**Short version to memorize:** **Business problem → Collect → Prepare → Features → Train → Tune → Evaluate → Deploy → Monitor → Retrain.**
**Memory trick:** "**B**ig **C**ats **P**lay **F**etch; **T**igers **T**ake **E**very **D**og's **M**eat **R**aw."

### 1.10.1 Data preparation
- **Simple meaning:** Cleaning and organizing the raw data so the model can learn from it.
- **Technical:** Handling missing values, removing duplicates and outliers, normalizing/scaling, encoding categories, labeling, splitting train/validation/test.
- **AWS:** **SageMaker Data Wrangler / Canvas** (visual data prep), **AWS Glue** (ETL = Extract, Transform, Load), **Glue DataBrew** (visual cleaning), **SageMaker Ground Truth** (labeling), **SageMaker Feature Store**.
- **Exam trap:** "Garbage in, garbage out." Most model problems come from **data quality**.
- **Memory trick:** **Clean the kitchen before cooking.**

### 1.10.2 Hyperparameters
- **Simple meaning:** The settings you choose **before** training (like oven temperature). The model does NOT learn them.
- **Technical:** Configuration values such as learning rate, number of epochs, batch size, tree depth. **Parameters (weights)** are learned; **hyperparameters** are set.
- **AWS:** **SageMaker Automatic Model Tuning (AMT)** finds the best hyperparameters automatically.
- **Epoch** = one full pass through the training data.
- **Exam trap:** "Automatically find the best hyperparameter values" → SageMaker **Automatic Model Tuning**.

### 1.10.3 Evaluation
- Test the model on unseen data with the right metric (accuracy/F1/RMSE…). Compare to a **baseline**. Check **bias** (Clarify).

### 1.10.4 Deployment
- Make the model available for use: a real-time endpoint, serverless, async, or batch (see 1.2).
- **AWS:** SageMaker endpoints; **SageMaker Model Registry** (catalog and approve model versions before deployment).

### 1.10.5 Monitoring
- **Simple meaning:** Watching the model in production to make sure it still works well.
- **Technical:** Tracking prediction quality, **data drift** (input data changes over time), **concept drift** (the relationship between input and output changes), bias drift, and latency/errors.
- **AWS:** **SageMaker Model Monitor** (detects drift in data quality, model quality, bias, and feature attribution); **Amazon CloudWatch** (metrics, logs, alarms).
- **Exam keyword:** "performance degraded over time", "data changed since training", "drift"
- **Exam trap:** "Model accuracy dropped months after deployment because customer behavior changed" → **drift → Model Monitor → retrain**.
- **Memory trick:** **Models age like milk, not wine. Monitor them.**

### 1.10.6 Retraining
- Train again with new data when drift or a performance drop is detected. It can be **automated** with **SageMaker Pipelines**.

---

## 1.11 MLOps & PRODUCTION CONCEPTS

### 1.11.1 MLOps
- **Simple meaning:** DevOps for machine learning. Automating and managing the whole ML lifecycle so models reach production reliably and stay healthy.
- **Technical meaning:** Practices and tools that automate and standardize ML workflows: **CI/CD for models, version control, experiment tracking, automated pipelines, model registry, monitoring, retraining**.
- **Real-world example:** New data arrives → pipeline automatically retrains, evaluates, and (after approval) deploys the model.
- **AWS example:** **SageMaker Pipelines** (workflow automation), **SageMaker Model Registry** (versioning/approval), **SageMaker Experiments / managed MLflow** (tracking), **SageMaker Model Monitor**, **SageMaker Projects** (MLOps templates).
- **Exam keyword:** "automate the ML lifecycle", "repeatable", "CI/CD", "production", "scale ML operations"
- **Exam trap:** "Automate retraining and deployment steps" → **SageMaker Pipelines** (not Lambda alone).
- **Memory trick:** **MLOps = ML + DevOps = automate the model factory.**

### MLOps key benefits (from the guide)
| Concept | Simple meaning | AWS |
|---|---|---|
| **Experimentation** | Try many versions (data, features, hyperparameters) and track results | SageMaker Experiments, managed MLflow |
| **Repeatable processes** | Same steps run the same way every time | SageMaker Pipelines |
| **Scalable systems** | Handle more data/models/traffic | SageMaker managed infrastructure |
| **Managing technical debt** | Avoid messy shortcuts that make future changes costly | Pipelines, versioning, documentation |
| **Production readiness** | Model is tested, monitored, secure, and documented before launch | Model Registry, Model Cards, Model Monitor |
| **Model monitoring** | Detect drift/quality drops | Model Monitor, CloudWatch |
| **Model re-training** | Refresh with new data | Pipelines |

### 1.11.2 Experimentation
- Trying different approaches and **tracking** each run's settings and results so you can compare them.
- **Keyword:** "track and compare training runs" → **SageMaker Experiments / MLflow**.

### 1.11.3 Reproducibility
- **Simple meaning:** Someone can re-run your work and get the same result.
- **Technical:** Versioning of **data, code, model, hyperparameters, and environment** so results can be recreated and audited.
- **Keyword:** "recreate the same model", "audit how a model was built", "lineage"
- **AWS:** SageMaker Pipelines, Model Registry, **SageMaker ML Lineage Tracking**, Experiments.

### 1.11.4 Technical debt
- **Simple meaning:** Shortcuts today create extra work tomorrow (like credit card debt).
- **In ML:** undocumented features, manual steps, no versioning, "glue code", no monitoring.
- **Fix:** MLOps automation, documentation, versioning.

### 1.11.5 Production readiness
- The model is ready for real users: **tested, scalable, secure, monitored, documented, approved, rollback-able**.

### Key SageMaker AI features for Domain 1 (summary)
| Feature | What it does | Keyword |
|---|---|---|
| **SageMaker AI** | Build, train, deploy ML models (full platform) | "custom model", "full control" |
| **SageMaker Studio / Unified Studio** | Web IDE for ML/data work | "IDE", "notebooks" |
| **SageMaker Canvas** | **No-code** ML for business analysts | "no ML experience", "no code" |
| **SageMaker Autopilot** | AutoML: automatically builds the best model (now in Canvas) | "automatically build model" |
| **SageMaker JumpStart** | Pre-trained models & solutions, one-click deploy | "pre-trained models", "quickly deploy open-source FM" |
| **SageMaker Data Wrangler** | Visual data preparation | "prepare data, minimal code" |
| **SageMaker Feature Store** | Store, share, reuse features | "reuse features across teams" |
| **SageMaker Ground Truth** | Data labeling with humans | "label data" |
| **SageMaker Clarify** | Bias detection + explainability | "bias", "explain predictions", "feature importance" |
| **SageMaker Model Monitor** | Monitor deployed models for drift | "drift", "quality degrades" |
| **SageMaker Model Registry** | Catalog/version/approve models | "version", "approve for production" |
| **SageMaker Model Cards** | Document model details for governance | "document intended use, risk" |
| **SageMaker Model Dashboard** | Single view of all models & monitors | "overview of all models" |
| **SageMaker Pipelines** | MLOps workflow automation (CI/CD) | "automate ML workflow" |
| **SageMaker Experiments / MLflow** | Track experiments | "compare runs" |
| **SageMaker Debugger** | Debug training problems | "training issues", "vanishing gradients" |
| **SageMaker Automatic Model Tuning** | Hyperparameter optimization | "best hyperparameters" |
| **Amazon Augmented AI (A2I)** | Human review of low-confidence predictions | "human review", "low confidence" |
| **SageMaker Role Manager** | Quickly set least-privilege roles for ML personas | "permissions for data scientists" |

### IF THE QUESTION SAYS… → THINK…
22. "Business analysts with no ML experience need to build predictions" → **SageMaker Canvas**
23. "Automate the steps of the ML workflow (CI/CD for ML)" → **SageMaker Pipelines** (MLOps)
24. "Model accuracy dropped over time because input data changed" → **Data drift → SageMaker Model Monitor → retrain**
25. "Track and compare many training experiments" → **SageMaker Experiments / MLflow**
26. "Need to recreate exactly how a model was built" → **Reproducibility / lineage (versioning, Pipelines, Model Registry)**
27. "Automatically find the best hyperparameters" → **SageMaker Automatic Model Tuning**
28. "Humans should review predictions when the model's confidence is low" → **Amazon Augmented AI (A2I)**

---

## 1.12 COMPARISON: AI vs ML vs DL vs NN vs GenAI vs Agentic AI

```
┌──────────────────────── ARTIFICIAL INTELLIGENCE ────────────────────────┐
│  (rules-based systems, expert systems, search, ...)                     │
│   ┌──────────────────── MACHINE LEARNING ─────────────────────────┐     │
│   │  (decision trees, XGBoost, k-means, linear regression, ...)   │     │
│   │   ┌──────────────── DEEP LEARNING (neural networks) ──────┐   │     │
│   │   │   ┌────────────── GENERATIVE AI ──────────────────┐   │   │     │
│   │   │   │  Foundation Models → LLMs, diffusion models   │   │   │     │
│   │   │   │  Agentic AI = FMs + planning + tools + memory │   │   │     │
│   │   │   └───────────────────────────────────────────────┘   │   │     │
│   │   └───────────────────────────────────────────────────────┘   │     │
│   └───────────────────────────────────────────────────────────────┘     │
└─────────────────────────────────────────────────────────────────────────┘
```

| | AI | ML | Neural Network | Deep Learning | Generative AI | Agentic AI |
|---|---|---|---|---|---|---|
| **What it is** | Any machine intelligence | Learns patterns from data | Layered structure of connected nodes | ML using many-layered NNs | DL models that create new content | FM-powered systems that plan & act |
| **Relationship** | Umbrella | Subset of AI | Building block of DL | Subset of ML | Subset of DL | Built on GenAI/FMs |
| **Needs data?** | Not always (rules) | Yes | Yes | Lots | Massive (pre-training) | Uses a pre-trained FM |
| **Output** | Decisions | Predictions | Predictions | Predictions / representations | Text, images, code, audio | **Actions + results** |
| **Example** | Chess engine with rules | Churn prediction | Digit recognizer | Face recognition | Write an email | Research, book, and pay an invoice |
| **AWS** | All AI services | SageMaker AI | SageMaker AI | Rekognition, Transcribe | Bedrock, Nova | Bedrock Agents, AgentCore, Strands |
| **Keyword** | "mimic human intelligence" | "learn from data" | "layers, nodes, weights" | "many layers, unstructured" | "generate, create" | "autonomous, multi-step, take actions, tools" |

---

## DOMAIN 1 — FAST RECAP
- AI ⊃ ML ⊃ DL ⊃ GenAI. Agentic AI = GenAI that **acts**.
- Supervised = labels (classification/regression). Unsupervised = no labels (clustering). RL = rewards.
- Inference types: **Real-time** (now), **Serverless** (sometimes), **Async** (large/slow), **Batch** (bulk).
- Overfit = great training, bad test. Underfit = bad everywhere.
- Precision → avoid false alarms. Recall → avoid misses. F1 → balance. Accuracy is misleading on imbalanced data.
- Lifecycle: Business goal → Data → Prepare → Features → Train → Tune → Evaluate → Deploy → Monitor → Retrain.
- MLOps = automation + repeatability + monitoring (SageMaker Pipelines, Model Registry, Model Monitor).
- Don't use ML when simple rules work or exact answers are required.

**➡ Continue to PART 2 — Domain 2: Fundamentals of Generative AI**
