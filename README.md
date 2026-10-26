# 🛡️ Cyber Threat Intelligence using Knowledge Graphs

<p align="center">
  <b>A DSA-based cybersecurity threat analysis system using Graphs, Hash Maps, BFS, DFS and Path Finding.</b>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=cplusplus">
  <img src="https://img.shields.io/badge/DSA-Graph%20%7C%20BFS%20%7C%20DFS-orange?style=for-the-badge">
  <img src="https://img.shields.io/badge/Domain-Cybersecurity-red?style=for-the-badge">
  <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge">
</p>

---

## 📌 Overview

**Cyber Threat Intelligence using Knowledge Graphs** is a C++ based Data Structures and Algorithms project designed to represent and analyze relationships between cybersecurity entities.

The system models entities such as **attackers, malware, vulnerabilities, servers, and organizations** as nodes in a directed graph. Relationships between these entities are represented as directed edges.

This allows cybersecurity information to be explored using graph traversal and path-finding algorithms.

### Example Threat Chain

```text
Attacker_A
    │
    │ uses
    ▼
Malware_X
    │
    │ exploits
    ▼
CVE_101
    │
    │ affects
    ▼
Server_01
    │
    │ belongs_to
    ▼
Organization_A
```

---

# 🎯 Project Objectives

- Represent cybersecurity information using a **Knowledge Graph**.
- Store entities efficiently using **Hash Maps**.
- Represent relationships using an **Adjacency List**.
- Search cybersecurity entities efficiently.
- Traverse threat relationships using **BFS and DFS**.
- Identify possible attack paths between entities.
- Handle invalid input and graph edge cases.
- Demonstrate practical applications of **Data Structures and Algorithms in Cybersecurity**.

---

# 🧠 Data Structures Used

| Data Structure | Purpose |
|---|---|
| `unordered_map` | Stores and searches entities efficiently |
| `vector` | Represents adjacency lists |
| `queue` | Used by BFS traversal |
| `unordered_set` | Maintains visited entities |
| `unordered_map` | Stores parent relationships during path finding |

### Graph Representation

The project uses a **directed adjacency-list representation**.

```cpp
unordered_map<string, Entity> entities;

unordered_map<string, vector<Relationship>> graph;
```

Each entity contains:

```cpp
struct Entity {
    string name;
    string type;
};
```

Each relationship contains:

```cpp
struct Relationship {
    string target;
    string relation;
};
```

---

# ⚙️ Features

### 1️⃣ Add Entity

Add a new cybersecurity entity by specifying:

- Entity name
- Entity type

Example:

```text
Name: Malware_Z
Type: Malware
```

Duplicate entities are detected automatically.

---

### 2️⃣ Add Relationship

Create a directed relationship between two existing entities.

Example:

```text
Attacker_A → uses → Malware_X
```

The program verifies that both entities exist and prevents duplicate relationships.

---

### 3️⃣ Display Knowledge Graph

Displays every entity along with its outgoing relationships.

Example:

```text
Malware_X [Malware]
   exploits -> CVE_101
   targets -> Server_02
```

---

### 4️⃣ Search Entity

Search for an entity using its name.

The system displays:

```text
Entity Found!

Name : Malware_X
Type : Malware
```

Because entities are stored in an `unordered_map`, lookup is **O(1) average-case**.

---

### 5️⃣ BFS Threat Traversal

Performs **Breadth-First Search** from a selected entity.

BFS uses a queue and explores the graph level by level.

Example:

```text
BFS Threat Traversal:

Attacker_A Malware_X CVE_101 Server_02 Organization_A
```

---

### 6️⃣ DFS Threat Traversal

Performs **Depth-First Search** from a selected entity.

DFS explores one path as deeply as possible before backtracking.

Example:

```text
DFS Threat Traversal:

Attacker_A Malware_X CVE_101 Server_01 Organization_A
```

---

### 7️⃣ Attack Path Finder

Finds a path between two cybersecurity entities using **BFS with parent tracking**.

Example:

```text
Source      : Attacker_A
Destination : Organization_A

Attack Path:

Attacker_A
    ↓
Malware_X
    ↓
CVE_101
    ↓
Server_01
    ↓
Organization_A
```

The algorithm reconstructs the path using a parent map.

---

### 8️⃣ Sample Dataset

The project includes a predefined cybersecurity dataset containing:

```text
Attackers
Malware
Vulnerabilities
Servers
Organizations
```

Example entities:

```text
Attacker_A
Attacker_B

Malware_X
Malware_Y

CVE_101
CVE_202

Server_01
Server_02

Organization_A
```

---

# 🖥️ Program Menu

```text
============================================
       CYBER THREAT KNOWLEDGE GRAPH
============================================

1. Add Entity
2. Add Relationship
3. Display Graph
4. Search Entity
5. BFS Threat Traversal
6. DFS Threat Traversal
7. Find Attack Path
8. Load Sample Dataset
9. Exit

Enter your choice:
```

---

# 🚀 How to Run

## Prerequisites

Make sure you have a C++ compiler installed.

Recommended:

- **GCC / MinGW**
- C++11 or later

---

## Clone the Repository

```bash
git clone https://github.com/SukheshVarma/CyberThreat-KnowledgeGraph.git
```

Move into the project directory:

```bash
cd CyberThreat-KnowledgeGraph
```

---

## Compile

```bash
g++ main.cpp KnowledgeGraph.cpp -o KnowledgeGraph
```

