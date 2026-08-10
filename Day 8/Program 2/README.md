
# 🔍 Search in Rotated Sorted Array – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #33 – Medium)

There is an integer array `nums` sorted in ascending order (with **distinct** values). Prior to being passed to your function, `nums` is possibly **rotated** at an unknown pivot index `k`.

Given the rotated array `nums` and an integer `target`, return the **index** of `target` if it is in `nums`, or `-1` if it is not.

You must write an algorithm with **O(log n)** runtime complexity.

Example:

```
Original sorted: [0, 1, 2, 4, 5, 6, 7]
Rotated at k=4:  [4, 5, 6, 7, 0, 1, 2]

Input:  nums = [4,5,6,7,0,1,2], target = 0
Output: 4  (index of 0)

Input:  nums = [4,5,6,7,0,1,2], target = 3
Output: -1 (not found)
```

---

# 🧠 Approach: Modified Binary Search

The key insight is:

> Even though the array is rotated, **at least one half** (left or right of mid) is **always sorted**. We can determine which half is sorted and decide where the target lies.

### How to identify the sorted half:

```
If nums[left] <= nums[mid] → LEFT half is sorted
Otherwise                  → RIGHT half is sorted
```

### Decision logic:

Once we know which half is sorted, we check if the target falls within that sorted range:
- If yes → search that half
- If no → search the other half

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[left] <= nums[mid]) {
                // LEFT half is sorted
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                // RIGHT half is sorted
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 `int left = 0; int right = nums.size() - 1;`

* Standard binary search setup.
* `left` and `right` define the current search window.

---

### 🔹 `int mid = left + (right - left) / 2;`

* Calculate the middle index.
* Using `left + (right - left) / 2` instead of `(left + right) / 2` to **avoid integer overflow**.

---

### 🔹 `if (nums[mid] == target) return mid;`

* If we found the target at `mid`, return immediately.

---

### 🔹 Determine Which Half is Sorted

```cpp
if (nums[left] <= nums[mid])
```

#### Why this works:

In a rotated sorted array, the rotation point creates one "break". At any `mid`:

```
Case 1: Left half is sorted        Case 2: Right half is sorted
[4, 5, 6, 7, | 0, 1, 2]           [6, 7, 0, 1, | 2, 4, 5]
 ↑ sorted ↑   mid                  mid           ↑ sorted ↑
nums[left] <= nums[mid] ✓          nums[left] > nums[mid]
```

* If `nums[left] <= nums[mid]` → the left half `[left...mid]` has no rotation break → **sorted**.
* Otherwise → the right half `[mid...right]` is **sorted**.

---

### 🔹 Case 1: LEFT Half is Sorted

```cpp
if (target >= nums[left] && target < nums[mid]) {
    right = mid - 1;  // Search left half
} else {
    left = mid + 1;   // Search right half
}
```

* We know `nums[left...mid]` is sorted.
* If `target` is within this range → it must be in the left half.
* Otherwise → it must be in the right half.

```
[4, 5, 6, 7, 0, 1, 2]
 ↑ sorted ↑
If target = 5: 5 >= 4 && 5 < 7 → search left ✅
If target = 0: NOT in [4,7) → search right ✅
```

---

### 🔹 Case 2: RIGHT Half is Sorted

```cpp
if (target > nums[mid] && target <= nums[right]) {
    left = mid + 1;   // Search right half
} else {
    right = mid - 1;  // Search left half
}
```

* We know `nums[mid...right]` is sorted.
* If `target` is within this range → it must be in the right half.
* Otherwise → it must be in the left half.

---

### 🔹 `return -1;`

* If the loop ends without finding the target, it doesn't exist in the array.

---

# 📊 Step-by-Step Example

Input:

```
nums = [4, 5, 6, 7, 0, 1, 2], target = 0
```

| Step | left | right | mid | nums[mid] | Sorted Half | Target in Range? | Action |
| ---- | ---- | ----- | --- | --------- | ----------- | ---------------- | ------ |
| 1    | 0    | 6     | 3   | 7         | Left [4,5,6,7] | 0 not in [4,7) | left = 4 |
| 2    | 4    | 6     | 5   | 1         | Right [1,2] | 0 not in (1,2] | right = 4 |
| 3    | 4    | 4     | 4   | 0         | Found! | — | return 4 |

✅ Final Answer = **4**

---

# 📊 Example: Target Not Found

Input:

```
nums = [4, 5, 6, 7, 0, 1, 2], target = 3
```

| Step | left | right | mid | nums[mid] | Sorted Half | Action |
| ---- | ---- | ----- | --- | --------- | ----------- | ------ |
| 1    | 0    | 6     | 3   | 7         | Left        | left = 4 |
| 2    | 4    | 6     | 5   | 1         | Right       | right = 4 |
| 3    | 4    | 4     | 4   | 0         | Left        | left = 5 |

left (5) > right (4) → STOP

✅ Final Answer = **-1** (not found)

---

# 🎯 Visual: Why One Half is Always Sorted

```
Rotated at different positions:

[0, 1, 2, 4, 5, 6, 7]  → Not rotated (both halves sorted)
[7, 0, 1, 2, 4, 5, 6]  → Right half sorted
[6, 7, 0, 1, 2, 4, 5]  → Right half sorted
[5, 6, 7, 0, 1, 2, 4]  → Left half sorted
[4, 5, 6, 7, 0, 1, 2]  → Left half sorted
[2, 4, 5, 6, 7, 0, 1]  → Left half sorted
[1, 2, 4, 5, 6, 7, 0]  → Left half sorted

The rotation break can only be in ONE half → the other is sorted!
```

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(log n)**

* Standard binary search — we halve the search space each iteration.
* At most `log₂(n)` iterations.

---

### 🔹 Space Complexity: **O(1)**

* Only a few integer variables used.
* No extra data structures.

---

# ⚔️ Comparison With Other Approaches

| Approach                      | Time Complexity | Space Complexity |
| ----------------------------- | --------------- | ---------------- |
| Linear Search                 | O(n)            | O(1)             |
| Find Pivot + Two Binary Searches | O(log n)     | O(1)             |
| Single Modified Binary Search | O(log n)        | O(1)             |

The single modified binary search is the **cleanest** approach 🚀

---

# ⭐ Key Concepts Learned

* **Modified Binary Search** — adapting binary search for non-standard conditions
* Identifying the **sorted half** in a rotated array
* Range checking to decide which half to search
* Overflow-safe mid calculation: `left + (right - left) / 2`
* Handling edge cases: single element, not rotated, not found

---

# 🏆 Why This Problem Is Important

* Classic **binary search variant** — one of the most common interview patterns
* Tests ability to adapt known algorithms to new constraints
* Foundation for "Search in Rotated Sorted Array II" (with duplicates)
* Real-world use: searching in circular buffers, log-rotated files
* Commonly asked at Google, Amazon, Microsoft, Facebook, Apple, Bloomberg
