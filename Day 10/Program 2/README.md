
# ✂️ Remove Nth Node From End of List – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #19 – Medium)

Given the `head` of a linked list, remove the `n`th node from the end of the list and return its head.

Follow up: Could you do this in one pass?

Example:

```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Explanation: The 2nd node from the end is 4. Removing it yields [1,2,3,5].
```

More examples:

```
Input: head = [1], n = 1
Output: []

Input: head = [1,2], n = 1
Output: [1]
```

---

# 🧠 Approach: Two Pointers (Slow & Fast) & Dummy Head

The key insight is:

> If we have two pointers spaced exactly `n` nodes apart, when the faster pointer reaches the end of the list, the slower pointer will be just before the node we need to remove!

### Why use a Dummy Head?

If `n` is equal to the length of the list, it means we need to remove the **first node**. A `dummy` head pointing to `head` ensures that our logic works universally without special `if (head == node_to_remove)` conditions.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // slow is now just before the node to be deleted
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 `ListNode* dummy = new ListNode(0, head);`
* We create a dummy node with value 0, and its `next` pointer points to the original `head`.
* This elegantly handles the edge case where the actual head needs to be deleted.

---

### 🔹 Initialize Pointers
```cpp
ListNode* slow = dummy;
ListNode* fast = dummy;
```
* Both `slow` and `fast` start at the `dummy` node.

---

### 🔹 Create the 'Gap'
```cpp
for (int i = 0; i < n; i++) {
    fast = fast->next;
}
```
* We advance the `fast` pointer `n` times.
* The gap between `slow` and `fast` is exactly `n` nodes.

---

### 🔹 Traverse Together
```cpp
while (fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next;
}
```
* Move both pointers one step at a time.
* Because they maintain a gap of `n`, when `fast` reaches the last node (`fast->next == nullptr`), `slow` will be exactly `n` nodes behind.
* This means `slow` is sitting **right before** the target node to delete!

---

### 🔹 Delete the Node
```cpp
ListNode* nodeToDelete = slow->next;
slow->next = slow->next->next;
delete nodeToDelete;
```
* `slow->next` is the node we want to remove. We store it temporarily.
* We bypass the node by linking `slow` to `slow->next->next`.
* Free the memory to avoid memory leaks.

---

### 🔹 Return the Result
```cpp
ListNode* newHead = dummy->next;
delete dummy;
return newHead;
```
* The new head of the list is what the dummy node points to.
* Clean up the dummy node and return.

---

# 📊 Step-by-Step Example

Input: `head = [1,2,3,4,5]`, `n = 2`

**Initialization:**
```
dummy -> 1 -> 2 -> 3 -> 4 -> 5 -> null
S, F
```

**Step 1: Move `fast` 2 steps ahead:**
```
dummy -> 1 -> 2 -> 3 -> 4 -> 5 -> null
  S           F
```

**Step 2: Move both until `fast` is at the end:**
```
dummy -> 1 -> 2 -> 3 -> 4 -> 5 -> null
             S           F
```

**Step 3: `slow` is at 3, delete `slow->next` (4):**
```
Bypass 4:
dummy -> 1 -> 2 -> 3 ------> 5 -> null
```

✅ Final Answer = **[1, 2, 3, 5]**

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(L)**
* Where `L` is the number of nodes in the linked list. We make exactly one pass through the list.

---

### 🔹 Space Complexity: **O(1)**
* We only use a few constant extra pointers (`dummy`, `slow`, `fast`).

---

# ⭐ Key Concepts Learned
* **Two-Pointer technique** (Fast and Slow pointers / Runner technique) in Linked Lists.
* Using a **dummy head** to simplify deletion edge cases.
* **One-pass** algorithms vs. two-pass (count nodes then find Nth).
* Safe memory management (`delete`).

---

# 🏆 Why This Problem Is Important
* A classic linked list manipulation problem.
* Introduces the extremely useful "Runner" technique which is used to find middles or cycles in linked lists.
* Frequently asked in technical interviews.
