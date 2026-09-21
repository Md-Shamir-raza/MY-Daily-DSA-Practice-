# Invert Binary Tree (LeetCode #226)

## 📝 Problem Description
Given the `root` of a binary tree, invert the tree, and return its root.

**Example 1:**
- **Input:** root = [4,2,7,1,3,6,9]
- **Output:** [4,7,2,9,6,3,1]

**Example 2:**
- **Input:** root = [2,1,3]
- **Output:** [2,3,1]

## 💡 Solution Approach
We can solve this problem recursively. For each node in the tree, we simply swap its left and right child pointers. Then, we recursively call the same function on the left child and right child to invert their subtrees. The base case for the recursion is when the node is `nullptr`, in which case we just return `nullptr`.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(N) where N is the number of nodes in the tree, because we visit each node exactly once.
- **Space Complexity:** O(H) where H is the height of the tree. This is the space used by the recursion stack. In the worst case (skewed tree), it's O(N). For a balanced tree, it's O(log N).
