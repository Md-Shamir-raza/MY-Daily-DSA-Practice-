
# 🎯 Find First and Last Position of Element in Sorted Array – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #34 – Medium)

Given an array of integers `nums` sorted in **non-decreasing order**, find the **starting and ending position** of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with **O(log n)** runtime complexity.

Example:

```
Input:  nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Explanation: 8 first appears at index 3 and last at index 4.

Input:  nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Input:  nums = [], target = 0
Output: [-1,-1]
```

---

# 🧠 Approach: Two Binary Searches

The key insight is:

> Run binary search **twice** — once to find the **leftmost** (first) occurrence, and once to find the **rightmost** (last) occurrence.

### Standard binary search vs. bound search:

| Standard Binary Search | Bound Search |
| ---------------------- | ------------ |
| Stops when `nums[mid] == target` | **Keeps searching** after finding target |
| Returns any occurrence | Returns the **first** or **last** occurrence |

### The trick:

When we find `target` at `mid`:
- **For first position**: Don't stop! Search **left** (`right = mid - 1`) — there might be an earlier occurrence.
- **For last position**: Don't stop! Search **right** (`left = mid + 1`) — there might be a later occurrence.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        int last = findBound(nums, target, false);
        return {first, last};
    }

private:
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                result = mid;

                if (isFirst) {
                    right = mid - 1;  // Search left
                } else {
                    left = mid + 1;   // Search right
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 `int first = findBound(nums, target, true);`

* Call `findBound` with `isFirst = true` to find the **leftmost** occurrence.

---

### 🔹 `int last = findBound(nums, target, false);`

* Call `findBound` with `isFirst = false` to find the **rightmost** occurrence.

---

### 🔹 `int result = -1;`

* Stores the best position found so far.
* Initialized to `-1` (not found).
* Gets updated every time we find `target`.

---

### 🔹 Standard Binary Search Part

```cpp
if (nums[mid] < target) {
    left = mid + 1;
} else {
    right = mid - 1;
}
```

* If `nums[mid] < target` → target is in the right half.
* If `nums[mid] > target` → target is in the left half.
* Same as regular binary search.

---

### 🔹 The Key Difference: When `nums[mid] == target`

```cpp
if (nums[mid] == target) {
    result = mid;  // Save this position

    if (isFirst) {
        right = mid - 1;  // Keep searching LEFT
    } else {
        left = mid + 1;   // Keep searching RIGHT
    }
}
```

#### Finding the FIRST occurrence:

* We found `target` at `mid`, but there might be an **earlier** one.
* Set `result = mid` (save it in case there's no earlier one).
* Search `left` by setting `right = mid - 1`.

#### Finding the LAST occurrence:

* We found `target` at `mid`, but there might be a **later** one.
* Set `result = mid` (save it in case there's no later one).
* Search `right` by setting `left = mid + 1`.

---

# 📊 Step-by-Step Example

Input:

```
nums = [5, 7, 7, 8, 8, 10], target = 8
```

### Finding FIRST position (isFirst = true):

| Step | left | right | mid | nums[mid] | Action | result |
| ---- | ---- | ----- | --- | --------- | ------ | ------ |
| 1    | 0    | 5     | 2   | 7         | 7 < 8, left = 3 | -1 |
| 2    | 3    | 5     | 4   | 8         | Found! right = 3 | 4 |
| 3    | 3    | 3     | 3   | 8         | Found! right = 2 | 3 |

left (3) > right (2) → STOP. **First = 3** ✅

### Finding LAST position (isFirst = false):

| Step | left | right | mid | nums[mid] | Action | result |
| ---- | ---- | ----- | --- | --------- | ------ | ------ |
| 1    | 0    | 5     | 2   | 7         | 7 < 8, left = 3 | -1 |
| 2    | 3    | 5     | 4   | 8         | Found! left = 5 | 4 |
| 3    | 5    | 5     | 5   | 10        | 10 > 8, right = 4 | 4 |

left (5) > right (4) → STOP. **Last = 4** ✅

✅ Final Answer = **[3, 4]**

---

# 📊 Example: All Same Elements

Input:

```
nums = [2, 2, 2, 2, 2], target = 2
```

### Finding FIRST:

| Step | left | right | mid | Action | result |
| ---- | ---- | ----- | --- | ------ | ------ |
| 1    | 0    | 4     | 2   | Found! right = 1 | 2 |
| 2    | 0    | 1     | 0   | Found! right = -1 | 0 |

**First = 0** ✅

### Finding LAST:

| Step | left | right | mid | Action | result |
| ---- | ---- | ----- | --- | ------ | ------ |
| 1    | 0    | 4     | 2   | Found! left = 3 | 2 |
| 2    | 3    | 4     | 3   | Found! left = 4 | 3 |
| 3    | 4    | 4     | 4   | Found! left = 5 | 4 |

**Last = 4** ✅

✅ Final Answer = **[0, 4]**

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(log n)**

* Two binary searches, each O(log n).
* Total: O(2 log n) = **O(log n)**.

---

### 🔹 Space Complexity: **O(1)**

* Only a few integer variables.
* No extra data structures.

---

# ⚔️ Comparison With Other Approaches

| Approach                      | Time Complexity | Space Complexity |
| ----------------------------- | --------------- | ---------------- |
| Linear Scan                   | O(n)            | O(1)             |
| Binary Search + Linear Expand | O(n) worst case | O(1)             |
| Two Binary Searches (Optimal) | O(log n)        | O(1)             |

Two binary searches guarantee **O(log n)** even with all duplicates 🚀

---

# ⭐ Key Concepts Learned

* **Binary search for bounds** — finding first and last occurrences
* The "don't stop on match" technique — keep searching after finding target
* Using a `result` variable to track the best answer across iterations
* Parameterized search with a boolean flag (`isFirst`)
* Why linear expansion after binary search can degrade to O(n)

---

# 🏆 Why This Problem Is Important

* Essential **binary search variant** — tested in nearly every interview round
* Equivalent to C++ STL's `lower_bound()` and `upper_bound()`
* Foundation for counting occurrences in sorted arrays
* Teaches precise boundary handling in binary search
* Commonly asked at Google, Amazon, Facebook, Microsoft, Bloomberg
