# PART 2 — AIF-C01 MASTER NOTES

# DOMAIN 2 — FUNDAMENTALS OF GENERATIVE AI (24%)

The guide has three task statements:
- **2.1** Explain the basic concepts of generative AI (including **agentic AI**, **MCP**, multi-agent systems; new in v1.1)
- **2.2** Understand the capabilities and limitations of GenAI for solving business problems
- **2.3** Describe AWS infrastructure and technologies for building GenAI applications (including **token-based pricing**)

---

## 2.1 CORE GENAI BUILDING BLOCKS

### 2.1.1 Generative AI
- **Simple meaning:** AI that makes brand-new content (text, images, audio, video, code) when you ask it with a prompt.
- **Technical meaning:** Deep learning models (usually foundation models) that learn the patterns of their training data and **generate new, original outputs** with similar characteristics. Output is **probabilistic**: the model picks likely next pieces.
- **Real-world example:** "Write a product description for a waterproof hiking boot."
- **AWS example:** **Amazon Bedrock** (managed access to many FMs), Amazon Nova models, Amazon Quick, Kiro, Amazon Q Developer.
- **Exam keyword:** "create", "generate", "draft", "compose", "summarize", "conversational"
- **Common confusion:** GenAI vs predictive AI (see table 2.9).
- **Exam trap:** GenAI outputs can be **wrong (hallucinations)** and **vary each time (nondeterminism)**. Don't use it where exact, repeatable, fully explainable answers are legally required.
- **Memory trick:** **GenAI = a very well-read improviser.**

### 2.1.2 Foundation Model (FM)
- **Simple meaning:** One huge pre-trained model that can do many jobs.
- **Technical meaning:** A large model pre-trained on vast, broad data (self-supervised) that can be adapted to many downstream tasks. LLMs, multimodal models, image-generation models, and embedding models are all FMs.
- **AWS example:** Bedrock FMs: **Amazon Nova** (Micro = text-only, fastest/cheapest; Lite = low-cost multimodal; Pro = capable multimodal; Premier = most capable; **Nova Canvas** = image generation; **Nova Reel** = video generation; **Nova Sonic** = speech-to-speech; Nova Act = browser-action agent model), **Amazon Titan** (Titan Text Embeddings, Titan Multimodal Embeddings, Titan Image Generator), Anthropic Claude, Meta Llama, Mistral, Cohere (Command, Embed, Rerank), AI21 Labs, Stability AI (images), DeepSeek, OpenAI open-weight models, and more.
- **Exam keyword:** "pre-trained on large data", "general-purpose", "adaptable"
- **Memory trick:** **FM = Swiss Army knife model.**

### 2.1.3 Large Language Model (LLM)
- **Simple meaning:** An FM specialized in language. It reads text and writes text.
- **Technical meaning:** A transformer-based FM with billions of parameters, trained to predict the next token. It is used for text generation, summarization, Q&A, translation, and code.
- **Exam keyword:** "text generation", "language", "chat"
- **Exam trap:** LLM ⊂ FM. A question about image generation should not say "LLM".
- **Memory trick:** **L-L-M = Loves Language, Mostly.**

### LLM vs Foundation Model

| | Foundation Model | LLM |
|---|---|---|
| Scope | Any modality (text, image, audio, video, embeddings) | Text/language (some LLMs are multimodal) |
| Relationship | Umbrella category | A **type** of FM |
| Examples | Nova Canvas (images), Stable Diffusion, Titan Embeddings, Claude | Claude, Llama, Nova Pro, Mistral |
| Memory | Foundation for any building | The "language room" of the building |

### 2.1.4 Transformer
- **Simple meaning:** The model design that makes modern LLMs work. It reads all the words at once and figures out which words matter to each other.
- **Technical meaning:** A neural network architecture using **self-attention** to weigh the relationships between all tokens in a sequence **in parallel**. It is the basis of LLMs (GPT = Generative **Pre-trained Transformer**).
- **Real-world example:** In "The bank by the river", attention links "bank" with "river", so it means riverbank, not a money bank.
- **Exam keyword:** "attention mechanism", "self-attention", "parallel processing of sequences", "context of words"
- **Common confusion:** Transformer (text/LLMs) vs **diffusion** (images).
- **Exam trap:** Math details of attention are **OUT OF SCOPE**. Just know: transformers + attention → LLMs.
- **Memory trick:** **Transformer = pays ATTENTION to every word at once.**

### 2.1.5 Tokens
- **Simple meaning:** The small pieces of text a model reads and writes: a word, part of a word, or punctuation.
- **Technical meaning:** The basic units of text that an LLM processes. As a rule of thumb, **1 token ≈ 4 characters ≈ ¾ of an English word** (100 tokens ≈ 75 words). Models have **token limits**, and FMs are **priced per token**.
- **Real-world example:** "unbelievable" → "un" + "believ" + "able" = 3 tokens.
- **AWS example:** Bedrock on-demand pricing = **per 1,000 (or 1 million) input tokens + per 1,000 output tokens**.
- **Exam keyword:** "unit of text", "priced per token", "token limit", "max tokens"
- **Common confusion:** Token (a piece of text) vs embedding (a numeric meaning-vector).
- **Exam trap:** **Output tokens usually cost more than input tokens.** Long answers = more cost + more latency.
- **Memory trick:** **Tokens = LEGO bricks of text** (and you pay per brick).

### 2.1.6 Tokenization
- **Simple meaning:** Chopping text into tokens.
- **Technical meaning:** The process of converting raw text into a sequence of tokens (and token IDs) that the model can process.
- **Exam keyword:** "split text into units"
- **Exam trap:** Tokenization is different from chunking (chunking splits **documents** for RAG; tokenization splits **text** for the model).
- **Memory trick:** **Tokenize = Tiny pieces.**

### 2.1.7 Context window
- **Simple meaning:** How much text the model can "see" at one time: its short-term memory for one request.
- **Technical meaning:** The **maximum number of tokens** (input prompt + conversation history + retrieved documents + output) that a model can process in one request. Examples: 8K, 128K, 200K, 1M tokens.
- **Real-world example:** A model with a small context window can't read a 500-page contract at once.
- **AWS example:** Choosing a Bedrock model with a large context window for long document analysis.
- **Exam keyword:** "maximum input size", "long documents", "conversation history too long", "model forgets earlier parts"
- **Common confusion:** Context window (input+output capacity) vs **max tokens** (a setting that caps the **output** length).
- **Exam trap:** "Need to analyze very long documents in one request" → choose a model with a **larger context window** (or use chunking + RAG).
- **Memory trick:** **Context window = the size of the model's desk.** Everything must fit on the desk.

