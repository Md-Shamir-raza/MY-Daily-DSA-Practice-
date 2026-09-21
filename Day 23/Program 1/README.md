# Reverse Linked List (LeetCode #206)

## 📝 Problem Description
Given the `head` of a singly linked list, reverse the list, and return the reversed list.

**Example 1:**
- **Input:** head = [1,2,3,4,5]
- **Output:** [5,4,3,2,1]

**Example 2:**
- **Input:** head = [1,2]
- **Output:** [2,1]

## 💡 Solution Approach
We can reverse a linked list iteratively by keeping track of three pointers: `prev` (initially `nullptr`), `curr` (initially `head`), and `next_node`. As we iterate through the list, we store the next node, reverse the `curr->next` pointer to point to `prev`, and then advance both `prev` and `curr` one step forward. We repeat this until `curr` becomes `nullptr`. The new head of the reversed list will be `prev`.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(N) where N is the number of nodes in the linked list, as we traverse it exactly once.
- **Space Complexity:** O(1) since we are modifying the pointers in-place and only using a few extra pointers.