---

## Run

### Windows

```powershell
.\KnowledgeGraph.exe
```

### Linux / macOS

```bash
./KnowledgeGraph
```

---

# 🧪 Testing & Edge Cases

The application handles several important cases.

### Duplicate Entity

```text
Entity already exists!
```

### Entity Not Found

```text
Entity not found!
```

### Invalid Relationship

```text
Target entity does not exist!
```

### Empty Graph

```text
Graph is empty!
```

### No Attack Path

```text
No attack path exists between X and Y.
```

### Same Source and Destination

```text
Source and destination are the same.
Attack Path: X
```

### Cyclic Graphs

BFS and DFS maintain a `visited` set to prevent infinite traversal.

---

# ⏱️ Time Complexity

Let:

- **V** = number of vertices/entities
- **E** = number of edges/relationships

| Operation | Complexity |
|---|---:|
| Add Entity | **O(1) average** |
| Search Entity | **O(1) average** |
| Add Relationship | **O(d)** |
| Display Graph | **O(V + E)** |
| BFS | **O(V + E)** |
| DFS | **O(V + E)** |
| Attack Path | **O(V + E)** |
| Space Complexity | **O(V + E)** |

`d` represents the number of relationships connected to the source entity.

The adjacency-list representation is particularly suitable for a sparse cybersecurity knowledge graph because it stores only existing relationships.

---

# 🔐 Why Knowledge Graphs?

Cybersecurity data contains many interconnected relationships.

For example:

```text
Attacker
   ↓
uses
   ↓
Malware
   ↓
exploits
   ↓
Vulnerability
   ↓
affects
   ↓
Server
   ↓
belongs_to
   ↓
Organization
```

A graph structure allows these relationships to be represented naturally and enables algorithms such as **BFS, DFS and shortest-path search** to analyze potential threat propagation.

---

# 🏗️ Project Structure

```text
CyberThreat-KnowledgeGraph/
│
├── KnowledgeGraph.h
├── KnowledgeGraph.cpp
├── main.cpp
├── KnowledgeGraph.exe
└── README.md
```

### `KnowledgeGraph.h`

Contains:

- Entity structure
- Relationship structure
- KnowledgeGraph class
- Function declarations

### `KnowledgeGraph.cpp`

Contains the implementation of:

- Entity management
- Relationship management
- Graph display
- Search
- BFS
- DFS
- Attack path finding
- Sample dataset

### `main.cpp`

Contains the interactive menu and user input handling.

---

# 🧩 System Architecture

```text
                 ┌─────────────────────┐
                 │    User Interface   │
                 │    Menu Driven      │
                 └──────────┬──────────┘
                            │
                            ▼
                 ┌─────────────────────┐
                 │   KnowledgeGraph    │
                 │      Class          │
                 └──────────┬──────────┘
                            │
             ┌──────────────┴──────────────┐
             ▼                             ▼
   ┌──────────────────┐          ┌──────────────────┐
   │  Entity Storage  │          │ Graph Structure  │
   │  unordered_map   │          │ Adjacency List   │
   └──────────────────┘          └─────────┬────────┘
                                           │
                         ┌─────────────────┼─────────────────┐
                         ▼                 ▼                 ▼
                       BFS               DFS          Attack Path
```

---

# 👥 Team Contributions

| Member | Contribution |
|---|---|
| **Sukhesh Varma** | Core Knowledge Graph structure, entity/relationship management & final integration |
| **Vishal R K** | Graph display and entity search |
| **balalogan07** | BFS and DFS threat traversal |
| **Member 4** | Attack path analysis and sample dataset |

The project uses separate GitHub accounts and individual commits to demonstrate team contributions.

---

# 📚 DSA Concepts Demonstrated

This project demonstrates practical implementation of:

- Directed Graphs
- Adjacency Lists
- Hash Maps
- Vectors
- Queues
- Hash Sets
- Breadth-First Search
- Depth-First Search
- Path Reconstruction
- Graph Traversal
- Cycle Prevention
- Complexity Analysis

---

# 🌐 Real-World Applications

The concepts demonstrated by this project can be applied to:

- Cyber threat intelligence
- Malware relationship analysis
- Vulnerability mapping
- Attack path analysis
- Security incident investigation
- Network threat analysis
- Threat actor profiling
- Security knowledge bases

---

# 🔮 Future Improvements

Possible extensions include:

- Visualization of the knowledge graph
- Import cybersecurity datasets from JSON/CSV
- Weighted attack paths
- Risk scoring
- Threat severity classification
- Integration with real threat intelligence feeds
- Machine learning based threat prediction
- Web-based graph visualization
- Database integration

---

# 📌 Project Status

**Status: ✅ Completed**

The current implementation supports:

```text
✓ Entity Management
✓ Relationship Management
✓ Graph Display
✓ Entity Search
✓ BFS Traversal
✓ DFS Traversal
✓ Attack Path Detection
✓ Sample Dataset
✓ Input Validation
✓ Duplicate Detection
✓ Edge Case Handling
✓ GitHub Version Control
```

---

## ⭐ Acknowledgement

This project was developed as part of a **Data Structures and Algorithms laboratory evaluation**, demonstrating how fundamental DSA concepts can be applied to a real-world cybersecurity problem.

---

<p align="center">
  <b>🛡️ Cybersecurity × Data Structures & Algorithms 🚀</b>
</p>