### 2.1.8 Input tokens vs Output tokens
- **Input tokens:** Everything you send (system prompt, instructions, examples, retrieved context, chat history, user question).
- **Output tokens:** Everything the model generates in response.
- **Cost:** Billed separately. **Output is typically priced higher** per token.
- **Latency:** More output tokens = longer generation time (the model generates tokens one by one).
- **Exam trap:** To cut cost/latency: shorten prompts, lower max output tokens, use **prompt caching** for repeated prefixes, choose a smaller model, use batch.
- **Memory trick:** **In = what you say. Out = what it says. Both cost; Out costs more.**

### 2.1.9 Embeddings
- **Simple meaning:** Turning text (or images) into a list of numbers that captures its **meaning**. Similar meanings get similar numbers.
- **Technical meaning:** Dense numerical **vector representations** of data (words, sentences, documents, images) in a multi-dimensional space where **semantic similarity = closeness**.
- **Real-world example:** "car" and "automobile" get embeddings that are very close. "car" and "banana" are far apart.
- **AWS example:** **Amazon Titan Text Embeddings**, Titan Multimodal Embeddings, **Cohere Embed**, Amazon Nova multimodal embeddings (in Bedrock). Knowledge Bases create embeddings automatically.
- **Exam keyword:** "numerical representation", "semantic meaning", "similarity search", "semantic search"
- **Common confusion:** Embedding vs token; embedding vs vector (an embedding **is** a vector, one that was created by an embedding model to capture meaning).
- **Exam trap:** "Search by meaning, not exact keywords" → **embeddings + vector search** (semantic search).
- **Memory trick:** **Embedding = the GPS coordinates of meaning.**

### 2.1.10 Vectors
- **Simple meaning:** A list of numbers, like [0.12, -0.8, 0.33, …].
- **Technical meaning:** An ordered array of numbers representing a point in multi-dimensional space. Embeddings are stored as vectors (e.g., 1,024 dimensions).
- **Exam keyword:** "vector", "dimensions", "similarity (cosine/distance)"
- **Common confusion:** Vector = the **data format**. Embedding = a vector **with meaning** produced by a model.
- **Memory trick:** **Vector = the container of numbers; embedding = what's inside it (meaning).**

### 2.1.11 Chunking
- **Simple meaning:** Cutting big documents into smaller pieces before storing them for search.
- **Technical meaning:** Splitting source documents into smaller segments ("chunks") before embedding them, so each piece fits the embedding model's limits and retrieval returns **focused, relevant** passages. Strategies: **fixed-size** (with overlap), **semantic**, **hierarchical**, **no chunking** (one doc = one chunk).
- **Real-world example:** A 300-page manual split into 500-token chunks.
- **AWS example:** Bedrock Knowledge Bases let you choose the chunking strategy (default, fixed-size, hierarchical, semantic, none) or use custom Lambda chunking.
- **Exam keyword:** "split documents", "chunk size", "overlap", "retrieval returns irrelevant/too-large passages"
- **Exam trap:** Chunks **too large** → irrelevant info, higher cost, context overflow. Chunks **too small** → lost context. Tuning the chunk size can improve RAG accuracy.
- **Memory trick:** **Chunking = slicing a pizza so each slice fits in your mouth.**

### 2.1.12 Vector database (vector store)
- **Simple meaning:** A database that stores embeddings and quickly finds the ones **most similar** to your question.
- **Technical meaning:** A data store optimized for storing vectors and running **similarity (nearest-neighbor) search**. It is the core of RAG.
- **AWS options (MEMORIZE):**
  - **Amazon OpenSearch Service / OpenSearch Serverless**: vector search engine (the **default "quick create"** store for Bedrock Knowledge Bases). Keyword: "vector search, full-text + semantic (hybrid) search, scalable".
  - **Amazon Aurora PostgreSQL** (with **pgvector**): keyword: "already uses relational DB/PostgreSQL".
  - **Amazon RDS for PostgreSQL** (with **pgvector**): keyword: "PostgreSQL, managed relational".
  - **Amazon Neptune (Neptune Analytics)**: graph database. Keyword: "**GraphRAG**, relationships between entities, knowledge graph".
  - **Amazon S3 Vectors**: low-cost, large-scale vector storage in S3. Keyword: "cheapest, massive vector storage, infrequent queries".
  - **Amazon DocumentDB**, **Amazon MemoryDB** (fast in-memory vector search), and **Amazon ElastiCache (Valkey)** also support vectors.
  - Third party (supported by Knowledge Bases): Pinecone, Redis Enterprise Cloud, MongoDB Atlas.
- **Exam keyword:** "store embeddings", "similarity search", "semantic search", "vector store"
- **Exam trap:** Amazon **DynamoDB** and **Redshift** are **not** the typical answers for a vector store in AIF-C01 questions.
- **Memory trick:** **"OpenSearch, Aurora, RDS-Postgres, Neptune" = O-A-R-N ("OAR-N the boat of vectors").**

### Tokens vs Embeddings vs Vectors vs Chunking

| | Tokens | Embeddings | Vectors | Chunking |
|---|---|---|---|---|
| What | Small pieces of text | Meaning as numbers | List of numbers (format) | Splitting documents into pieces |
| Size | Sub-word units | Hundreds–thousands of dimensions | Any length | e.g., 300–1,000 tokens per chunk |
| Purpose | Model input/output & **billing** | **Semantic similarity** | Store/compare numbers | Prepare docs for **RAG** retrieval |
| Where used | Every prompt/response | RAG, search, recommendations | Vector DBs | Knowledge base ingestion |
| AWS | Bedrock token pricing | Titan/Cohere/Nova Embeddings | OpenSearch, Aurora, Neptune | Bedrock Knowledge Bases chunking settings |
| Memory | LEGO bricks | GPS of meaning | Container of numbers | Pizza slices |

**RAG data flow (memorize the order):**
`Documents → Chunking → Embedding model → Vectors stored in Vector DB → User question embedded → Similarity search → Top chunks added to prompt → FM generates grounded answer`

