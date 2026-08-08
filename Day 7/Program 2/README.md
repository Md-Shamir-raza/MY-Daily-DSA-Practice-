
# 🔢 Next Permutation – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #31 – Medium)

A **permutation** of an array of integers is an arrangement of its members into a sequence. The **next permutation** is the next lexicographically greater permutation.

If the array is the **last permutation** (fully descending), rearrange it as the **first permutation** (fully ascending).

The replacement must be done **in place** with only constant extra memory.

Example:

```
Input:  [1, 2, 3]
Output: [1, 3, 2]

Input:  [3, 2, 1]
Output: [1, 2, 3]  (wraps around to first permutation)

Input:  [1, 1, 5]
Output: [1, 5, 1]
```

All permutations of [1,2,3] in order:
```
[1,2,3] → [1,3,2] → [2,1,3] → [2,3,1] → [3,1,2] → [3,2,1] → wraps to [1,2,3]
```

---

# 🧠 Approach: The Standard Next Permutation Algorithm

The algorithm has **4 steps**:

### Step 1: Find the "dip"
Scan from **right to left** to find the first element that is **smaller** than its right neighbor.
Call this index `i`.

### Step 2: Find the swap partner
Scan from **right to left** to find the **smallest element greater** than `nums[i]`.
Call this index `j`.

### Step 3: Swap
Swap `nums[i]` and `nums[j]`.

### Step 4: Reverse the suffix
Reverse everything after index `i` to get the **smallest** possible suffix.

### Why this works:
- Step 1 finds the rightmost position where we can make the permutation "bigger".
- Step 2 finds the next larger digit to place at position `i`.
- Step 4 ensures the rest is as small as possible (ascending order).

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find first decreasing element from right
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // Step 2: Find smallest element > nums[i] from right
            int j = n - 1;
            while (j > i && nums[j] <= nums[i]) {
                j--;
            }

            // Step 3: Swap
            swap(nums[i], nums[j]);
        }

        // Step 4: Reverse suffix after i
        reverse(nums.begin() + i + 1, nums.end());
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 Step 1: Find the Dip

```cpp
int i = n - 2;
while (i >= 0 && nums[i] >= nums[i + 1]) {
    i--;
}
```

#### What happens:

* Start from the second-to-last element.
* Move left as long as elements are in **non-increasing** order.
* Stop at the first element that is **smaller** than its right neighbor.

#### Example: `[1, 3, 5, 4, 2]`

```
Compare from right:
  2 vs nothing → skip (start from i=3)
  4 >= 2 → continue left (i=2)
  5 >= 4 → continue left (i=1)
  3 < 5  → STOP! i = 1
```

The "dip" is at index 1 (value 3).

#### If `i < 0`:
* The entire array is in descending order → it's the **last permutation**.
* We skip Steps 2 and 3, and just reverse the whole array.

---

### 🔹 Step 2: Find the Swap Partner

```cpp
int j = n - 1;
while (j > i && nums[j] <= nums[i]) {
    j--;
}
```

#### What happens:

* From the right, find the **smallest element** that is **strictly greater** than `nums[i]`.
* Since the suffix is in descending order, the first element from the right that is greater than `nums[i]` is the one we want.

#### Example: `[1, 3, 5, 4, 2]`, `nums[i] = 3`

```
From right:
  2 <= 3 → continue (j=3)
  4 > 3  → STOP! j = 3
```

Swap partner is at index 3 (value 4).

---

### 🔹 Step 3: Swap

```cpp
swap(nums[i], nums[j]);
```

* Swap the dip element with the swap partner.

```
Before: [1, 3, 5, 4, 2]
              ↕      ↕
After:  [1, 4, 5, 3, 2]
```

**Key property**: The suffix after `i` is **still in descending order** after the swap!

---

### 🔹 Step 4: Reverse the Suffix

```cpp
reverse(nums.begin() + i + 1, nums.end());
```

* Reverse everything after index `i` to make it **ascending** (smallest possible suffix).

```
Before reverse: [1, 4, 5, 3, 2]
                       ^^^^^^^^^ descending
After reverse:  [1, 4, 2, 3, 5]
                       ^^^^^^^^^ ascending
```

✅ `[1, 4, 2, 3, 5]` is the next permutation of `[1, 3, 5, 4, 2]`.

---

# 📊 Step-by-Step Example

Input:

```
nums = [1, 3, 5, 4, 2]
```

### Step 1: Find the dip

```
Scan right to left: 4≥2 ✓, 5≥4 ✓, 3<5 STOP
i = 1, nums[i] = 3
```

### Step 2: Find swap partner

```
Scan right to left: 2≤3, 4>3 STOP
j = 3, nums[j] = 4
```

### Step 3: Swap nums[1] and nums[3]

```
[1, 3, 5, 4, 2] → [1, 4, 5, 3, 2]
```

### Step 4: Reverse suffix after index 1

```
[1, 4, 5, 3, 2] → [1, 4, 2, 3, 5]
```

✅ Final Answer = **[1, 4, 2, 3, 5]**

---

# 📊 Another Example: Last Permutation

Input:

```
nums = [3, 2, 1]
```

### Step 1: Find the dip

```
Scan: 2≥1 ✓, 3≥2 ✓ → no dip found, i = -1
```

### Steps 2 & 3: Skipped (i < 0)

### Step 4: Reverse entire array

```
[3, 2, 1] → [1, 2, 3]
```

✅ Wraps around to the first permutation.

---

# 🎯 All Permutations of [1,2,3] in Order

```
[1,2,3]  →  Step 1: i=1  →  swap 2,3  →  reverse nothing  →  [1,3,2]
[1,3,2]  →  Step 1: i=0  →  swap 1,2  →  reverse [3]→[3]  →  [2,1,3]
[2,1,3]  →  Step 1: i=1  →  swap 1,3  →  reverse nothing  →  [2,3,1]
[2,3,1]  →  Step 1: i=0  →  swap 2,3  →  reverse [2,1]→[1,2]  →  [3,1,2]
[3,1,2]  →  Step 1: i=1  →  swap 1,2  →  reverse nothing  →  [3,2,1]
[3,2,1]  →  Step 1: i=-1 →  reverse all  →  [1,2,3]
```

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(n)**

* Step 1: At most `n` comparisons.
* Step 2: At most `n` comparisons.
* Step 3: O(1) swap.
* Step 4: At most `n/2` swaps for reverse.
* Total: **O(n)**.

---

### 🔹 Space Complexity: **O(1)**

* All operations are done **in-place**.
* Only a few integer variables used.

---

# ⚔️ Comparison With Other Approaches

| Approach                        | Time Complexity | Space Complexity |
| ------------------------------- | --------------- | ---------------- |
| Generate All Permutations       | O(n!)           | O(n!)            |
| Sort-based (not in-place)       | O(n log n)      | O(n)             |
| Standard Algorithm (In-place)   | O(n)            | O(1)             |

The standard algorithm is **optimal** — linear time, constant space 🚀

---

# ⭐ Key Concepts Learned

* **Lexicographic ordering** of permutations
* The 4-step **next permutation algorithm**
* Why the suffix is always in descending order at the "dip"
* In-place array manipulation with swap and reverse
* Edge case handling: last permutation wraps to first

---

# 🏆 Why This Problem Is Important

* Fundamental **combinatorics** algorithm used in many applications
* C++ STL actually has `std::next_permutation` that uses this exact algorithm
* Tests understanding of lexicographic order and array manipulation
* Foundation for permutation-based problems
* Commonly asked at Google, Amazon, Microsoft, Goldman Sachs, Uber
