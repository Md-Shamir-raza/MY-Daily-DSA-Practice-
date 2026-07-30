
# 🎨 Sort Colors (Dutch National Flag) – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #75 – Medium)

Given an array `nums` with `n` objects colored **red (0)**, **white (1)**, and **blue (2)**, sort them **in-place** so that objects of the same color are adjacent, in the order red, white, and blue.

You must solve this problem **without using the library's sort function** and in **one pass**.

Example:

```
Input:  nums = [2, 0, 2, 1, 1, 0]
Output: [0, 0, 1, 1, 2, 2]
```

More examples:

```
Input:  [2, 0, 1]  → Output: [0, 1, 2]
Input:  [0]        → Output: [0]
Input:  [1]        → Output: [1]
```

---

# 🧠 Approach: Dutch National Flag Algorithm

This algorithm was proposed by **Edsger Dijkstra** and uses **three pointers**:

| Pointer | Role |
| ------- | ---- |
| `low`   | Everything before `low` is **0** (red) |
| `mid`   | Current element being examined |
| `high`  | Everything after `high` is **2** (blue) |

### The invariant:

```
[0...low-1]  → all 0s (sorted)
[low...mid-1] → all 1s (sorted)
[mid...high] → unsorted (to be processed)
[high+1...n-1] → all 2s (sorted)
```

### Rules:

| nums[mid] | Action |
| --------- | ------ |
| 0         | Swap with `low`, increment both `low` and `mid` |
| 1         | Just increment `mid` (already in correct region) |
| 2         | Swap with `high`, decrement `high` only (don't move `mid`) |

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 `int low = 0;`

* Points to the **next position** where a `0` should be placed.
* Everything to the left of `low` is guaranteed to be `0`.

---

### 🔹 `int mid = 0;`

* The **current element** being examined.
* Moves left to right through the array.

---

### 🔹 `int high = nums.size() - 1;`

* Points to the **next position** where a `2` should be placed.
* Everything to the right of `high` is guaranteed to be `2`.

---

### 🔹 `while (mid <= high)`

* We continue processing until `mid` crosses `high`.
* When `mid > high`, all elements have been classified.

---

### 🔹 Case 1: `nums[mid] == 0`

```cpp
swap(nums[low], nums[mid]);
low++;
mid++;
```

#### What happens:

* Current element is `0` → it belongs at the beginning.
* Swap it with the element at `low`.
* Move **both** pointers forward.

#### Why move `mid` too?

* The element swapped from `low` to `mid` is either `0` or `1` (already processed).
* So it's safe to move past it.

---

### 🔹 Case 2: `nums[mid] == 1`

```cpp
mid++;
```

#### What happens:

* Current element is `1` → it's **already in the correct middle region**.
* Just move `mid` forward. No swap needed.

---

### 🔹 Case 3: `nums[mid] == 2`

```cpp
swap(nums[mid], nums[high]);
high--;
```

#### What happens:

* Current element is `2` → it belongs at the end.
* Swap it with the element at `high`.
* Move `high` backward.

#### ⚠️ Why NOT increment `mid`?

* The element swapped from `high` to `mid` is **unknown** (could be 0, 1, or 2).
* We need to **re-examine** it in the next iteration.
* This is the most common mistake people make!

---

# 📊 Step-by-Step Example

Input:

```
nums = [2, 0, 2, 1, 1, 0]
```

| Step | low | mid | high | nums                | nums[mid] | Action           |
| ---- | --- | --- | ---- | ------------------- | --------- | ---------------- |
| 1    | 0   | 0   | 5    | [2, 0, 2, 1, 1, 0] | 2         | swap(mid, high)  |
| 2    | 0   | 0   | 4    | [0, 0, 2, 1, 1, 2] | 0         | swap(low, mid)   |
| 3    | 1   | 1   | 4    | [0, 0, 2, 1, 1, 2] | 0         | swap(low, mid)   |
| 4    | 2   | 2   | 4    | [0, 0, 2, 1, 1, 2] | 2         | swap(mid, high)  |
| 5    | 2   | 2   | 3    | [0, 0, 1, 1, 2, 2] | 1         | mid++            |
| 6    | 2   | 3   | 3    | [0, 0, 1, 1, 2, 2] | 1         | mid++            |

Now `mid (4) > high (3)` → **STOP**

✅ Final Answer = **[0, 0, 1, 1, 2, 2]**

---

# 🎯 Visual Representation

```
Before: [2, 0, 2, 1, 1, 0]

Processing...

After:  [0, 0, 1, 1, 2, 2]
         ^^^^  ^^^^  ^^^^
         RED   WHITE BLUE
```

The array is partitioned into three regions:

```
[0 ... low-1]   → All 0s (RED)
[low ... high]   → All 1s (WHITE)  
[high+1 ... n-1] → All 2s (BLUE)
```

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(n)**

* Each element is visited **at most twice** (once by `mid`, possibly once when swapped).
* Single pass through the array.

---

### 🔹 Space Complexity: **O(1)**

* Only three integer variables used: `low`, `mid`, `high`.
* Sorting is done **in-place** — no extra array needed.

---

# ⚔️ Comparison With Other Approaches

| Approach                       | Time Complexity | Space Complexity | Passes |
| ------------------------------ | --------------- | ---------------- | ------ |
| Built-in Sort                  | O(n log n)      | O(log n)         | —      |
| Counting Sort (Two Pass)       | O(n)            | O(1)             | 2      |
| Dutch National Flag (One Pass) | O(n)            | O(1)             | 1      |

The Dutch National Flag algorithm is the **optimal** solution — one pass, constant space 🚀

---

# ⭐ Key Concepts Learned

* **Three-pointer** technique (variation of two pointers)
* **In-place** partitioning without extra space
* **Dutch National Flag** algorithm by Dijkstra
* Why we don't increment `mid` when swapping with `high`
* Array partitioning into three regions

---

# 🏆 Why This Problem Is Important

* Classic **interview problem** asked at top companies
* Teaches the Dutch National Flag partitioning technique
* Foundation for **QuickSort's partition** step (3-way partition)
* Tests understanding of pointer manipulation and invariants
* Commonly asked at Google, Amazon, Microsoft, Goldman Sachs