### 2.1.13 Multimodal models
- **Simple meaning:** Models that understand or create **more than one type** of data: text + images (+ audio/video).
- **Technical meaning:** FMs that accept and/or produce multiple **modalities** (text, image, audio, video) in one model.
- **Example:** Upload a photo of a broken part and ask "What is this and how do I fix it?"
- **AWS example:** Amazon Nova Lite/Pro/Premier (text+image+video input), Claude (text+image), **Titan Multimodal Embeddings / Nova multimodal embeddings** (search images with text), **Bedrock Data Automation** (extract insights from documents, images, audio, video).
- **Exam keyword:** "text and images together", "multiple data types", "describe an image"
- **Exam trap:** "Search a product catalog of images using text queries" → **multimodal embeddings**.
- **Memory trick:** **Multi-modal = Multiple senses.**

### 2.1.14 Diffusion models
- **Simple meaning:** Image generators that start from random noise ("TV static") and gradually clean it up into a picture that matches your prompt.
- **Technical meaning:** Generative models trained to **reverse a noise-adding process**. They generate images (or audio/video) by iterative **denoising**.
- **Example:** "A red fox in the snow, watercolor style" → image.
- **AWS example:** **Stability AI** (Stable Diffusion/Stable Image) in Bedrock; Amazon Nova Canvas; Titan Image Generator.
- **Exam keyword:** "image generation", "noise", "denoising", "text-to-image"
- **Common confusion:** Diffusion (images from noise) vs transformer (text). Older **GANs** (Generative Adversarial Networks: a generator vs a discriminator) and **VAEs** (Variational Autoencoders) are other generative architectures (just know the names).
- **Memory trick:** **Diffusion = De-noise into an image.**

### Other model types to recognize (names only)
| Model type | One-liner |
|---|---|
| **GAN** | Two networks compete: a generator makes fakes, a discriminator judges them |
| **VAE** | Compresses data to a latent space and generates new samples from it |
| **Embedding model** | Outputs vectors, not text |
| **Reranker model** | Re-orders retrieved results by relevance (e.g., Cohere Rerank, Amazon Rerank) |
| **Small Language Model (SLM)** | Smaller, faster, cheaper LLM (e.g., Nova Micro); can run at the edge |

### IF THE QUESTION SAYS… → THINK…
29. "Convert text into numerical representations that capture meaning" → **Embeddings**
30. "Search documents by meaning rather than exact keywords" → **Semantic search: embeddings + vector database**
31. "Split long documents into smaller parts before indexing" → **Chunking**
32. "Model can't process the whole document in one request" → **Context window limit** → bigger context model or chunking/RAG
33. "Generate images from text descriptions" → **Diffusion model** (Stability AI / Nova Canvas in Bedrock)
34. "Understand an image and answer questions about it" → **Multimodal model**
35. "Store embeddings and find relationships between entities (knowledge graph)" → **Amazon Neptune (GraphRAG)**
36. "Company already uses PostgreSQL and wants vector search" → **Aurora PostgreSQL / RDS for PostgreSQL with pgvector**

---

## 2.2 PROMPT ENGINEERING & CONTEXT ENGINEERING (INTRO, DETAILS IN PART 3)

### 2.2.1 Prompt engineering
- **Simple meaning:** Writing your request to the AI in a smart way so you get better answers, without changing the model.
- **Technical meaning:** Designing and refining input prompts (instructions, context, examples, output format) to guide an FM toward accurate, relevant output. **Model weights do not change.**
- **Example:** Bad: "Tell me about our product." Good: "You are a support agent. In 3 bullet points, explain the return policy below to a customer. Use a friendly tone."
- **AWS example:** Bedrock playgrounds, **Bedrock Prompt Management** (save, version, reuse prompts).
- **Exam keyword:** "improve output without training", "lowest cost/effort", "instructions", "examples in prompt"
- **Exam trap:** Prompt engineering is **the cheapest and fastest** first step. Try it before RAG or fine-tuning.
- **Memory trick:** **Prompt engineering = asking better questions.**

### 2.2.2 Context engineering (NEW in v1.1)
- **Simple meaning:** Carefully deciding **what information goes into the model's context window**, not just how the question is worded. This includes the right documents, memory, tool results, and instructions, at the right size.
- **Technical meaning:** The practice of designing and managing the **entire context** given to an FM or agent: system instructions, retrieved knowledge (RAG), conversation history, agent memory, tool definitions and tool outputs, examples, and structured data. The goal is to maximize relevance and accuracy within the context window while controlling cost and latency.
- **Real-world example:** A support agent gets the customer's profile, the last 3 messages (not all 300), the 4 most relevant policy chunks, and the list of available tools. That's context engineering.
- **AWS example:** Bedrock Knowledge Bases (retrieval), AgentCore Memory (short/long-term memory), prompt caching (reusing static context), Bedrock Prompt Management (templates).
- **Exam keyword:** "what information to include in the context", "manage conversation history", "memory", "relevant context", "too much context degrades answers"
- **Common confusion:** **Prompt engineering = HOW you ask. Context engineering = WHAT the model knows when it answers.**
- **Exam trap:** Stuffing **more** context isn't always better. Irrelevant context raises cost and latency and can **reduce accuracy**. Curate it: retrieve only relevant chunks, summarize old history.
- **Memory trick:** **Prompt = the question. Context = the briefing folder you hand the model.**

---

## 2.3 FOUNDATION MODEL LIFECYCLE

**Memorize the order (ordering question!):**

1. **Data selection** → choose/curate large, diverse, high-quality training data
2. **Model selection** → choose the architecture / pre-existing FM that fits the use case
3. **Pre-training** → train on massive unlabeled data (self-supervised). Hugely expensive.
4. **Fine-tuning** → adapt with smaller, task-specific (often labeled) data
5. **Evaluation** → measure quality, safety, bias (benchmarks, human eval, metrics)
6. **Deployment** → serve the model for inference (Bedrock, SageMaker endpoint)
7. **Feedback** → collect user feedback and monitor, then improve (retrain/re-tune/update prompts)

**Memory trick:** "**D**on't **M**ake **P**izza **F**or **E**veryone **D**uring **F**asting" → Data selection, Model selection, Pre-training, Fine-tuning, Evaluation, Deployment, Feedback.

