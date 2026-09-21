# Maximum Depth of Binary Tree (LeetCode #104)

## 📝 Problem Description
Given the `root` of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

**Example 1:**
- **Input:** root = [3,9,20,null,null,15,7]
- **Output:** 3

**Example 2:**
- **Input:** root = [1,null,2]
- **Output:** 2

## 💡 Solution Approach
We can use Depth-First Search (DFS) recursively to find the maximum depth. The maximum depth of a tree is 1 + the maximum of the depths of its left and right subtrees. The base case is when the tree is empty (root is `nullptr`), in which case the depth is 0.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(N) where N is the number of nodes in the tree, since we must visit each node once to find the maximum depth.
- **Space Complexity:** O(H) where H is the height of the tree, due to the call stack during recursion. In the worst case (skewed tree), this is O(N). In the best case (balanced tree), this is O(log N).
