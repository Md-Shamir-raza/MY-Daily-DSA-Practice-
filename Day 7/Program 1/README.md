
# 🎯 Subarray Sum Equals K – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #560 – Medium)

Given an array of integers `nums` and an integer `k`, return the **total number of subarrays** whose sum equals `k`.

A **subarray** is a contiguous non-empty sequence of elements within an array.

Example:

```
Input:  nums = [1,1,1], k = 2
Output: 2
Explanation: Subarrays [1,1] (index 0-1) and [1,1] (index 1-2) both sum to 2.
```

More examples:

```
Input:  nums = [1,2,3], k = 3  → Output: 2  ([1,2] and [3])
Input:  nums = [1,-1,0], k = 0 → Output: 3  ([1,-1], [-1,0], [1,-1,0])
```

---

# 🧠 Approach: Prefix Sum + Hash Map

The key insight is:

> If `prefixSum[j] - prefixSum[i] = k`, then the subarray from index `i+1` to `j` has sum `k`.

So for each index `j`, we need to count how many previous prefix sums equal `prefixSum[j] - k`.

### Why can't we use Sliding Window?

* Sliding window works only for **positive numbers** (or when the window property is monotonic).
* This problem has **negative numbers**, so the prefix sum can go up and down.
* Hash map approach handles all cases.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;

        int count = 0;
        int prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            int target = prefixSum - k;
            if (prefixCount.find(target) != prefixCount.end()) {
                count += prefixCount[target];
            }

            prefixCount[prefixSum]++;
        }

        return count;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 `unordered_map<int, int> prefixCount;`

* A hash map that stores:
  - **Key**: A prefix sum value
  - **Value**: How many times this prefix sum has occurred

* This lets us quickly count how many earlier positions have a specific prefix sum.

---

### 🔹 `prefixCount[0] = 1;`

* **Critical initialization**: We start with prefix sum `0` having count `1`.
* This represents the "empty prefix" — before any element.

#### Why is this needed?

* If `prefixSum` itself equals `k`, then the subarray from index `0` to current index has sum `k`.
* We need `prefixSum - k = 0` to exist in the map to count this.

Example: `nums = [3], k = 3`
- `prefixSum = 3`, `target = 3 - 3 = 0`
- Without `prefixCount[0] = 1`, we'd miss this subarray!

---

### 🔹 `int count = 0;`

* Counter for the total number of valid subarrays.

---

### 🔹 `int prefixSum = 0;`

* Running sum from index `0` to the current index.

---

### 🔹 `prefixSum += nums[i];`

* Add the current element to the running prefix sum.
* After this line: `prefixSum = nums[0] + nums[1] + ... + nums[i]`

---

### 🔹 The Core Logic

```cpp
int target = prefixSum - k;
if (prefixCount.find(target) != prefixCount.end()) {
    count += prefixCount[target];
}
```

#### The mathematical insight:

```
If prefixSum[j] - prefixSum[i] = k
Then prefixSum[i] = prefixSum[j] - k
```

* `target = prefixSum - k` is the value we're looking for.
* If this value appeared `n` times before → there are `n` subarrays ending at index `i` with sum `k`.
* We add all `n` to our count.

---

### 🔹 `prefixCount[prefixSum]++;`

* Store the current prefix sum in the map (increment its count).
* Future iterations can use this to find subarrays ending at later indices.

#### Order matters!

* We **check first**, then **store**.
* This ensures we don't count a subarray that starts and ends at the same position (zero length).

---

# 📊 Step-by-Step Example

Input:

```
nums = [1, 1, 1], k = 2
```

| i | nums[i] | prefixSum | target (pSum-k) | prefixCount (before) | Found? | count | prefixCount (after) |
| - | ------- | --------- | --------------- | -------------------- | ------ | ----- | ------------------- |
| — | —       | 0         | —               | {0:1}                | —      | 0     | {0:1}               |
| 0 | 1       | 1         | 1-2 = -1        | {0:1}                | No     | 0     | {0:1, 1:1}          |
| 1 | 1       | 2         | 2-2 = 0         | {0:1, 1:1}           | Yes(1) | 1     | {0:1, 1:1, 2:1}     |
| 2 | 1       | 3         | 3-2 = 1         | {0:1, 1:1, 2:1}     | Yes(1) | 2     | {0:1, 1:1, 2:1, 3:1}|

✅ Final Answer = **2**

The two subarrays: `[1,1]` (index 0-1) and `[1,1]` (index 1-2).

---

# 🎯 Why Prefix Sum Works — Visual Proof

```
nums = [1, 1, 1]
Prefix sums: [1, 2, 3]

Subarray sum from i+1 to j = prefixSum[j] - prefixSum[i]

For sum = k = 2:
  prefixSum[1] - prefixSum[-1] = 2 - 0 = 2  ✅ → subarray [0..1]
  prefixSum[2] - prefixSum[0]  = 3 - 1 = 2  ✅ → subarray [1..2]
```

---

# 🔄 Example with Negative Numbers

Input:

```
nums = [1, -1, 0], k = 0
```

| i | nums[i] | prefixSum | target | Found? | count | Map |
| - | ------- | --------- | ------ | ------ | ----- | --- |
| — | —       | 0         | —      | —      | 0     | {0:1} |
| 0 | 1       | 1         | 1      | No     | 0     | {0:1, 1:1} |
| 1 | -1      | 0         | 0      | Yes(1) | 1     | {0:2, 1:1} |
| 2 | 0       | 0         | 0      | Yes(2) | 3     | {0:3, 1:1} |

✅ Final Answer = **3**

Subarrays: `[1,-1]`, `[-1,0]`, `[1,-1,0]`

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(n)**

* Single pass through the array.
* Hash map operations (find, insert) are O(1) average.

---

### 🔹 Space Complexity: **O(n)**

* The hash map stores at most `n+1` distinct prefix sums.

---

# ⚔️ Comparison With Other Approaches

| Approach                       | Time Complexity | Space Complexity |
| ------------------------------ | --------------- | ---------------- |
| Brute Force (All Subarrays)    | O(n²)           | O(1)             |
| Prefix Sum Array + Brute Force | O(n²)           | O(n)             |
| Prefix Sum + Hash Map          | O(n)            | O(n)             |

The prefix sum + hash map approach is **optimal** 🚀

---

# ⭐ Key Concepts Learned

* **Prefix Sum** — converting subarray sum to a difference of two prefix sums
* **Hash Map counting** — tracking frequency of seen values
* Why `prefixCount[0] = 1` is essential (empty subarray base case)
* Handling **negative numbers** (why sliding window fails here)
* The pattern: "find how many previous values satisfy a condition"

---

# 🏆 Why This Problem Is Important

* Combines two powerful techniques: **prefix sum + hash map**
* Teaches a pattern applicable to many subarray problems
* Cannot be solved with sliding window — tests deeper understanding
* Foundation for problems like "Subarray Sum Divisible by K"
* Commonly asked at Google, Amazon, Facebook, Microsoft, Bloomberg
