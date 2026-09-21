# Linked List Cycle (LeetCode #141)

## 📝 Problem Description
Given `head`, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer.
Return `true` if there is a cycle in the linked list. Otherwise, return `false`.

**Example 1:**
- **Input:** head = [3,2,0,-4], pos = 1 (where tail connects to the 1st node, zero-indexed)
- **Output:** true
- **Explanation:** There is a cycle in the linked list, where the tail connects to the 1st node.

**Example 2:**
- **Input:** head = [1,2], pos = -1
- **Output:** false
- **Explanation:** There is no cycle in the linked list.

## 💡 Solution Approach
We can use **Floyd’s Cycle-Finding Algorithm**, also known as the "Tortoise and the Hare" algorithm. We use two pointers: a `slow` pointer that moves one step at a time, and a `fast` pointer that moves two steps at a time. If there is a cycle, the fast pointer will eventually wrap around and meet the slow pointer. If the fast pointer reaches the end of the list (`nullptr`), then there is no cycle.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(N) where N is the number of nodes in the linked list. If there is no cycle, the fast pointer reaches the end in N/2 steps. If there is a cycle, the pointers will meet in at most N steps.
- **Space Complexity:** O(1) since we only use two pointers.
