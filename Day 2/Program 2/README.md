
# 🔺 3Sum – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #15 – Medium)

Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that:

- `i != j`, `i != k`, and `j != k`
- `nums[i] + nums[j] + nums[k] == 0`

The solution set must **not contain duplicate triplets**.

Example:

```
Input:  nums = [-1, 0, 1, 2, -1, -4]
Output: [[-1, -1, 2], [-1, 0, 1]]
Explanation: 
  nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0
  nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0
  nums[2] + nums[3] + nums[4] = 1 + 2 + (-1) = 2 ≠ 0
  The distinct triplets are [-1,-1,2] and [-1,0,1].
```

---

# 🧠 Approach: Sort + Two Pointers

The key insight is:

> Sort the array first, then fix one element and use two pointers to find the remaining two elements that sum to zero.

### Why this works:

1. **Sorting** allows us to use two-pointer technique efficiently.
2. **Fixing one element** reduces the problem to Two Sum.
3. **Skipping duplicates** ensures no repeated triplets.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Fix one element and use two pointers
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Optimization: if smallest is > 0, no solution
            if (nums[i] > 0) break;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return result;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 `sort(nums.begin(), nums.end());`

* Sorts the array in **ascending order**.
* This is essential for the two-pointer technique.
* Example: `[-1, 0, 1, 2, -1, -4]` → `[-4, -1, -1, 0, 1, 2]`

---

### 🔹 `for (int i = 0; i < n - 2; i++)`

* We fix `nums[i]` as the **first element** of the triplet.
* Loop goes up to `n - 2` because we need at least 2 more elements.

---

### 🔹 `if (i > 0 && nums[i] == nums[i - 1]) continue;`

* **Skip duplicate** values for the first element.
* If `nums[i]` is same as `nums[i-1]`, we already explored all triplets starting with this value.

Example:
```
[-1, -1, 0, 1, 2]
  i=0 → process -1
  i=1 → skip (same as nums[0])
```

---

### 🔹 `if (nums[i] > 0) break;`

* **Optimization**: If the first element is positive, the sum of three positive numbers can never be zero.
* Since the array is sorted, all remaining elements are also positive.
* So we can stop early.

---

### 🔹 `int left = i + 1; int right = n - 1;`

* `left` starts just after `i`.
* `right` starts at the end of the array.
* Together they form a **search window** for the remaining two elements.

---

### 🔹 `int sum = nums[i] + nums[left] + nums[right];`

* Calculate the sum of the current triplet.
* Three possible outcomes:
  - `sum == 0` → Found a valid triplet ✅
  - `sum < 0` → Need a larger sum → move `left` right
  - `sum > 0` → Need a smaller sum → move `right` left

---

### 🔹 If `sum == 0` → Found a Triplet

```cpp
result.push_back({nums[i], nums[left], nums[right]});
```

* Add the triplet to the result.

---

### 🔹 Skip Duplicates After Finding a Triplet

```cpp
while (left < right && nums[left] == nums[left + 1]) left++;
while (left < right && nums[right] == nums[right - 1]) right--;
left++;
right--;
```

* After finding a valid triplet, skip all duplicate values on both sides.
* Then move both pointers inward to search for more triplets.

---

### 🔹 If `sum < 0` → Move Left Pointer

```cpp
left++;
```

* Sum is too small. Moving `left` right increases the sum (sorted array).

---

### 🔹 If `sum > 0` → Move Right Pointer

```cpp
right--;
```

* Sum is too large. Moving `right` left decreases the sum (sorted array).

---

# 📊 Step-by-Step Example

Input:

```
nums = [-1, 0, 1, 2, -1, -4]
After sorting: [-4, -1, -1, 0, 1, 2]
```

### Iteration 1: `i = 0`, `nums[i] = -4`

| left | right | nums[left] | nums[right] | sum  | Action     |
| ---- | ----- | ---------- | ----------- | ---- | ---------- |
| 1    | 5     | -1         | 2           | -3   | left++     |
| 2    | 5     | -1         | 2           | -3   | left++     |
| 3    | 5     | 0          | 2           | -2   | left++     |
| 4    | 5     | 1          | 2           | -1   | left++     |

No triplets found for `-4`.

### Iteration 2: `i = 1`, `nums[i] = -1`

| left | right | nums[left] | nums[right] | sum  | Action               |
| ---- | ----- | ---------- | ----------- | ---- | -------------------- |
| 2    | 5     | -1         | 2           | 0    | ✅ Found [-1,-1,2]   |
| 3    | 4     | 0          | 1           | 0    | ✅ Found [-1,0,1]    |

### Iteration 3: `i = 2`, `nums[i] = -1`

* Skip! Same as `nums[1]` (duplicate).

### Iteration 4: `i = 3`, `nums[i] = 0`

* `nums[i] = 0`, `left = 4`, `right = 5`
* Sum = `0 + 1 + 2 = 3 > 0` → right--
* `left == right` → stop

✅ Final Answer = **[[-1,-1,2], [-1,0,1]]**

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(n²)**

* Sorting takes `O(n log n)`.
* The two-pointer scan for each fixed element takes `O(n)`.
* Total: `O(n log n) + O(n²)` = **O(n²)**.

---

### 🔹 Space Complexity: **O(1)** (excluding output)

* We only use a few pointer variables.
* The sorting is in-place.
* Output space depends on the number of triplets.

---

# ⚔️ Comparison With Brute Force

| Approach                        | Time Complexity | Space Complexity |
| ------------------------------- | --------------- | ---------------- |
| Brute Force (Three Nested Loops)| O(n³)           | O(1)             |
| Sort + Two Pointers (Optimized) | O(n²)           | O(1)             |

Sorting + two pointers reduces the complexity by an entire order of magnitude 🚀

---

# ⭐ Key Concepts Learned

* Reducing a 3-element problem to a 2-element problem (Two Sum)
* Sorting as a preprocessing step for two pointers
* Duplicate skipping techniques
* Early termination optimizations
* How fixing one variable simplifies a multi-variable problem

---

# 🏆 Why This Problem Is Important

* One of the most frequently asked **medium** interview problems
* Builds upon Two Sum — shows how to extend solutions
* Teaches sorting + two-pointer paradigm
* Tests edge case handling (duplicates, all zeros, no solution)
* Commonly asked at Google, Amazon, Facebook, Microsoft
