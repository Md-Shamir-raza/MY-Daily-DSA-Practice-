# Binary Tree Right Side View (LeetCode #199)

## 📝 Problem Description
Given the `root` of a binary tree, imagine yourself standing on the **right side** of it, return the values of the nodes you can see ordered from top to bottom.

**Example 1:**
- **Input:** root = [1,2,3,null,5,null,4]
- **Output:** [1,3,4]

**Example 2:**
- **Input:** root = [1,2,null,4]
- **Output:** [1,2,4]
- **Explanation:** Even though node 4 is a left child, it's visible from the right because there's no right child at that level.

## 💡 Solution Approach
We perform a **Breadth-First Search (BFS)** using a queue. At each level, we process all nodes and only record the **last node** of that level (since it's the rightmost and thus visible from the right side). This is essentially a Level Order Traversal where we only keep the last element of each level.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(N) where N is the number of nodes in the tree. We visit each node exactly once.
- **Space Complexity:** O(W) where W is the maximum width of the tree (the maximum number of nodes at any level), which in the worst case can be O(N/2) ≈ O(N).
