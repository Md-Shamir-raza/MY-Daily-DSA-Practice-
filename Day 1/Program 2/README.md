
# 🚀 Maximum Subarray (Kadane’s Algorithm) – C++ Explanation

## 📌 Problem Statement

Given an integer array `nums`, find the **contiguous subarray** (containing at least one number) which has the largest sum and return its sum.

Example:

```
Input:  [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6
```

---

# 🧠 Approach: Kadane’s Algorithm (Greedy + Dynamic Programming)

Kadane’s Algorithm works on the idea:

> If the current sum becomes negative, discard it and start fresh from the next element.

Because a negative sum will only decrease the total sum of future subarrays.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0;
        int maxsum = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            currsum += nums[i];
            maxsum = max(currsum, maxsum);

            if(currsum < 0)
                currsum = 0;
        }

        return maxsum;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 `int currsum = 0;`

* Stores the **current subarray sum**
* It keeps adding elements one by one

---

### 🔹 `int maxsum = INT_MIN;`

* Stores the **maximum subarray sum found so far**
* Initialized with `INT_MIN` to handle cases where all numbers are negative

Example:
If array is `[-3, -2, -1]`
Answer should be `-1`
So we cannot initialize maxsum as `0`.

---

### 🔹 Loop Through Array

```cpp
for(int i = 0; i < nums.size(); i++)
```

We iterate through each element of the array.

---

### 🔹 Add Current Element

```cpp
currsum += nums[i];
```

We keep extending the current subarray.

---

### 🔹 Update Maximum Sum

```cpp
maxsum = max(currsum, maxsum);
```

We compare:

* Current subarray sum
* Maximum sum found so far

And store the larger one.

---

### 🔹 Reset If Negative

```cpp
if(currsum < 0)
    currsum = 0;
```

If current sum becomes negative:

* It will reduce future subarray sums
* So we discard it and start fresh

---

### 🔹 Return Result

```cpp
return maxsum;
```

Return the largest subarray sum found.

---

# 📊 Step-by-Step Example

Input:

```
[-2,1,-3,4,-1,2,1,-5,4]
```

| Index | Element | currsum         | maxsum |
| ----- | ------- | --------------- | ------ |
| 0     | -2      | -2 → reset to 0 | -2     |
| 1     | 1       | 1               | 1      |
| 2     | -3      | -2 → reset      | 1      |
| 3     | 4       | 4               | 4      |
| 4     | -1      | 3               | 4      |
| 5     | 2       | 5               | 5      |
| 6     | 1       | 6               | 6      |
| 7     | -5      | 1               | 6      |
| 8     | 4       | 5               | 6      |

✅ Final Answer = **6**

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(n)**

* We traverse the array only once.
* Each element is processed exactly one time.

---

### 🔹 Space Complexity: **O(1)**

* We only use two variables:

  * `currsum`
  * `maxsum`
* No extra data structures are used.

---

# ⚔️ Comparison With Brute Force

| Approach                   | Time Complexity | Space Complexity |
| -------------------------- | --------------- | ---------------- |
| Brute Force (Nested Loops) | O(n²)           | O(1)             |
| Kadane’s Algorithm         | O(n)            | O(1)             |

Kadane’s algorithm is highly optimized and commonly asked in coding interviews.

---

# ⭐ Key Concepts Learned

* Greedy approach
* Dynamic Programming intuition
* Handling negative numbers
* Optimizing from O(n²) to O(n)

---

# 🏆 Why This Algorithm Is Important

* Frequently asked in interviews
* Foundation for many advanced problems
* Teaches optimal substructure thinking

