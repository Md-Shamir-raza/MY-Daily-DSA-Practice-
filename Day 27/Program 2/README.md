# Kth Smallest Element in a BST (LeetCode #230)

## 📝 Problem Description
Given the `root` of a binary search tree, and an integer `k`, return the `k`th smallest value (1-indexed) of all the values of the nodes in the tree.

**Example 1:**
- **Input:** root = [3,1,4,null,2], k = 1
- **Output:** 1

**Example 2:**
- **Input:** root = [5,3,6,2,4,null,null,1], k = 3
- **Output:** 3

## 💡 Solution Approach
The inorder traversal of a Binary Search Tree (BST) visits nodes in ascending order. We can perform an inorder traversal (Left, Node, Right) and keep a count of how many nodes we have visited. When our count reaches `k`, the value of the current node is our answer. We can stop the traversal early once we find the `k`th smallest element to optimize performance.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(H + k) where H is the height of the tree. We first go down to the leftmost leaf, which takes O(H) time, and then we process `k` nodes. In the worst case, this is O(N).
- **Space Complexity:** O(H) for the recursion stack space, where H is the tree's height. This ranges from O(log N) for a balanced tree to O(N) for a completely skewed tree.
