# Merge Two Sorted Lists (LeetCode #21)

## 📝 Problem Description
You are given the heads of two sorted linked lists `list1` and `list2`.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

**Example 1:**
- **Input:** list1 = [1,2,4], list2 = [1,3,4]
- **Output:** [1,1,2,3,4,4]

**Example 2:**
- **Input:** list1 = [], list2 = []
- **Output:** []

## 💡 Solution Approach
We can iterate through both lists using a dummy node to keep track of the head of the merged list. We compare the values of the nodes at the current positions in `list1` and `list2`. The node with the smaller value is appended to the merged list, and we advance the pointer in that list. We continue this until one of the lists is exhausted. Finally, we append the remaining nodes of the non-empty list to the end of the merged list.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(N + M) where N and M are the lengths of `list1` and `list2`, because we traverse each list at most once.
- **Space Complexity:** O(1) since we only allocate a few pointers and a dummy node, without creating any new nodes.
