# Reorder List (LeetCode #143)

## 📝 Problem Description
You are given the head of a singly linked-list. The list can be represented as:
`L0 → L1 → … → Ln - 1 → Ln`
Reorder the list to be on the following form:
`L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …`
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

**Example 1:**
- **Input:** head = [1,2,3,4]
- **Output:** [1,4,2,3]

**Example 2:**
- **Input:** head = [1,2,3,4,5]
- **Output:** [1,5,2,4,3]

## 💡 Solution Approach
The problem can be broken down into three steps:
1. Find the middle of the linked list using the Tortoise and Hare (slow and fast pointers) approach.
2. Reverse the second half of the linked list.
3. Merge the first half and the reversed second half alternately.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(N) where N is the number of nodes in the linked list. Finding the middle takes O(N/2), reversing takes O(N/2), and merging takes O(N/2).
- **Space Complexity:** O(1) as we only reassign pointers and do not use extra data structures.