| Stage | Simple meaning | Who usually does it | AWS |
|---|---|---|---|
| Data selection | Pick good data | Model builder | S3, Glue, Ground Truth |
| Model selection | Pick the right base model | **You** | Bedrock model catalog, JumpStart, Bedrock Model Evaluation |
| Pre-training | Teach general knowledge | Model provider (Amazon, Anthropic, Meta…) | (SageMaker HyperPod for builders) |
| Fine-tuning | Specialize | **You** (optional) | Bedrock customization, SageMaker |
| Evaluation | Test it | **You** | Bedrock Model Evaluation, SageMaker Clarify |
| Deployment | Serve it | **You** | Bedrock (on-demand/provisioned), SageMaker endpoints |
| Feedback | Improve over time | **You** | CloudWatch, user ratings, A2I |

**Exam trap:** Most companies **skip pre-training**. They select an existing FM, then customize it with prompting, RAG, or fine-tuning.

---

## 2.4 GENAI USE CASES

| Use case | What it looks like | AWS example |
|---|---|---|
| **Text generation** | Marketing copy, emails, reports | Bedrock (Nova, Claude) |
| **Summarization** | Summarize calls, meetings, long reports | Bedrock; Transcribe + Bedrock for calls |
| **Translation** | Translate with tone/style | Amazon Translate (standard), Bedrock LLM (context-aware) |
| **Chatbots** | Conversational Q&A | Bedrock + Knowledge Bases; Amazon Lex |
| **AI assistants** | Help employees work (search, draft, act) | **Amazon Quick**, Amazon Q Business, Bedrock Agents |
| **Code generation** | Write/explain/test code | **Kiro**, Amazon Q Developer, Bedrock |
| **Image generation** | Product images, ads | Nova Canvas, Stability AI |
| **Video generation** | Short marketing videos | **Nova Reel** |
| **Audio generation** | Voices, speech | **Amazon Polly** (TTS), **Nova Sonic** (speech-to-speech conversational) |
| **Search** | Semantic/enterprise search | Bedrock Knowledge Bases, OpenSearch, Kendra |
| **Recommendations** | Personalized suggestions (GenAI-enhanced) | **Amazon Personalize**, Bedrock (descriptions) |
| **Customer service** | Agent assist, automated responses, call summaries | Amazon Connect (contact center, with AI features), Bedrock, Lex |
| **Document processing** | Extract & summarize documents | Textract + Bedrock; Bedrock Data Automation |
| **AI agents** | Complete multi-step tasks | Bedrock Agents, AgentCore, Strands Agents |

### IF THE QUESTION SAYS… → THINK…
37. "Generate short marketing videos from text" → **Amazon Nova Reel** (Bedrock)
38. "Developer assistant that writes code from specifications" → **Kiro** (agentic IDE) / Amazon Q Developer
39. "Employees need an AI assistant that answers questions from company data and automates workflows" → **Amazon Quick** (or Amazon Q Business)
40. "Summarize customer call recordings" → **Transcribe** (speech→text) + **Bedrock** (summarize)

---

## 2.5 AGENTIC AI (EXPLAINED SIMPLY) — NEW & IMPORTANT

### Start with a story
- A **chatbot** is like a very smart librarian. You ask, and it **tells you** the answer.
- An **agent** is like a personal assistant. You give it a **goal**, and it **figures out the steps, uses tools (apps, APIs, databases), remembers things, and does the work**, checking results along the way.

Goal: *"Refund order #123 if it arrived damaged."*
1. **Reason/plan:** "I need to check the order, check the damage report, then refund."
2. **Use tool:** call the Order API → gets order details.
3. **Use tool:** check the damage-claim database → damage confirmed.
4. **Act:** call the Payment API → refund issued.
5. **Respond:** "Your refund of $45 has been issued."

This loop is often called **ReAct** (Reason + Act): *think → act (tool) → observe the result → think again → … → final answer*.

### 2.5.1 AI agent
- **Simple meaning:** An AI program that can take actions to complete a goal, not just talk.
- **Technical meaning:** A system where an FM acts as the "brain" that **reasons, plans, and decides which tools to call**. It uses **memory** and **tools/APIs** to complete multi-step tasks with some autonomy.
- **The 4 parts of an agent (memorize):**
  1. **Model (brain):** the FM that reasons and plans
  2. **Instructions (goal/role):** what the agent should do and how to behave
  3. **Tools (hands):** APIs, functions, databases, knowledge bases, code interpreter, browser
  4. **Memory:** short-term (this conversation) + long-term (facts remembered across sessions)
- **AWS example:** **Amazon Bedrock Agents** (fully managed: define instructions, **action groups** (tools via Lambda + API schema), knowledge bases); **Amazon Bedrock AgentCore** (run any agent framework securely at scale); **Strands Agents** (open-source Python SDK from AWS to build agents in a few lines of code).
- **Exam keyword:** "perform actions", "call APIs", "multi-step", "autonomously complete tasks", "orchestrate", "book", "update records"
- **Common confusion:** Agent vs RAG. RAG = **look things up and answer**. Agent = **plan + act** (and can use RAG as one tool).
- **Exam trap:** If the scenario requires **changing something in another system** (create a ticket, process a refund, update inventory), the answer is an **agent**, not just a knowledge base.
- **Memory trick:** **Agent = Brain (FM) + Hands (tools) + Notebook (memory) + Job description (instructions).**

### 2.5.2 Agentic AI
- **Simple meaning:** The overall approach of building AI systems that act on their own toward goals.
- **Technical meaning:** AI systems characterized by **autonomy, goal-directed planning, tool use, memory, and iterative reasoning**, often with **human-in-the-loop** checkpoints for high-risk actions.
- **Exam trap:** More autonomy = more risk. Use **guardrails, least-privilege permissions (AgentCore Identity/Policy), human approval for sensitive actions, logging/observability**.

### 2.5.3 Tool use (function calling)
- **Simple meaning:** The model asks to use an outside tool, like a calculator, weather API, or database, to get information or do something.
- **Technical meaning:** The FM is given **tool definitions** (name, description, input schema). It outputs a structured request to call a tool. The application/agent runs the tool and feeds the result back to the model.
- **AWS example:** Bedrock **Converse API tool use**; Bedrock Agents **action groups** (Lambda functions + OpenAPI schema); AgentCore Gateway (turns APIs/Lambdas into MCP tools); AgentCore **Code Interpreter** and **Browser** tools.
- **Exam keyword:** "call external APIs", "real-time data", "function calling"
- **Exam trap:** The **model itself doesn't run the code**. It *requests* the tool call, and the application or agent runtime executes it.
- **Memory trick:** **Tools = the agent's hands.**

