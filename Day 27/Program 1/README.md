# Lowest Common Ancestor of a Binary Search Tree (LeetCode #235)

## 📝 Problem Description
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow a node to be a descendant of itself)."

**Example 1:**
- **Input:** root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
- **Output:** 6
- **Explanation:** The LCA of nodes 2 and 8 is 6.

**Example 2:**
- **Input:** root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
- **Output:** 2
- **Explanation:** The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

## 💡 Solution Approach
We can utilize the properties of a Binary Search Tree (BST). In a BST, all nodes in the left subtree are smaller than the root, and all nodes in the right subtree are greater than the root. 
- If both `p` and `q` are greater than the `root`, then the LCA must be in the right subtree.
- If both `p` and `q` are less than the `root`, then the LCA must be in the left subtree.
- If one is greater and one is less, or if one of them is equal to the root, then the current root is the LCA. This is because the paths to `p` and `q` split at this node.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(H) where H is the height of the BST. In the worst case (a skewed tree), this is O(N). For a balanced tree, it is O(log N).
- **Space Complexity:** O(H) for the recursion stack space. We can also do this iteratively in O(1) space.
