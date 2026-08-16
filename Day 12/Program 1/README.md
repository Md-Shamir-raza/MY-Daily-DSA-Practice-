
# ✅ Validate Binary Search Tree – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #98 – Medium)

Given the `root` of a binary tree, determine if it is a **valid binary search tree (BST)**.

A valid BST is defined as follows:
- The left subtree of a node contains only nodes with keys **less than** the node's key.
- The right subtree of a node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.

Example:

```
Input: root = [2,1,3]
  2
 / \
1   3
Output: true
```

More examples:

```
Input: root = [5,1,4,null,null,3,6]
  5
 / \
1   4
   / \
  3   6
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
```

---

# 🧠 Approach: Recursive Range Checking

The key insight is:

> A common mistake is to only check if `node->left < node` and `node->right > node`. This is incorrect because a node deep in the left subtree might be greater than the root, which violates the BST property.
> Instead, we must pass down an **allowable range (min, max)** for each node.

### How it works:
1. Start with the root allowed to be anything: `(LONG_MIN, LONG_MAX)`. We use `long long` to prevent overflow if the tree contains `INT_MAX` or `INT_MIN`.
2. When going **left**, the maximum allowable value becomes the current node's value: `(min, node.val)`.
3. When going **right**, the minimum allowable value becomes the current node's value: `(node.val, max)`.
4. If any node's value falls outside its allowable range, return `false`.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode* node, long long minVal, long long maxVal) {
        if (node == nullptr) {
            return true;
        }

        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }

        return validate(node->left, minVal, node->val) && 
               validate(node->right, node->val, maxVal);
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 `isValidBST` Function

```cpp
bool isValidBST(TreeNode* root) {
    return validate(root, LONG_MIN, LONG_MAX);
}
```
* This is the public interface.
* We call our private helper function `validate`, passing the root and the initial unrestricted range `LONG_MIN` to `LONG_MAX`.

---

### 🔹 Base Case

```cpp
if (node == nullptr) {
    return true;
}
```
* If we reach a null node, it means we've reached the bottom of a path without any violations. An empty tree (or subtree) is technically a valid BST.

---

### 🔹 Check Current Node

```cpp
if (node->val <= minVal || node->val >= maxVal) {
    return false;
}
```
* **Crucial step**: Does the current node violate its inherited constraints?
* If `node->val` is less than or equal to `minVal` OR greater than or equal to `maxVal`, it's not a valid BST.
* Note the `<=` and `>=`: BSTs usually do not allow duplicate values.

---

### 🔹 Recursive Validation

```cpp
return validate(node->left, minVal, node->val) && 
       validate(node->right, node->val, maxVal);
```
* We must recursively validate BOTH subtrees; if either is false, the whole tree is invalid (hence `&&`).
* **Going Left**: The values must be strictly less than the current node. So, `maxVal` gets updated to `node->val`. `minVal` stays the same.
* **Going Right**: The values must be strictly greater than the current node. So, `minVal` gets updated to `node->val`. `maxVal` stays the same.

---

# 📊 Step-by-Step Example (Invalid Tree)

Tree:
```
    5
   / \
  1   4
     / \
    3   6
```

1. **Root (5)**: `validate(5, -∞, ∞)`
   - `-∞ < 5 < ∞` ✅
   - Calls Left: `validate(1, -∞, 5)`
   - Calls Right: `validate(4, 5, ∞)`

2. **Left Child (1)**: `validate(1, -∞, 5)`
   - `-∞ < 1 < 5` ✅
   - Leaf node, returns `true`.

3. **Right Child (4)**: `validate(4, 5, ∞)`
   - Wait, `4` is NOT strictly between `5` and `∞`.
   - `4 <= 5` triggers `return false`.

✅ Result bubbles up: `true && false` -> **false**. The tree is invalid!

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(N)**
* We visit each node in the tree exactly once in the worst case (if the tree is a valid BST).

---

### 🔹 Space Complexity: **O(H)**
* `H` is the height of the tree.
* This space is used by the recursion call stack.
* In the worst case (a completely unbalanced tree, like a linked list), `H = N`, so space is `O(N)`.
* In the best case (a perfectly balanced tree), `H = log(N)`, so space is `O(log N)`.

---

# ⭐ Key Concepts Learned
* **Tree Traversal and State Passing**: Passing constraints down the recursive call stack.
* **Global vs. Local Constraints**: Why local checks (`left < root < right`) aren't enough for a full BST validation.
* **Overflow Handling**: Using `LONG_MIN` and `LONG_MAX` to avoid integer overflow issues with extreme test cases.

---

# 🏆 Why This Problem Is Important
* It tests your fundamental understanding of the Binary Search Tree property.
* It highlights a very common logic trap that many candidates fall into (the local-only check).
* Essential for any interview focusing on Trees and Graphs.
