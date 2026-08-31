
# 🔢 Single Number II – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #137 – Medium)

Given an integer array `nums` where every element appears **three times** except for one, which appears **exactly once**. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example:

```
Input: nums = [2,2,3,2]
Output: 3

Input: nums = [0,1,0,1,0,1,99]
Output: 99
```

---

# 🧠 Approach: Bit Manipulation (Digital Logic Design)

The key insight is:

> If a number appears 3 times, then at any specific bit position (0 to 31), the sum of the bits contributed by this number will be a multiple of 3 (either 0 or 3).
> We can build a state machine to track the number of times we've seen a `1` at each bit position, modulo 3.
> Since modulo 3 has 3 states (0, 1, 2), we need 2 bits to represent the state. We'll use two integer variables: `ones` (tracks bits seen exactly once) and `twos` (tracks bits seen exactly twice).

*(Note: There is a simpler O(32 * N) solution where you manually count the bits in a loop, but this `O(N)` digital logic approach is the most optimal and famous "magic" bitwise solution).*

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        
        return ones;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 State Variables

```cpp
int ones = 0;
int twos = 0;
```
* `ones` will hold the bits that have appeared 1 time so far (modulo 3).
* `twos` will hold the bits that have appeared 2 times so far (modulo 3).
* When a bit appears a 3rd time, it will be cleared from both `ones` and `twos` (resetting to state 0).

---

### 🔹 Updating `ones`

```cpp
for (int num : nums) {
    ones = (ones ^ num) & ~twos;
```
* `ones ^ num`: XOR adds the bits of `num` to `ones`. If a bit was `0`, it becomes `1`. If a bit was `1`, it becomes `0` (meaning it's moving to the `twos` state).
* `& ~twos`: This is the crucial part. If a bit is already in `twos` (meaning it's now appearing for the 3rd time), `~twos` will have a `0` at that position. The `&` operation will then force that bit to `0` in `ones`. This prevents a bit from being recorded in `ones` if it's currently on its 3rd appearance.

---

### 🔹 Updating `twos`

```cpp
    twos = (twos ^ num) & ~ones;
}
```
* `twos ^ num`: XOR adds the bits of `num` to `twos`.
* `& ~ones`: Similar logic. We only want a bit to stay in `twos` if it is NOT currently in `ones`. If it's in `ones`, it means it just appeared for the 1st time, so it shouldn't be in `twos` yet.

---

# 📊 Step-by-Step Example

Let's trace a single bit position. We see the bit `1` three times, then `0`.

**Initial:** `ones = 0`, `twos = 0`

**1st appearance of bit '1':**
- `ones = (0 ^ 1) & ~0` -> `1 & 1` = **1**
- `twos = (0 ^ 1) & ~1` -> `1 & 0` = **0**
State: `ones=1, twos=0` (Seen 1 time)

**2nd appearance of bit '1':**
- `ones = (1 ^ 1) & ~0` -> `0 & 1` = **0**
- `twos = (0 ^ 1) & ~0` -> `1 & 1` = **1**
State: `ones=0, twos=1` (Seen 2 times)

**3rd appearance of bit '1':**
- `ones = (0 ^ 1) & ~1` -> `1 & 0` = **0**
- `twos = (1 ^ 1) & ~0` -> `0 & 1` = **0**
State: `ones=0, twos=0` (Reset! Seen 3 times)

---

### 🔹 Final Result

```cpp
return ones;
```
* After iterating through all numbers, every number that appeared 3 times will have cycled its bits back to `0` in both `ones` and `twos`.
* The single number that appeared only 1 time will have its bits left in the `ones` variable. We return `ones`.

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(N)**
* We iterate through the array of size `N` exactly once. The bitwise operations inside the loop run in `O(1)` time.

### 🔹 Space Complexity: **O(1)**
* We only use two integer variables, regardless of the input size.
