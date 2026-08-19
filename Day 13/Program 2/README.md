
# 📈 Longest Increasing Subsequence – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #300 – Medium)

Given an integer array `nums`, return the length of the **longest strictly increasing subsequence**.

A **subsequence** is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements. (e.g., `[3, 6, 2, 7]` is a subsequence of the array `[0, 3, 1, 6, 2, 2, 7]`).

Example:

```
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
```

More examples:

```
Input: nums = [0,1,0,3,2,3]
Output: 4
Explanation: Subsequence is [0,1,2,3].

Input: nums = [7,7,7,7,7,7,7]
Output: 1
```

---

# 🧠 Approach: Dynamic Programming (O(N²))

The key insight is:

> Let `dp[i]` be the length of the longest increasing subsequence that **ends exactly at index `i`**.
> To calculate `dp[i]`, we can look back at all previous indices `j` (where `j < i`). If `nums[i] > nums[j]`, it means we can append `nums[i]` to the subsequence ending at `j`.
> Thus, `dp[i] = max(dp[i], dp[j] + 1)`.

*Note: There is an O(N log N) solution using Binary Search, but the O(N²) DP approach is the classic foundation for understanding sequence-based DP.*

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> dp(nums.size(), 1);
        int maxLength = 1;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 Initialize DP Array

```cpp
if (nums.empty()) return 0;
vector<int> dp(nums.size(), 1);
int maxLength = 1;
```
* Edge case: If the input is empty, return 0.
* We create a `dp` array of the same size as `nums`.
* Every element is initialized to `1`. Why? Because the shortest possible increasing subsequence ending at any index is just the element itself (length 1).
* `maxLength` keeps track of the absolute longest subsequence we've found across the entire array.

---

### 🔹 Outer Loop (The Current Element)

```cpp
for (int i = 1; i < nums.size(); i++) {
```
* We iterate through the array starting from index 1 (since `dp[0]` is already correctly initialized to 1). `i` represents the end element of the subsequence we are currently evaluating.

---

### 🔹 Inner Loop (Checking Previous Elements)

```cpp
for (int j = 0; j < i; j++) {
```
* For the element at `i`, we look back at *all* previous elements at index `j`.

---

### 🔹 DP Transition

```cpp
if (nums[i] > nums[j]) {
    dp[i] = max(dp[i], dp[j] + 1);
}
```
* `if (nums[i] > nums[j])`: This checks if the sequence is strictly increasing. If the current element is greater than the previous element `j`, we can extend the sequence ending at `j`.
* `dp[i] = max(...)`: We update `dp[i]`. It either stays its current value, or it becomes `dp[j] + 1` (the length of the subsequence ending at `j`, plus 1 for adding the current element `i`). We want the *maximum* possible length.

---

### 🔹 Update Global Maximum

```cpp
maxLength = max(maxLength, dp[i]);
```
* After evaluating all previous elements `j` and settling on the final `dp[i]`, we check if `dp[i]` is the longest subsequence we've found overall.
* This is necessary because the longest increasing subsequence doesn't necessarily have to end at the very last element of the array.

---

# 📊 Step-by-Step Example

Input: `nums = [10, 9, 2, 5, 3, 7]`

**Initialization:** `dp = [1, 1, 1, 1, 1, 1]`

**i = 1 (val: 9):**
- j=0 (val: 10). 9 < 10, skip.
`dp = [1, 1, 1, 1, 1, 1]`

**i = 2 (val: 2):**
- j=0, 1 (vals: 10, 9). 2 < both, skip.
`dp = [1, 1, 1, 1, 1, 1]`

**i = 3 (val: 5):**
- j=0, 1 (vals: 10, 9). 5 < both, skip.
- j=2 (val: 2). 5 > 2. `dp[3] = max(1, dp[2]+1) = 2`. (Seq: [2, 5])
`dp = [1, 1, 1, 2, 1, 1]`

**i = 4 (val: 3):**
- j=0, 1 (vals: 10, 9). skip.
- j=2 (val: 2). 3 > 2. `dp[4] = max(1, dp[2]+1) = 2`. (Seq: [2, 3])
- j=3 (val: 5). 3 < 5, skip.
`dp = [1, 1, 1, 2, 2, 1]`

**i = 5 (val: 7):**
- j=0, 1. skip.
- j=2 (val: 2). 7 > 2. `dp[5] = max(1, dp[2]+1) = 2`.
- j=3 (val: 5). 7 > 5. `dp[5] = max(2, dp[3]+1) = 3`. (Seq: [2, 5, 7])
- j=4 (val: 3). 7 > 3. `dp[5] = max(3, dp[4]+1) = 3`. (Seq: [2, 3, 7])
`dp = [1, 1, 1, 2, 2, 3]`

✅ Max value in `dp` is **3**.

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(N²)**
* The outer loop runs `N` times.
* The inner loop runs `i` times (up to `N`).
* Total operations: `1 + 2 + 3 + ... + N = O(N²)`.

---

### 🔹 Space Complexity: **O(N)**
* We use a `dp` array of size `N` to store the lengths of the longest subsequences.

---

# ⭐ Key Concepts Learned
* **Subsequences vs Subarrays**: Subsequences don't need to be contiguous, which is why we must look back at *all* previous indices `j`, not just `i-1`.
* **State Definition in DP**: Defining `dp[i]` as the answer *ending exactly at index i* is a very common and powerful pattern for 1D arrays/strings.

---

# 🏆 Why This Problem Is Important
* It is one of the most famous and foundational Dynamic Programming problems (often abbreviated as LIS).
* Many other problems can be reduced to finding an LIS (e.g., Russian Doll Envelopes).
