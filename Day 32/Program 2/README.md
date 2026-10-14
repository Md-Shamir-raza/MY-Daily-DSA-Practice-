# Construct Binary Tree from Preorder and Inorder Traversal (LeetCode #105)

## 📝 Problem Description
Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return the binary tree.

**Example 1:**
- **Input:** preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
- **Output:** [3,9,20,null,null,15,7]

**Example 2:**
- **Input:** preorder = [-1], inorder = [-1]
- **Output:** [-1]

## 💡 Solution Approach
The first element of the preorder traversal is always the root. We find this root's position in the inorder array — everything to its left is the left subtree, and everything to its right is the right subtree. We use a **Hash Map** for O(1) lookup of the root's index in the inorder array. Then, we recursively build the left and right subtrees. A key insight is that we pass `preIdx` by reference; since preorder goes Root → Left → Right, the index naturally advances correctly when we build the left subtree before the right.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(N) where N is the number of nodes. Each node is visited once, and we use a hash map for O(1) lookups.
- **Space Complexity:** O(N) for the hash map and O(H) for the recursion stack, where H is the tree's height.
