# Data Structures Cheat Sheet

## Table of Contents
- [Arrays](#arrays)
- [Lists](#lists)
- [Stacks](#stacks)
- [Queues](#queues)
- [Heaps](#priority-queues--binary-heaps)
- [Maps](#hash-maps--hash-tables--dictionaries)
- [Trees](#trees)
    - [Binary Trees](#binary-trees)
    - [Binary Search Trees](#binary-search-trees)
    - [Red-Black Trees](#red-black-trees)
    - Splay Trees
    - B-Trees
    - Tries
- [Graphs](#graphs)
    - [Adjacency Representations](#adjacency-representations)

## Arrays

#### 📖 Definition:

> **Contiguous blocks of memory** (of the same data type)

---

#### 🔗 Types:

- **Static Array**
- **Dynamic Array**
- **Dynamically Allocated Array**

---

#### 🆚 Distinctions:

#### 🔹 Static Arrays

- Allocated on stack at compile time (automatic storage duration)
- Can be **modified** but **NOT resized**

#### 🔹 Dynamically Allocated Arrays*

- (Re)allocated on heap at runtime (dynamic storage duration, managed manually)
- Can be **modified and resized**

> *⚠️ *The ability to dynamically allocate arrays depends on the programming language*

#### 🔹 Dynamic Arrays

- (Re)allocated on the heap during runtime
- Can be **modified and resized**
- Built from a wrapper class with helpful member functions to manipulate data**

> **💡 *A wrapper class could also be built for static arrays, but functionality would be limited compared to dynamic arrays*

---

#### ⚙️ Operations:

| **Dynamic Array**         |                          | **Static Array**            |                          |
|---------------------------|--------------------------|-----------------------------|--------------------------|
| **Operation**             | **Time Complexity**      | **Operation**               | **Time Complexity**      |
| Access/Modify (any)       | O(1)                     | Access/Modify (any)         | O(1)                     |
| Insert/Delete (front)     | O(n)                     | Search                      | O(n)                     |
| Insert/Delete (mid)       | O(n)                     |                             |                          |
| Insert/Delete (end)       | O(1)*                    |                             |                          |
| Search                    | O(n)                     |                             |                          |
> *unless array is at capacity in which case it is O(n)

---

#### 🧠 Takeaways:

- Arrays allow for **random access** with the tradeoff of potentially **costly insertion/deletion** due to potential memory reallocation
- They are typically ***space efficient** because data is stored **contiguously** in memory
> ***Dynamic arrays** can become **space inefficient** since memory is often **overallocated** (either by the user or system) to avoid excessive resizing (which can add **time overhead**)

---

#### ✅ Use Cases:
**Best to use arrays when:**
- The **size is known** or can be reasonably predicted
- There is a **frequent need for fast data access**
- **Memory efficiency** is important

#### Examples:
- Searching and sorting algorithms
- Mathematical or computational problems

[back to top](#data-structures-cheat-sheet)

<!-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ -->

## Lists

#### 📖 Definition:

> Linked nodes that store data and point to each other

---

#### 🔗 Types:

- **Singly-Linked List**
- **Doubly-Linked List**
- **Circular Linked List**

---

#### 🆚 Distinctions:

#### 🔹 Singly vs Doubly Linked Lists
- **Singly linked lists** are **monodirectional**
- **Doubly linked lists** are **bidirectional** (each node points to both its predecessor and successor)
- **Singly linked lists** are generally **more space efficient**
- **Doubly linked lists** allow more efficient access to the **end element**, and **insert/delete** operations at both ends

#### 🔁 Circular Linked Lists
- The **tail node** points back to the **head**, forming a loop
- Common in **doubly linked lists** with a **sentinel node**, which simplifies boundary conditions and reduces code complexity

---

#### ⚙️ Operations:

| **Singly-Linked List**  |                     | **Doubly-Linked List**  |                     |
|-------------------------|---------------------|-------------------------|---------------------|
| **Operation**           | **Time Complexity** | **Operation**           | **Time Complexity** |
| Access (front)          | O(1)                | Access (front)          | O(1)                |
| Access (mid)            | O(n)                | Access (mid)            | O(n)                |
| Access (end)            | O(n)*               | Access (end)            | O(1)                |
| Insert/Delete (front)   | O(1)                | Insert/Delete (front)   | O(1)                |
| Insert/Delete (mid)     | O(1)                | Insert/Delete (mid)     | O(1)                |
| Insert (end)            | O(n)*               | Insert/Delete (end)     | O(1)                |
| Delete (end)            | O(n)                |                         |                     |
| Search                  | O(n)                | Search                  | O(n)                |
> **\*** O(1) if a **tail pointer** is maintained

---

#### 🧠 Takeaways:

- Linked lists offer **high efficiency for insertion and deletion**, at the **cost of random access performance**
- Have some **storage overhead** due to pointer references to other nodes, however they are **space-efficient in capacity**, as they grow or shrink dynamically — storing only as many nodes as needed

---

#### ✅ Use Cases:

**Best to use linked lists when:**
- The **size of the data structure is unknown** or changes frequently
- There is a **frequent need to insert/delete** at various points in the data structure

#### Examples:
- Hash Table Chaining
- Graph Adjacency Representations
- Navigable data structures (i.e. for music playlists, image viewers, or browsing history)

[back to top](#data-structures-cheat-sheet)

<!-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ -->

## Stacks

#### 📖 Definition:

> **Abstract data type** that stores elements in **LIFO (Last In, First Out)** order.

---

#### 🔗 Types:

Stacks are usually implemented using a **linear storage structure**, such as:
- [**Arrays**](#arrays)
- [**Linked Lists**](#lists)

---

#### 🆚 Distinctions:

#### 🔹 Stack Array vs Stack List
- The **efficiency of stack operations** is **identical** in both implementations
- **Arrays** tend to have **more storage overhead** up front (due to allocation strategies)
- **Linked lists** (stack list) incur more **overhead as they grow**, due to storing additional pointers and dynamic memory management

---

#### ⚙️ Operations:
| Stack             |                     |
|-------------------|---------------------|
| **Operation**     | **Time Complexity** |
| Access (top)      | O(1)                |
| Insert (top)      | O(1)                |
| Delete (top)      | O(1)                |

---

#### 🧠 Takeaways:

- A stack is built on **top of another data structure** and enforces a **LIFO** order for accessing, inserting, and deleting elements
- Offers **constant time access**, insertion, and deletion at the **top**
- Choice of underlying structure (i.e. array vs list) impacts **space and performance tradeoffs**

---

#### ✅ Use Cases:

**Best to use stacks when:**
- You need to manage elements in a **last-in, first-out** manner
- There is a need for **function call management** (call stacks)
  
#### Examples:
- **Backtracking** algorithms (e.g., undo functionality, recursive parsing)
- **Depth-First Search** (DFS)

[back to top](#data-structures-cheat-sheet)

<!-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ -->

## Queues

#### 📖 Definition:

> **Abstract data type** that stores elements in **FIFO (First In, First Out)** order

---

#### 🔗 Types:

Queues are typically implemented using a **linear storage structure** like:
- [**Arrays**](#arrays)
- [**Linked Lists**](#lists)

Other common queue types:
- **Deques** (Double-Ended Queues)
- [**Priority Queues**](#priority-queues--binary-heaps)

---

#### 🆚 Distinctions:

#### 🔹 Queue List vs Queue Array
- **Arrays** require a more complex implementation where elements **wrap around** (i.e., circular buffer) to maintain efficiency
- **Arrays** tend to have **more allocation overhead** up front
- **Lists** incur **overhead as they grow** due to pointer storage and dynamic allocation

#### 🔹 Deque
- A **double-ended queue** that allows insertion and deletion at **both front and back**
> 💡 Useful when both ends of the queue need to be accessed efficiently

---

#### ⚙️ Operations:
| Queue            |                     |
|------------------|---------------------|
| **Operation**    | **Time Complexity** |
| Access (front)   | O(1)                |
| Insert (end)     | O(1)                |
| Delete (front)   | O(1)                |

---

#### 🧠 Takeaways:

- A queue is built on top of another structure and enforces a **FIFO** access pattern
- Provides **constant-time** access to the **front**, **deletion** from the front, and **insertion** at the end
- Choice of underlying structure (i.e. array vs list) impacts **space and performance tradeoffs**

---

#### ✅ Use Cases:

**Best to use queues when:**
- You need to process items in the **order they arrive**

#### Examples:
- **task scheduling**
- **I/O buffering**
- **Breadth-First Search (BFS)**

[back to top](#data-structures-cheat-sheet)

<!-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ -->

## Priority Queues / (Binary) Heaps

#### 📖 Definition:

> A **nearly complete binary tree** whose nodes satisfy a **min/max heap property**  
> *(Usually visualized as a tree, but implemented using **linear storage** like an array or list)*

---

#### 🔗 Types:

- **Min Heap**
- **Max Heap**

#### Other Specialty Heaps:
- Binomial Heap
- Fibonacci Heap
- D-ary Heap
- Pairing Heap
- Leftist Heap
- Skew Heap
- B-Heap

---

#### 🆚 Distinctions: 

Min vs Max Heap
- **Min Heap**: The key of each parent node is **less than or equal to** its child nodes
- **Max Heap**: The key of each parent node is **greater than or equal to** its child nodes
- Both enforce the **heap property** recursively down the tree

---

#### ⚙️ Operations:

|Priority Queue        |                     |
|----------------------|---------------------|
| **Operation**        | **Time Complexity** |
| Access (min/max)\*   | O(1)                |
| Insert               | O(log₂n)            |
| Delete (min/max)\*   | O(log₂n)            |

> \* **min** or **max** element depending on heap type

---

#### 🧠 Takeaways:

- Heaps allow **constant-time access** to the **highest or lowest priority element**
- Insertion and deletion require **O(log n)** time to maintain the heap property
- Provide an efficient solution for managing **priority-ordered data**

---

#### 📐 Properties:

- Height of a heap:  
  `h = ⌊log₂n⌋`
- Number of nodes in a heap of height `h`:  
  `2^h ≤ n < 2^(h+1)`
- Max number of nodes at height `h`:  
  `⌈n / 2^(h+1)⌉`
- Index range of leaf nodes (in array):  
  `⌊n / 2⌋ + 1` to `n`
- Number of leaves in a heap of height `h`:  
  `1` to `2^h`
- Each child of the root is a subtree with at most `2n / 3` nodes

---

#### ✅ Use Cases:

**Best to use heaps when:**
- You need **quick access to the smallest or largest element**  
- In scenarios where **priority** matters more than order

#### Examples:
- Efficiently **schedule jobs** based on priority
- **Dijkstra’s algorithm** (shortest path in graphs)
- **Heap Sort** (a comparison-based sorting algorithm)

[back to top](#data-structures-cheat-sheet)

<!-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ -->

## Hash Maps / Hash Tables / Dictionaries

#### 📖 Definition:

> An **associative array** of **key-value pairs** that allows efficient data retrieval based on keys

---

#### 🔗 Types:

- **Ordered** vs **Unordered**
- **Multi-key** vs **Unique-key**
- **Sets** (store only keys, no values)

> These types can be **combined** based on ordering and key uniqueness

---

#### 🆚 Distinctions:

#### 🔹 Ordered vs Unordered
- **Ordered maps** maintain the order of key-value pairs by **sorting based on keys**
  - Typically implemented using **Red-Black Trees (RB-Trees)**
- **Unordered maps** do **not maintain any order**
  - Typically implemented using **hashing** (with **chaining** or **open addressing**)

#### 🔹 Multi-key vs Unique-key
- **Multi-key maps** allow **non-unique keys**
- **Unique-key maps** require **each key to be unique**

#### 🔹 Sets
- A **set** is like a hash map but stores **only keys**, not values
> 💡 Efficient for **membership checking**

---

#### ⚙️ Operations:

| Hash Map         |                                      |
|------------------|--------------------------------------|
| **Operation**    | **Time Complexity**                  |
| Search / Access  | O(1)\*                               |
| Insert           | O(1)\*\*                             |
| Delete           | O(1)\*\*\*                           |

> \* **Expected** runtime; worst case is O(n) if many collisions occur  
> \*\* O(n) worst case if **rehashing** is needed  
> \*\*\* O(n) worst case depending on collision handling implementation

---

#### 🧠 Takeaways:

- Hash maps provide **highly efficient** insertion, deletion, and key-based access
- They are **widely applicable** in real-world programming and make a strong **default choice** for general-purpose data storage
- May not be ideal when:
  - **Ordering/stability** of elements matters
  - **Iteration complexity** is important
  - Memory overhead is a concern for **simple applications**

---

#### ✅ Use Cases:

**Best to use hash maps when:**
- **efficient modification and retrieval** of data is important

#### Examples:
- **Caching** (e.g. LRU caches)
- **Database indexing**
- **Routing tables / Networking**
- **Graph algorithms** (e.g. adjacency maps)

[back to top](#data-structures-cheat-sheet)

<!-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ -->

## Trees

#### 📖 Definition:

> An **abstract data type** that represents a **hierarchical tree structure** with a set of **connected nodes**

---

#### 🔗 Types:

- **Binary Tree**
- **Ternary Tree**  
. . .
- **N-Ary Tree**

---

#### 🆚 Distinctions:

Tree types are categorized based on the **maximum number of children** each node can have:
- **Binary** → 2 children
- **Ternary** → 3 children
- **N-Ary** → *n* children

---

#### 📚 Terminology:

| **Term**             | **Definition**                                                                     |
|----------------------|------------------------------------------------------------------------------------|
| **Node**             | Basic building block of a tree, stores data and connects to other nodes            |
| **Edge**             | A **link** or **branch** between two nodes (parent → child)                        |
| **Root**             | The **topmost** node in a tree                                                     |
| **Parent**           | A node with one or more children                                                   |
| **Child**            | A node with a parent                                                               |
| **Sibling**          | Nodes sharing the same parent                                                      |
| **Ancestor**         | Any node on the path from the **root** to a specific node                          |
| **Descendant**       | Any node on the path from a node to its **leaf nodes**                             |
| **Predecessor**      | Node that comes directly **before** another in an **in-order traversal**           |
| **Successor**        | Node that comes directly **after** another in an **in-order traversal**            |
| **Leaf**             | A node with **no children** (also called an **external node**)                     |
| **Internal Node**    | A node with **at least one child** (i.e., a **non-leaf**)                          |
| **External Node**    | A node with **no children** (i.e., a **leaf**)                                     |
| **Degree of Node**   | The **number of children** a node has                                              |
| **Depth of Node**    | Number of **edges from a node to the root**                                        |
| **Height**           | Number of **edges from the root to the farthest leaf**                             |
| **Depth**            | Number of **nodes on the longest path from root to leaf**                          |
| **Level**            | Number of **edges between a node and the root**                                    |
| **Diameter**         | Length (in edges) of the **longest simple path** between any two nodes in the tree |
| **Subtree**          | A node and **all its descendants**                                                 |
| **Serialization**    | Converting a tree into a **storable/transmittable format**                         |
| **Deserialization**  | Reconstructing a tree from a **serialized format**                                 |

---

#### ✅ Use Cases:

Trees are widely used in:
- File systems and hierarchical data modeling
- Abstract Syntax Trees (compilers, interpreters)
- Databases and indexes (e.g. B-Trees)
- XML/HTML document structures
- Networking (e.g., routing tables)
- AI (e.g., decision trees)
- Organizing game states, scenes, or UI components

[back to top](#data-structures-cheat-sheet)

<!-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ -->

## Binary Trees

#### 📖 Definition:

> A **tree data structure** in which each node has at most **two children** (often referred to as the **left** and **right** child)

---

#### 🔗 Types:

- **Full (Proper) Binary Tree**
- **Degenerate (Pathological) Binary Tree**
- **Skewed Binary Tree** (Left or Right)
- **Complete Binary Tree**
- **Perfect Binary Tree**
- **Balanced Binary Tree**

> Also includes more advanced types:
- **Binary Search Trees (BSTs)**
- **Cartesian Trees**
- **Segment Trees**

---

#### 🆚 Distinctions:

| **Type**       | **Description**                                                                  |
|----------------|----------------------------------------------------------------------------------|
| **Full**       | Every node has either **0 or 2 children**                                        |
| **Degenerate** | Every internal node has **only one child** (resembles a linked list)             |
| **Skewed**     | A degenerate tree skewed **entirely left or right**                              |
| **Complete**   | All levels fully filled **except possibly the last**, filled **from the left**   |
| **Perfect**    | All **internal nodes** have 2 children and **all leaves** are on the same level  |
| **Balanced**   | Height difference between left/right subtree of any node is **at most 1**        |

---

#### 📐 Properties:

- A binary tree with `n` nodes has **`n - 1` edges** (or any tree for that matter)
- A binary tree can have up to **`2^i` nodes at level `i`** (where i ranges from 0 to height)
- **Logarithmic properties** (in terms of base 2) are common:

####  Full Binary Tree
- If there are `n` **leaves**, then there are `n - 1` **internal nodes**

####  Complete (or Perfect) Binary Tree
- **Height** = `⌊log₂(n)⌋`
- **Levels** = `height + 1`
- > _Also see:_ [Heaps](#priority-queues--binary-heaps)

####  Perfect Binary Tree
- Has `⌈n / 2⌉` **leaf nodes**
- Total nodes = `2^h - 1` (where `h` is height)

---

#### 🔍 Visuals:
<details>
<summary><strong>🌳 Full (Proper) Binary Tree</strong></summary>

```
      A
    /   \
   B     C
 /  \
D    E
```

</details>

<details>
<summary><strong>🌳 Degenerate (Pathological) Binary Tree</strong></summary>
  
      A
       \
        B
         \
          C
         /
       D

</details>

<details>
<summary><strong>🌳 Skewed Binary Tree</strong></summary>

      A
       \
        B
         \
          C
           \
            D

</details>

<details>
<summary><strong>🌳 Complete Binary Tree</strong></summary>

```
      A
    /   \
   B     C
 /  \   /
D    E F
```

</details>

<details>
<summary><strong>🌳 Perfect Binary Tree</strong></summary>

```
      A
    /   \
   B     C
 /  \   /  \
D    E F    G
```

</details>

<details>
<summary><strong>🌳 Balanced Binary Tree</strong></summary>
  
```
      A
    /   \
   B     C
  /       \
 D         E
```

</details>

[back to top](#data-structures-cheat-sheet)

<!-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ -->

## Binary Search Trees

#### 📖 Definition:
> "An ordered binary tree in which each node contains a key that satisfies the binary-search-tree property"

- **Binary-search-tree property**:  
  For any given node, the key must be:
  - **Greater than** all keys in its **left subtree**
  - **Less than** all keys in its **right subtree**

---

#### 🔗 Types:

- AVL Tree  
- Red-Black Tree  
- B-Tree  
- B+ Tree  
- Splay Tree  
- KD Tree
- etc.

---

#### 🆚 Distinctions:

Special types of BSTs vary in how they:
- Maintain **balance** (e.g., AVL, Red-Black)
- Optimize for **specific types of data access**
- Handle **multi-way branching** (e.g., B-Trees)

---

#### ⚙️ Operations:

|Binary Search Tree |                     |
|-------------------|---------------------|
| **Operation**     | **Time Complexity** |
| Search            | O(h)*               |
| Insert            | O(h)*               |
| Delete            | O(h)*               |
| Traverse          | O(n)                |
> *`h` is the height of the tree. Best case: O(log₂n), Worst case: O(n)

---

#### 🧠 Takeaways:

- BSTs allow for **efficient searching, insertion, and deletion**
- **Tree height** determines performance:
  - **Best case**: `O(log₂n)` for balanced trees
  - **Worst case**: `O(n)` for skewed or degenerate trees
- In practice, most BST-based applications use **self-balancing trees** (e.g., AVL or Red-Black Trees) for reliable performance

---

#### ✅ Use Cases:

- Sorting large datasets (e.g., Tree Sort)
- Database indexing
- Search-based applications
- *Implementation of abstract data types:
  - **Map**
  - **Set**  
  *(common in many programming libraries)

[back to top](#data-structures-cheat-sheet)

<!-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ -->

## Red-Black Trees

#### 📖 Definition:
> A **Red-Black Tree** is a self-balancing binary search tree that satisfies specific color-based properties to maintain balance and ensure logarithmic time operations

---

#### 📐 Properties:

1. Every node is either **red** or **black**
2. The **root** is always **black**
3. Every **leaf** (NIL) is **black**
4. If a node is **red**, both its children must be **black** (no two red nodes in a row)
5. Every simple path from a node to its descendant **leaves** contains the same number of **black nodes** (black-height)

---

#### ⚙️ Operations:

| Red-Black Tree |                     |
|----------------|---------------------|
| **Operation**  | **Time Complexity** |
| Search         | O(log₂n)            |
| Insert         | O(log₂n)            |
| Delete         | O(log₂n)            |
| Traverse       | O(n)                |

---

#### 🧠 Takeaways:

- Red-Black Trees maintain balance **through coloring and rotations**
- They ensure the tree's **height is always O(log₂n)** (this makes them ideal for maintaining dynamic ordered data efficiently)
- The **maximum height** of a red-black tree is **2log₂(n + 1)**

---

#### ✅ Use Cases:

#### Examples:
- Associative containers in standard libraries of various programming languages
- Database indexing systems
- Symbol tables in compilers

[back to top](#data-structures-cheat-sheet)

<!-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ -->

## Splay Trees

[back to top](#data-structures-cheat-sheet)

<!-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ -->

## B-Trees

[back to top](#data-structures-cheat-sheet)

<!-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ -->

## Tries

[back to top](#data-structures-cheat-sheet)

<!-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ -->

## Graphs

#### 📖 Definition:
> An **abstract data type** consisting of **vertices** (or nodes) connected by **edges**, used to represent relationships and interactions between objects (or entities)

---

#### 🔗 Types:

**Graph Characteristics:**
- **Directed / Undirected**
- **Weighted / Unweighted**
- **Connected / Disconnected**
- **Cyclic / Acyclic**
- **Simple / Multigraph**
- **Sparse / Dense**

**Special Cases:**
- Trivial Graph
- Null Graph
- Complete Graph
- Regular Graph
- Tree
- Bipartite Graph

**Representations:**
- **Adjacency List** ✅ *(most common)*
- **Adjacency Matrix** ✅ *(most common)*
- **Edge List**

---

#### 🆚 Distinctions:

#### ➤ Directed vs Undirected
- **Directed**: edges have a direction (A → B)
- **Undirected**: edges represent bidirectional relationships (A — B)
- **Mixed**: combination of directed and undirected edges

#### ➤ Weighted vs Unweighted
- **Weighted**: edges carry values (or weights) (e.g. cost, distance)
- **Unweighted**: edges represent equal-cost relationships

#### ➤ Connected vs Disconnected
- **Connected**: every vertex is reachable from any other
- **Disconnected**: at least one vertex is not reachable from others

#### ➤ Cyclic vs Acyclic
- **Cyclic**: contains at least one cycle
- **Acyclic**: contains no cycles

#### ➤ Simple vs Multigraph
- **Simple**: no parallel edges or self-loops
- **Multigraph**: allows multiple edges between same pair of nodes

#### ➤ Sparse vs Dense
- **Sparse**: few edges relative to vertices  
  \|E\| ≪ \|V²\|  
- **Dense**: number of edges approaches the maximum  
  \|E\| ≈ \|V²\|


#### 🌟 Special Graph Types
- **Trivial Graph**: single vertex, no edges
- **Null Graph**: multiple vertices, no edges
- **Complete Graph**: every vertex is connected to every other
- **Regular Graph**: all vertices have equal degree
- **Tree**: acyclic, connected graph
- **Bipartite Graph**: vertices can be split into two disjoint sets with edges only between sets

---

#### 📚 Terminology:

- **Adjacency**: two vertices connected by an edge  
  - In directed graphs:  
    - `u → v` → `u` is the **initial** vertex, `v` is the **terminal** vertex

- **Degree**: number of edges connected to a vertex  
  - **Self-loop** contributes **2** to degree  
  - In directed graphs:  
    - **In-degree**: edges arriving at a vertex  
    - **Out-degree**: edges departing a vertex
  - **Isolated Vertex**: degree = 0  
  - **Pendant Vertex**: degree = 1

- **Path**: sequence of connected vertices  
  - **P(u, v) = (v₀, v₁, ..., vₙ)**  
  - **Simple Path**: all vertices are distinct (except possibly start/end)

---

#### ✅ Use Cases:

Graphs are ideal when **relationships or connections** are central to the problem

**Examples:**
- 🌐 Network modeling (social, computer, etc.)
- 🗺 Routing & navigation (e.g. GPS systems)
- 📊 Web page ranking (e.g. Google's PageRank)
- 🔄 Task scheduling & dependency resolution

[back to top](#data-structures-cheat-sheet)

<!-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ -->

## Adjacency Representations

#### 📖 Definition:
> Graphs whose connections are represented by vertices and their neighboring (adjacent) vertices

---

#### 🔗 Types:

- **Adjacency List**
- **Adjacency Matrix**

---

#### 🆚 Distinctions:

#### Adjacency List
- Requires **Θ(V + E)** storage
- Time to find each edge: **Θ(V + E)***  
  > *(Θ(E) if \|E\| = Ω(V), (e.g. connected, undirected graphs or strongly connected, directed graphs)
- Edge search: **O(v)** where *v* is the number of adjacent vertices
- Easy to adapt to many graph types
- Best for **sparse graphs**

#### Adjacency Matrix
- Requires **Θ(V²)** storage
- Time to find each edge: **Θ(V²)**
- Less flexible for complex graph variations
- Best for **dense graphs**
- Simpler to implement for **small graphs**

---

#### ⚙️ Operations:

| **Operation**         | **Adjacency List**            | **Adjacency Matrix**      |
|-----------------------|-------------------------------|---------------------------|
| Search Vertex         | O(1)                          | O(1)                      |
| Search Edge           | O(E)                          | O(1)                      |
| Insert Vertex         | O(V+E), O(V), or O(1) \*\*    | O(V²)                     |
| Insert Edge           | O(1)                          | O(1)                      |
| Delete Vertex         | O(V+E), O(V), or O(1) \*\*    | O(V²)                     |
| Delete Edge           | O(E)                          | O(1)                      |
| Traverse              | O(V + E)\*                    | O(V²)                     |
> \* Unless \|E\| = Ω(V), in which case it becomes Θ(E)  
> \*\* Depends on underlying structure & implementation

---

#### 🧠 Takeaways:

- **Adjacency List** is generally preferred:
  - More compact for **sparse graphs**
  - Easier to modify and adapt for different graph variants

- **Adjacency Matrix** is useful:
  - When the graph is **dense**
  - When you need **constant-time edge checks**
  - When simplicity and fast edge lookup matter more than space
 
[back to top](#data-structures-cheat-sheet)

<!-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ -->

<!-- underline options -->

─────────────────────────────────────────────────────────────────────────────────────────

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

═════════════════════════════════════════════════════════════════════════════════════════

▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄

█████████████████████████████████████████████████████████████████████████████████████████