### 2.5.4 Agent memory
- **Simple meaning:** What the agent remembers: in this conversation, and across past conversations.
- **Technical meaning:**
  - **Short-term (session) memory:** the current conversation's messages/state, kept in the context window.
  - **Long-term memory:** facts, user preferences, and summaries stored outside the model (e.g., in a database) and retrieved when needed across sessions.
- **AWS example:** **AgentCore Memory** (managed short-term + long-term memory); Bedrock Agents memory (session summaries retained across sessions).
- **Exam keyword:** "remember user preferences across sessions", "retain conversation context"
- **Exam trap:** FMs are **stateless**. They don't remember previous calls by themselves. Memory must be **managed and passed in** (context engineering).
- **Memory trick:** **Short-term = sticky note. Long-term = diary.**

### 2.5.5 Workflow orchestration
- **Simple meaning:** Organizing the steps of a task in the right order: who does what, and when.
- **Technical meaning:** Coordinating a sequence of steps (prompts, model calls, tool calls, conditions, loops, human approvals) in a GenAI application. It can be **model-driven** (the agent decides the steps dynamically) or **predefined** (a fixed workflow).
- **AWS example:** **Amazon Bedrock Flows** (visual builder to link prompts, KBs, agents, and Lambda into a workflow); Bedrock Agents orchestration; **AWS Step Functions** (general workflow orchestration); Strands Agents.
- **Exam keyword:** "sequence of steps", "chain prompts", "predefined workflow", "coordinate"
- **Exam trap:** Fixed, predictable steps → a **workflow (Bedrock Flows / Step Functions)**. Dynamic decisions → an **agent**.
- **Memory trick:** **Orchestration = conductor of the orchestra.**

### 2.5.6 Multi-agent systems
- **Simple meaning:** A team of specialized AI agents working together, like a company with different departments.
- **Technical meaning:** Multiple agents, each with a specialized role, tools, and instructions, that **collaborate** to solve complex tasks.
- **Common patterns (know the names):**
  - **Supervisor / orchestrator (hierarchical):** a supervisor agent breaks down the task and delegates to sub-agents, then combines the results. (Bedrock **multi-agent collaboration** uses a supervisor agent.)
  - **Sequential (pipeline):** Agent A → Agent B → Agent C, each passing output to the next.
  - **Parallel:** several agents work at the same time on different parts, then results are merged.
  - **Peer-to-peer / swarm (network):** agents communicate with each other directly and hand off tasks.
  - **Agent-as-a-tool:** one agent calls another agent like a tool.
- **Communication:** Agents talk via messages. Protocols include **MCP** (agent ↔ tools/data) and **A2A (Agent-to-Agent protocol)** (agent ↔ agent).
- **Real-world example:** Travel planning: a supervisor agent delegates to a flight agent, a hotel agent, and a budget agent.
- **AWS example:** Bedrock Agents **multi-agent collaboration** (supervisor + collaborators); Strands Agents (multi-agent patterns: graph, swarm, workflow); AgentCore Runtime hosts them.
- **Exam keyword:** "specialized agents", "supervisor agent", "delegate subtasks", "collaborate", "complex task split"
- **Exam trap:** One agent with too many tools gets confused. **Split it into specialized agents** coordinated by a supervisor.
- **Memory trick:** **Multi-agent = a team with a manager.**

### 2.5.7 Model Context Protocol (MCP) — explained simply
- **Simple meaning:** **MCP is like a universal USB-C port for AI.** Before USB-C, every device needed a different cable. Before MCP, every AI app needed custom code to connect to every tool (Slack, GitHub, databases, weather APIs). With MCP, a tool is wrapped once as an **"MCP server"**, and **any MCP-compatible AI app/agent (an "MCP client") can plug into it**.
- **Technical meaning:** MCP is an **open standard protocol** (created by Anthropic, widely adopted including by AWS) that standardizes how AI applications/agents connect to **external tools, data sources, and prompts**.
  - **MCP host / client:** the AI application or agent (e.g., Kiro, Amazon Q Developer, your Strands agent).
  - **MCP server:** a program that exposes **tools** (actions), **resources** (data), and **prompts** (templates) in a standard format.
- **Real-world example:** Your company builds one "Inventory MCP server". Now your coding assistant, your customer-service agent, and your analytics agent can all use it without custom integration for each.
- **AWS example:**
  - **AgentCore Gateway** converts existing APIs, Lambda functions, and services into **MCP-compatible tools** that agents can discover and use securely.
  - **AWS MCP servers** (open-source) let agents interact with AWS services and documentation.
  - **Kiro**, **Amazon Q Developer**, **Strands Agents**, and **Amazon Quick** support MCP.
- **Exam keyword:** "standard way to connect agents to external tools/data", "open protocol", "interoperability", "reuse tool integrations across agents", "MCP server"
- **Common confusion:** MCP is **not a model** and **not an AWS service**. It's a **protocol (a set of rules for communication)**. MCP connects **agents to tools/data**; A2A connects **agents to other agents**.
- **Exam trap:** "Connect agents to many external systems without building custom integrations for each" → **MCP** (e.g., via AgentCore Gateway).
- **Memory trick:** **MCP = "My Connector Plug" = USB-C for AI tools.**

```
  [AI Agent / App]  ← MCP client
        │  (standard MCP messages)
   ┌────┼──────────────┬──────────────┐
   ▼    ▼              ▼              ▼
[MCP server: DB] [MCP server: Slack] [MCP server: Weather API]
```

### 2.5.8 Connecting agents to external systems (summary)
| Method | What | AWS |
|---|---|---|
| Action groups | Define APIs (OpenAPI schema) + Lambda for an agent | Bedrock Agents |
| Tool use / function calling | Model requests tool calls | Bedrock Converse API |
| MCP | Standard protocol for tools/data | AgentCore Gateway, Strands, Kiro |
| Knowledge base | Read-only access to documents (RAG) | Bedrock Knowledge Bases |
| Browser / code tools | Browse websites, run code in a sandbox | AgentCore Browser, AgentCore Code Interpreter |
| Secure credentials | Agent gets **least-privilege** access to third-party systems (OAuth, API keys) | **AgentCore Identity** |
| Rules on tool calls | Allow/deny specific tool actions deterministically | **Policy in AgentCore** (Cedar policies at the Gateway) |

