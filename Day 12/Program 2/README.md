
# 🌳 Binary Tree Level Order Traversal – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #102 – Medium)

Given the `root` of a binary tree, return the **level order traversal** of its nodes' values. (i.e., from left to right, level by level).

Example:

```
Input: root = [3,9,20,null,null,15,7]
    3
   / \
  9  20
    /  \
   15   7

Output: [[3],[9,20],[15,7]]
```

More examples:

```
Input: root = [1]
Output: [[1]]

Input: root = []
Output: []
```

---

# 🧠 Approach: Breadth-First Search (BFS) using a Queue

The key insight is:

> To traverse a tree level by level, we use Breadth-First Search (BFS). A **Queue** data structure is perfect for this because it follows First-In-First-Out (FIFO) semantics. We process nodes in the exact order they were discovered.

### Grouping by Levels:
Standard BFS just prints nodes one by one. But this problem wants the output grouped by levels: `[[level1], [level2], ...]`.
To do this, we need to know how many nodes are in the *current* level before we start popping them. We can do this by taking the `size()` of the queue at the start of each level loop.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = q.front();
                q.pop();

                currentLevel.push_back(currentNode->val);

                if (currentNode->left != nullptr) {
                    q.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    q.push(currentNode->right);
                }
            }
            result.push_back(currentLevel);
        }
        return result;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 Initialization and Edge Case

```cpp
vector<vector<int>> result;
if (root == nullptr) return result;
```
* Create the `result` vector of vectors to store the final output.
* If the tree is empty (`root` is null), simply return the empty `result`.

---

### 🔹 Initialize the Queue

```cpp
queue<TreeNode*> q;
q.push(root);
```
* Create a queue of `TreeNode` pointers.
* Start the BFS by pushing the `root` node into the queue. Now, Level 0 is in the queue.

---

### 🔹 Outer Loop (Process each Level)

```cpp
while (!q.empty()) {
    int levelSize = q.size();
    vector<int> currentLevel;
```
* The loop continues as long as there are nodes to process.
* **CRITICAL STEP**: `int levelSize = q.size();` takes a snapshot of how many nodes are currently in the queue. These are exactly the nodes for the *current* level.
* We create a `currentLevel` vector to store the values of the nodes on this level.

---

### 🔹 Inner Loop (Process nodes in the current Level)

```cpp
for (int i = 0; i < levelSize; i++) {
    TreeNode* currentNode = q.front();
    q.pop();
    currentLevel.push_back(currentNode->val);
```
* We loop `levelSize` times. This ensures we only process the nodes that belong to the current level, even though we will be adding new nodes (children) to the queue during this loop.
* We grab the front node from the queue, remove it (`pop`), and add its value to `currentLevel`.

---

### 🔹 Queue the Children for the Next Level

```cpp
    if (currentNode->left != nullptr) {
        q.push(currentNode->left);
    }
    if (currentNode->right != nullptr) {
        q.push(currentNode->right);
    }
}
```
* If the current node has a left child, add it to the back of the queue.
* If it has a right child, add it to the back of the queue.
* These children will not be processed in the *current* `for` loop because we restricted the loop to `levelSize` iterations. They will be processed in the *next* iteration of the `while` loop (the next level).

---

### 🔹 Save the Level

```cpp
    result.push_back(currentLevel);
}
return result;
```
* Once the `for` loop finishes, we have collected all values for this level. Push the `currentLevel` array into our `result`.
* Finally, return the full `result`.

---

# 📊 Step-by-Step Example

Tree:
```
    3
   / \
  9  20
    /  \
   15   7
```

**Initialization**: Queue `q = [3]`. `result = []`.

**Iteration 1 (Level 0):**
- `levelSize` = 1. `currentLevel = []`.
- Loop 1 time:
  - Pop `3`. `currentLevel = [3]`.
  - Push children of 3: `9`, `20`. Queue is now `[9, 20]`.
- End loop. `result = [[3]]`.

**Iteration 2 (Level 1):**
- `levelSize` = 2. `currentLevel = []`.
- Loop 2 times:
  1. Pop `9`. `currentLevel = [9]`. Push children (none). Queue is `[20]`.
  2. Pop `20`. `currentLevel = [9, 20]`. Push children `15`, `7`. Queue is `[15, 7]`.
- End loop. `result = [[3], [9, 20]]`.

**Iteration 3 (Level 2):**
- `levelSize` = 2. `currentLevel = []`.
- Loop 2 times:
  1. Pop `15`. `currentLevel = [15]`. Push children (none). Queue is `[7]`.
  2. Pop `7`. `currentLevel = [15, 7]`. Push children (none). Queue is `[]`.
- End loop. `result = [[3], [9, 20], [15, 7]]`.

Queue is empty. Loop terminates. Return `result`. ✅

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(N)**
* We visit every node in the tree exactly once. Pushing and popping from a queue takes O(1) time.

---

### 🔹 Space Complexity: **O(N)**
* In the worst case (a completely full/perfect binary tree), the bottom-most level will hold `N/2` nodes.
* The queue needs to store all these nodes simultaneously.
* Therefore, the space required for the queue is O(N). The output array also takes O(N) space.

---

# ⭐ Key Concepts Learned
* **Breadth-First Search (BFS)** for trees and graphs.
* Using a **Queue (FIFO)** to maintain traversal order.
* The `levelSize` trick to group flat BFS output into distinct arrays per level.

---

# 🏆 Why This Problem Is Important
* Level order traversal is the foundation for many other tree algorithms (e.g., finding shortest path in unweighted graphs, zig-zag traversal, right-side view of a tree).
* It directly tests your understanding of BFS versus DFS.
