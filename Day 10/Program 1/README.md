
# ➕ Add Two Numbers – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #2 – Medium)

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit.

Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```

More examples:

```
Input: l1 = [0], l2 = [0]
Output: [0]

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

---

# 🧠 Approach: Math & Dummy Head Pointer

The key insight is:

> We can simulate schoolbook addition column by column, starting from the least significant digit (which is conveniently at the head of the lists).
> We maintain a `carry` for sums that exceed 9, and use a `dummyHead` to easily build and return the new list.

### Why Dummy Head?

When creating a new linked list, the first node is special because we need to return its pointer. A `dummyHead` avoids writing extra conditional logic for the first node, making the code much cleaner.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead; 
        return result;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 `ListNode* dummyHead = new ListNode(0);`
* Create a dummy node to act as the placeholder for the start of the result list.
* The actual answer will start at `dummyHead->next`.

---

### 🔹 `ListNode* curr = dummyHead;`
* `curr` will be our moving pointer used to attach new nodes to the end of our result list.

---

### 🔹 `int carry = 0;`
* Initialize the carry to 0.

---

### 🔹 `while (l1 != nullptr || l2 != nullptr || carry != 0)`
* The loop continues as long as:
  1. We haven't exhausted `l1`.
  2. We haven't exhausted `l2`.
  3. We still have a `carry` to add (e.g., `9 + 9 = 18`, leaving a carry of 1 for a new digit).

---

### 🔹 `int sum = carry;`
* Start the sum for the current column with the carry from the previous column.

---

### 🔹 Extracting values and advancing pointers

```cpp
if (l1 != nullptr) {
    sum += l1->val;
    l1 = l1->next;
}

if (l2 != nullptr) {
    sum += l2->val;
    l2 = l2->next;
}
```

* If a list isn't empty, add its value to `sum` and advance its pointer to the next node.
* If one list is shorter, we effectively treat its missing nodes as 0.

---

### 🔹 Calculate carry and new digit

```cpp
carry = sum / 10;
curr->next = new ListNode(sum % 10);
```

* `carry` for the next column is `sum / 10`. (e.g., if sum is 18, carry is 1).
* The new digit for the current column is `sum % 10`. (e.g., if sum is 18, the digit is 8).
* Create a new node with this digit and attach it to `curr->next`.

---

### 🔹 `curr = curr->next;`
* Advance the `curr` pointer to prepare for the next iteration.

---

### 🔹 Return the result

```cpp
ListNode* result = dummyHead->next;
delete dummyHead;
return result;
```

* The actual result list starts *after* the dummy head.
* We safely store the result, `delete` the dummy head to prevent a memory leak, and return.

---

# 📊 Step-by-Step Example

Input: `l1 = [2,4,3]`, `l2 = [5,6,4]`

| Step | l1 val | l2 val | sum (val1 + val2 + carry) | carry | new node | result list |
| ---- | ------ | ------ | ------------------------- | ----- | -------- | ----------- |
| 1    | 2      | 5      | 2 + 5 + 0 = 7             | 0     | 7        | [7]         |
| 2    | 4      | 6      | 4 + 6 + 0 = 10            | 1     | 0        | [7,0]       |
| 3    | 3      | 4      | 3 + 4 + 1 = 8             | 0     | 8        | [7,0,8]     |

End of loop (l1 and l2 are null, carry is 0).

✅ Final Answer = **[7, 0, 8]**

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(max(m, n))**
* We traverse both lists completely. The loop runs `max(m, n)` times, where `m` and `n` are the lengths of `l1` and `l2`.

---

### 🔹 Space Complexity: **O(max(m, n))**
* The length of the new list is at most `max(m, n) + 1`. This is required for the output, but often in interviews, output space isn't counted as auxiliary space. Auxilliary space is **O(1)**.

---

# ⭐ Key Concepts Learned
* Iterating through multiple linked lists simultaneously.
* Using a **dummy head** pointer to simplify linked list creation.
* Handling edge cases: different length lists and trailing carry values.
* Safe memory management in C++ (`delete dummyHead`).

---

# 🏆 Why This Problem Is Important
* Excellent introduction to Linked Lists and pointers.
* Tests basic mathematics and edge case handling.
* Extremely common interview question (classic LeetCode #2).