### 2.5.9 Amazon Bedrock AgentCore (overview; details in Part 5 & 6)
- **Simple meaning:** AWS's "operating platform" for AI agents. You build an agent with any framework (Strands, LangGraph, CrewAI…) and any model, and AgentCore **runs it securely at scale** with memory, tools, identity, and monitoring.
- **Components (memorize the names):**
  | Component | Simple meaning |
  |---|---|
  | **Runtime** | Serverless hosting for agents (secure, session-isolated, long-running tasks) |
  | **Memory** | Managed short-term + long-term memory |
  | **Gateway** | Turns APIs/Lambdas/services into **MCP tools** for agents |
  | **Identity** | Agent identity & credential management: who the agent is and what it can access (OAuth, API keys, least privilege) |
  | **Policy** | Deterministic rules (Cedar) controlling which tool calls an agent can make |
  | **Code Interpreter** | Secure sandbox to run code |
  | **Browser** | Secure cloud browser for agents to use websites |
  | **Observability** | Tracing, monitoring, debugging agent steps (CloudWatch) |
  | **Evaluations** | Continuously evaluate agent quality |
- **Bedrock Agents vs AgentCore:** Bedrock Agents = **quick, fully managed, configuration-based** agents inside Bedrock. AgentCore = **flexible infrastructure** to deploy/operate agents built with **any framework and any model**, at enterprise scale.

### 2.5.10 Strands Agents & Kiro
- **Strands Agents:** an **open-source SDK** from AWS for building agents with a **model-driven** approach (you give a model, a prompt, and tools, and the model plans the steps). It supports MCP and multi-agent patterns, and deploys to AgentCore/Lambda/containers. **Keyword:** "open-source SDK to build agents with few lines of code".
- **Kiro:** an AWS **agentic IDE** (AI coding environment). It uses **spec-driven development** (turns prompts into requirements → design → tasks → code) and **agent hooks** (automations triggered by events like saving a file). It supports MCP. **Keyword:** "AI-powered IDE", "specs to production code".

### IF THE QUESTION SAYS… → THINK…
41. "AI must complete multi-step tasks and call company APIs (e.g., process refunds)" → **Agent: Bedrock Agents / AgentCore**
42. "Standard, reusable way to connect agents to external tools and data sources" → **Model Context Protocol (MCP)**
43. "Convert existing APIs/Lambda functions into tools agents can use" → **AgentCore Gateway**
44. "Agent must remember user preferences across sessions" → **Agent memory (AgentCore Memory, long-term)**
45. "Complex task split among specialized agents coordinated by one agent" → **Multi-agent system, supervisor pattern** (Bedrock multi-agent collaboration)
46. "Deploy agents built with open-source frameworks securely at scale" → **Amazon Bedrock AgentCore (Runtime)**
47. "Open-source SDK from AWS for building agents" → **Strands Agents**
48. "Chain prompts, KBs, and Lambda in a fixed visual workflow" → **Amazon Bedrock Flows**

---

## 2.6 CAPABILITIES & ADVANTAGES OF GENAI

| Advantage | Simple meaning |
|---|---|
| **Adaptability** | One model handles many tasks |
| **Responsiveness** | Real-time, conversational interaction |
| **Simplicity** | Natural-language interface; no ML expertise needed to use it |
| **Scalability** | Generate content at massive scale |
| **Creativity / content creation** | New ideas, drafts, variations |
| **Personalization** | Tailored responses per user |
| **Speed to market** | Use pre-trained FMs; no need to train from scratch |
| **Handles unstructured data** | Understands text, images, audio |

---

## 2.7 LIMITATIONS & DISADVANTAGES OF GENAI (VERY TESTABLE)

### 2.7.1 Hallucinations
- **Simple meaning:** The model confidently makes things up. It sounds right but it's false.
- **Technical meaning:** Generated content that is **factually incorrect, fabricated, or not grounded** in the source data, but presented fluently and confidently.
- **Real-world example:** A chatbot cites a court case or a company policy that doesn't exist.
- **Fixes/Mitigation:** **RAG** (ground answers in trusted data), **Bedrock Guardrails contextual grounding check** (detects/blocks ungrounded answers), **Automated Reasoning checks** (mathematically verify answers against policy rules), lower **temperature**, prompt instructions ("say 'I don't know' if not in context"), citations, human review, evaluation.
- **Exam keyword:** "made-up", "fabricated", "confidently incorrect", "not in the source documents"
- **Common confusion:** Hallucination (made-up facts) vs bias (unfair outputs toward groups) vs toxicity (harmful/offensive language).
- **Exam trap:** Fine-tuning does **not** reliably fix hallucinations about **changing/private facts**. **RAG + grounding checks** is the better answer.
- **Memory trick:** **Hallucination = the model is dreaming.**

