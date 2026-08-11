
# 🦘 Jump Game – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #55 – Medium)

You are given an integer array `nums`. You are initially positioned at the array's **first index**, and each element represents your **maximum jump length** at that position.

Return `true` if you can reach the **last index**, or `false` otherwise.

Example:

```
Input:  nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Input:  nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 (value 0), stuck forever.
```

---

# 🧠 Approach: Greedy (Track Maximum Reach)

The key insight is:

> At each position, track the **farthest index** we can possibly reach. If at any point our current index exceeds our maximum reach, we're stuck.

### The greedy choice:

- At each index `i`, we can jump to any index from `i+1` to `i + nums[i]`.
- We greedily update `maxReach = max(maxReach, i + nums[i])`.
- If `maxReach >= last index` → we can reach the end ✅
- If `i > maxReach` → we can't even reach index `i` → stuck ❌

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) {
                return false;
            }

            maxReach = max(maxReach, i + nums[i]);

            if (maxReach >= nums.size() - 1) {
                return true;
            }
        }

        return true;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 `int maxReach = 0;`

* The **farthest index** we can reach from any position we've visited so far.
* Initially `0` — we start at index 0 and haven't moved yet.

---

### 🔹 `for (int i = 0; i < nums.size(); i++)`

* Iterate through each index in the array.
* We process positions **in order** — from left to right.

---

### 🔹 Check If We're Stuck

```cpp
if (i > maxReach) {
    return false;
}
```

#### What this means:

* If the current index `i` is **beyond** our `maxReach`, we can't be here.
* There's no way to reach this position → we're stuck.
* Return `false` immediately.

#### Example: `[3, 2, 1, 0, 4]`

```
Index 0: maxReach = max(0, 0+3) = 3 ✓ (can reach up to index 3)
Index 1: maxReach = max(3, 1+2) = 3 ✓
Index 2: maxReach = max(3, 2+1) = 3 ✓
Index 3: maxReach = max(3, 3+0) = 3 ✓ (nums[3]=0, can't jump further!)
Index 4: i=4 > maxReach=3 → STUCK! return false ❌
```

---

### 🔹 Update Maximum Reach

```cpp
maxReach = max(maxReach, i + nums[i]);
```

* From position `i`, we can jump up to `nums[i]` steps.
* The farthest we can reach from here is `i + nums[i]`.
* Update `maxReach` if this extends our range.

---

### 🔹 Early Exit

```cpp
if (maxReach >= nums.size() - 1) {
    return true;
}
```

* If our reach extends to or beyond the last index, we can make it!
* No need to check further — return `true` immediately.

---

# 📊 Step-by-Step Example 1 (Reachable)

Input:

```
nums = [2, 3, 1, 1, 4]
Last index = 4
```

| i | nums[i] | i > maxReach? | i + nums[i] | maxReach | Reach end? |
| - | ------- | ------------- | ----------- | -------- | ---------- |
| 0 | 2       | 0 > 0? No    | 0 + 2 = 2   | 2        | 2 ≥ 4? No  |
| 1 | 3       | 1 > 2? No    | 1 + 3 = 4   | 4        | 4 ≥ 4? Yes ✅ |

✅ Final Answer = **true** (reached at step 2!)

---

# 📊 Step-by-Step Example 2 (Stuck)

Input:

```
nums = [3, 2, 1, 0, 4]
Last index = 4
```

| i | nums[i] | i > maxReach? | i + nums[i] | maxReach | Reach end? |
| - | ------- | ------------- | ----------- | -------- | ---------- |
| 0 | 3       | 0 > 0? No    | 0 + 3 = 3   | 3        | 3 ≥ 4? No  |
| 1 | 2       | 1 > 3? No    | 1 + 2 = 3   | 3        | 3 ≥ 4? No  |
| 2 | 1       | 2 > 3? No    | 2 + 1 = 3   | 3        | 3 ≥ 4? No  |
| 3 | 0       | 3 > 3? No    | 3 + 0 = 3   | 3        | 3 ≥ 4? No  |
| 4 | 4       | 4 > 3? **Yes** ❌ | —       | —        | —          |

✅ Final Answer = **false** (stuck at index 4, can't reach it)

---

# 🎯 Visual Representation

```
Example 1: [2, 3, 1, 1, 4]

Index:  0  1  2  3  4
Value:  2  3  1  1  4
        └──┼──┘
           └──────┼──┘  ← Can reach end!

Example 2: [3, 2, 1, 0, 4]

Index:  0  1  2  3  4
Value:  3  2  1  0  4
        └──┼──┼──┘
           └──┼──┘
              └──┘
                  ✖     ← Index 3 has value 0, STUCK!
```

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(n)**

* Single pass through the array.
* Each element visited at most once.

---

### 🔹 Space Complexity: **O(1)**

* Only one variable `maxReach` used.
* No extra data structures.

---

# ⚔️ Comparison With Other Approaches

| Approach                    | Time Complexity | Space Complexity |
| --------------------------- | --------------- | ---------------- |
| Brute Force (Try All Paths) | O(2ⁿ)           | O(n)             |
| Dynamic Programming         | O(n²)           | O(n)             |
| Greedy (Max Reach)           | O(n)            | O(1)             |

The greedy approach is **optimal** — linear time, constant space 🚀

---

# 💡 Why Greedy Works Here

The greedy choice is **safe** because:

1. If we can reach index `i`, we can reach **all indices** from `0` to `i`.
2. The maximum reach is **monotonically non-decreasing** (it can only grow or stay the same).
3. We never need to backtrack — reaching farther is always better.

This means we don't need to explore all possible jump sequences — just tracking the farthest reach is sufficient.

---

# ⭐ Key Concepts Learned

* **Greedy algorithm** — making the locally optimal choice
* Tracking a **running maximum** (maxReach)
* Early termination in both success and failure cases
* Why greedy works: monotonic property of reachability
* Reducing exponential/quadratic DP to linear greedy

---

# 🏆 Why This Problem Is Important

* Classic **greedy** problem — introduces the greedy paradigm
* Foundation for Jump Game II (minimum jumps) and other variants
* Tests understanding of reachability and greedy correctness
* Real-world analogy: can you cross stepping stones?
* Commonly asked at Amazon, Google, Microsoft, Facebook, Goldman Sachs