### 2.7.2 Inaccuracy
- Outputs can be wrong or outdated. FMs have a **knowledge cutoff** (they don't know events after their training data ended) and don't know your private data. → Use **RAG** for current/private info.

### 2.7.3 Nondeterminism
- **Simple meaning:** Ask the same question twice, get different answers.
- **Technical meaning:** Generation involves probabilistic sampling, so outputs can vary across runs, especially with **higher temperature/top-p**.
- **Fix:** Lower temperature (toward 0), fixed prompts/templates, structured output formats.
- **Exam keyword:** "inconsistent responses", "different answer each time"
- **Exam trap:** Even temperature 0 isn't a guarantee of perfect consistency, but it's the **best available lever**.
- **Memory trick:** **Nondeterministic = Not the same twice.**

### 2.7.4 Interpretability (lack of)
- **Simple meaning:** It's hard to know **why** a large model gave a specific answer: a "black box".
- **Technical meaning:** Low interpretability because of billions of parameters. This makes auditing and regulated use harder.
- **Fix:** Use simpler/traditional models when explanations are legally required; add citations (RAG); use documentation (model cards, AI Service Cards); use SageMaker Clarify for explainability of traditional models.
- **Exam trap:** "Regulator requires explanation of each loan decision" → prefer an **interpretable traditional ML model** (+ Clarify), not a large FM.

### 2.7.5 Other limitations
| Limitation | Meaning | Mitigation |
|---|---|---|
| **Toxicity** | Offensive/harmful output | Bedrock Guardrails content filters |
| **Bias** | Unfair outputs for groups | Diverse data, evaluation, Clarify, guardrails |
| **IP / copyright risk** | Output may resemble copyrighted material | Review, indemnified models, policies |
| **Data privacy** | Sensitive data in prompts/outputs | Guardrails PII filters, Macie, encryption |
| **Cost** | Token costs can grow fast | Smaller models, caching, batch |
| **Latency** | Large models are slower | Smaller models, latency-optimized inference, streaming |
| **Knowledge cutoff** | Doesn't know recent events | RAG, tools/web search |
| **Prompt attacks** | Injection, jailbreaking | Guardrails prompt-attack filter, input validation |

### IF THE QUESTION SAYS… → THINK…
49. "Model gives confident but false answers" → **Hallucination** → mitigate with **RAG + Guardrails contextual grounding check**
50. "Same prompt returns different answers each time" → **Nondeterminism** → **lower temperature**
51. "Model doesn't know about events after its training" → **Knowledge cutoff** → **RAG / tools**
52. "Regulators need to understand exactly why each decision was made" → **Interpretability issue** → prefer traditional, explainable model

---

## 2.8 MODEL SELECTION FACTORS (DOMAIN 2 VIEW; MORE IN PART 3)

| Factor | Question to ask | Example |
|---|---|---|
| **Model type / modality** | Text, image, video, audio, embedding? | Need images → Nova Canvas / Stability AI |
| **Capabilities / performance** | Can it do the task well (reasoning, code, languages)? | Benchmarks, Bedrock Model Evaluation |
| **Model complexity / size** | Bigger = smarter but slower and pricier | Nova Micro (fast/cheap) vs Nova Premier (most capable) |
| **Latency** | How fast must it respond? | Real-time chat → smaller/faster model |
| **Cost** | Price per input/output token | High volume → cheaper model |
| **Context window** | How much input can it take? | Long contracts → large context |
| **Multilingual** | Does it support needed languages? | Global customer service |
| **Customization** | Can it be fine-tuned in Bedrock? | Need fine-tuning → check support |
| **Compliance** | Data residency, licensing, regulations | Region availability, license terms |
| **Constraints** | Throughput quotas, availability | Provisioned throughput |

**Golden rule:** Choose the **smallest, cheapest model that meets the quality requirement**.

---

## 2.9 KEY COMPARISONS

### Traditional ML vs Foundation Models vs Generative AI

| | Traditional ML | Foundation Models | Generative AI |
|---|---|---|---|
| What | Model trained for **one specific task** | Large pre-trained general-purpose model | Applications/models that **create** content (usually built on FMs) |
| Training data | Task-specific, often **labeled** | Massive, broad, **unlabeled** | (Uses FMs) |
| Tasks | One (e.g., fraud detection) | Many | Many generative tasks |
| Output | Label / number | Depends (text, embeddings, images) | New content |
| Build effort | Collect data, train from scratch | Use as-is or customize | Prompting, RAG, fine-tuning |
| Explainability | Higher | Low | Low |
| Cost per prediction | Low | Higher (per token) | Higher |
| AWS | SageMaker AI | Bedrock, JumpStart | Bedrock, Nova, Quick, Kiro |

### Generative AI vs Predictive AI

| | Predictive (traditional/discriminative) AI | Generative AI |
|---|---|---|
| Question | "What will happen / what is this?" | "Create something new" |
| Output | Label, score, number | Text, image, audio, code |
| Example | "This email is spam (97%)" | "Write a polite reply to this email" |
| Data | Structured/labeled | Massive unstructured |
| Determinism | More consistent | Nondeterministic |
| AWS | SageMaker, Comprehend, Rekognition, Personalize | Bedrock, Nova |
| Memory trick | **Predicts** | **Produces** |

---

## 2.10 AWS INFRASTRUCTURE FOR GENAI (TASK 2.3)

### 2.10.1 Amazon Bedrock (the #1 service of this exam)
- **Simple meaning:** A fully managed AWS service that gives you access to many top foundation models through **one API**, **without managing any servers**.
- **Technical meaning:** Serverless service offering FMs from Amazon (Nova, Titan) and third parties (Anthropic, Meta, Mistral, Cohere, AI21, Stability AI, DeepSeek, OpenAI open-weight, and others). It includes tools to customize (fine-tuning, continued pre-training, distillation), ground (Knowledge Bases), protect (Guardrails), evaluate (Model Evaluation), build agents (Agents, AgentCore), orchestrate (Flows), and manage prompts (Prompt Management).
- **Key facts (MEMORIZE):**
  - **Your data is NOT used to train the base FMs** and is **not shared with model providers**.
  - Data is **encrypted** in transit and at rest (you can use your own **KMS** keys).
  - Supports **VPC / AWS PrivateLink** for private connectivity.
  - Logged by **CloudTrail** (API calls). **Model invocation logging** can log prompts/responses to CloudWatch Logs/S3.
  - Compliant with many standards (SOC, ISO, HIPAA eligible, GDPR, etc.).
  - **Model access** must be enabled per model (IAM controls who can invoke which models).
- **Exam keyword:** "access multiple FMs via API", "serverless", "no infrastructure", "build GenAI apps quickly"
- **Memory trick:** **Bedrock = the bedrock (foundation) of GenAI on AWS: a model buffet via one API.**

### 2.10.2 Amazon SageMaker AI (for GenAI)
- Build, train, fine-tune, and deploy **your own** models with **full control** over infrastructure. **SageMaker JumpStart** = model hub with hundreds of pre-trained/open-source FMs and solutions you can deploy to your own SageMaker endpoints with a few clicks. **SageMaker HyperPod** = resilient clusters for large-scale FM training (LOW PRIORITY detail).
- **Bedrock vs SageMaker:** Bedrock = **serverless, API, least operational effort**. SageMaker = **full control, custom training, choose instance types, more ops effort**.

### 2.10.3 Other GenAI tools on AWS
| Tool | What | Keyword |
|---|---|---|
| **PartyRock** | Free, no-code Bedrock **playground** to learn/experiment by building mini GenAI apps | "experiment, learn, no AWS account/no code" |
| **Amazon Q Developer** | AI assistant for developers (code, AWS console help, transformations) | "developer productivity" |
| **Kiro** | Agentic AI IDE, spec-driven development | "AI IDE", "spec-driven" |
| **Amazon Quick** (Quick Suite) | Agentic AI workspace for business users: chat with company data, research, BI dashboards (QuickSight), automate workflows | "employee assistant", "insights + automation" |
| **Amazon Q Business** | GenAI assistant over enterprise data (related to Quick) | "enterprise Q&A over company data" |
| **Bedrock Studio / SageMaker Unified Studio** | Collaborative environment to build GenAI apps | "team builds GenAI apps" |

### 2.10.4 Advantages of AWS GenAI services
- **Accessibility / lower barrier to entry** (no ML expertise needed with Bedrock/Quick)
- **Efficiency** (managed, serverless, no infrastructure)
- **Cost-effectiveness** (pay-as-you-go per token)
- **Speed to market** (pre-trained FMs, templates)
- **Security & compliance** (IAM, KMS, PrivateLink, data not used for training)
- **Choice** (many models; switch easily)

### 2.10.5 Token-based pricing & cost tradeoffs (NEW emphasis in v1.1)

| Pricing option | How it works | Best for | Keyword |
|---|---|---|---|
| **On-demand** | Pay per input + output token; no commitment | Variable, unpredictable, prototyping | "pay-as-you-go", "no commitment" |
| **Batch inference** | Submit many prompts as a file (S3); results later; **~50% cheaper** | Large, non-urgent workloads | "large volume, not time sensitive" |
| **Provisioned Throughput** | Buy dedicated model units for a time commitment (hourly; no commitment, 1-month or 6-month) | **Consistent high throughput**, guaranteed capacity; **required for most custom (fine-tuned) models** | "guaranteed throughput", "custom model", "predictable heavy use" |
| **Prompt caching** | Cache repeated prompt prefixes → cached tokens cost much less + lower latency | Repeated long system prompts/documents | "same context reused many times" |
| **Cross-region inference** | Automatically route to other Regions for higher throughput/availability | Traffic bursts | "handle bursts", "availability" |
| **Latency-optimized inference** | Faster responses for supported models | Latency-critical apps | "lowest latency" |
| **Intelligent prompt routing** | Routes each prompt to a cheaper or stronger model in a family based on complexity | Cost optimization | "route simple prompts to smaller model" |

**What drives GenAI cost:**
1. **Model choice** (bigger = more expensive per token)
2. **Number of input tokens** (long prompts, RAG context, chat history)
3. **Number of output tokens** (long answers; usually priced higher)
4. **Request volume**
5. **Customization** (fine-tuning training cost + **provisioned throughput hosting**)
6. **Supporting services** (vector DB, Knowledge Base storage, Guardrails charges per text unit)

**Cost vs performance vs latency tradeoffs:**
- Bigger model → better quality, **higher cost, higher latency**.
- More context (RAG chunks, history) → better grounding, **higher cost/latency**.
- Fine-tuned model → better task fit, **training cost + provisioned throughput cost**.
- **Exam trap:** "Reduce cost of a high-volume, simple classification/summarization task" → **smaller model**, shorter prompts, batch, caching. Not a bigger model.

**Other AWS cost/performance considerations (from the guide):**
- **Responsiveness** (latency), **availability**, **redundancy**, **performance**, **regional coverage** (not every model is in every Region), **token-based pricing**, **provisioned throughput**, **custom models**.

### IF THE QUESTION SAYS… → THINK…
53. "Access many FMs through a single API without managing infrastructure" → **Amazon Bedrock**
54. "Need full control to train/deploy a custom model on chosen instances" → **Amazon SageMaker AI**
55. "Deploy an open-source pre-trained model quickly into your own environment" → **SageMaker JumpStart**
56. "Experiment with GenAI apps without code / without an AWS account" → **PartyRock**
57. "Guaranteed, consistent throughput for a fine-tuned custom model in Bedrock" → **Provisioned Throughput**
58. "Process 100,000 prompts overnight at lowest cost" → **Bedrock batch inference**
59. "Is customer prompt data used to train Bedrock base models?" → **No**

---

## 2.11 BUSINESS VALUE & METRICS FOR GENAI

| Metric | Meaning | Example |
|---|---|---|
| **Cross-domain performance** | Works well across varied tasks/domains | One assistant for HR + IT + finance |
| **Efficiency** | Time/effort saved | Tickets resolved per agent per hour |
| **Accuracy** | Correctness of outputs | % correct answers |
| **Conversion rate** | % of users who take the desired action (buy, sign up) | GenAI product descriptions ↑ sales |
| **Average revenue per user (ARPU)** | Revenue ÷ users | Personalized upsell |
| **Customer lifetime value (CLV)** | Total revenue expected from a customer over the whole relationship | Better service → customers stay longer |
| **Customer satisfaction (CSAT)** | How happy customers are | Survey scores after chatbot |
| **Average handle time** | Time to resolve a contact | Agent assist reduces it |
| **Productivity** | Output per employee | Developers ship faster with Kiro |
| **ROI** | Value gained vs cost | (Savings − cost) / cost |

- **Exam trap:** "Measure whether a GenAI shopping assistant increased sales" → **conversion rate** (not ROUGE/BLEU).
- **Memory trick:** **CLV = Customer's Lifetime Value = the long-game money.**

### IF THE QUESTION SAYS… → THINK…
60. "Measure % of chatbot visitors who purchase" → **Conversion rate**
61. "Measure total revenue a customer brings over the relationship" → **Customer lifetime value (CLV)**

---

## DOMAIN 2 — FAST RECAP
- FM = general pre-trained model. LLM = text FM. Transformer = attention. Diffusion = images from noise.
- Tokens = billing & limits; embeddings = meaning-as-numbers; vectors = number lists; chunking = splitting docs.
- Context window = max tokens per request (input + output).
- Context engineering = curating WHAT goes into the context (docs, memory, tools, history).
- FM lifecycle: Data selection → Model selection → Pre-training → Fine-tuning → Evaluation → Deployment → Feedback.
- Agent = FM brain + tools + memory + instructions; acts on goals. Multi-agent = team with a supervisor.
- **MCP = USB-C for AI tools** (open protocol connecting agents to tools/data). AgentCore Gateway makes MCP tools.
- Limitations: hallucination, nondeterminism, interpretability, bias, toxicity, cost, latency, knowledge cutoff.
- Bedrock = serverless FMs via API; your data is not used for training. SageMaker = full control.
- Pricing: on-demand (per token), batch (~50% off), provisioned throughput (custom models/guaranteed capacity), prompt caching.

**➡ Continue to PART 3 — Domain 3: Applications of Foundation Models**
