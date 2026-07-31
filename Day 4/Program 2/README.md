
# 🧮 Product of Array Except Self – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #238 – Medium)

Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the **product of all the elements** of `nums` **except** `nums[i]`.

The product of any prefix or suffix of `nums` is **guaranteed** to fit in a 32-bit integer.

You must write an algorithm that runs in **O(n)** time and **without using the division operator**.

Example:

```
Input:  nums = [1, 2, 3, 4]
Output: [24, 12, 8, 6]
Explanation:
  answer[0] = 2 × 3 × 4 = 24
  answer[1] = 1 × 3 × 4 = 12
  answer[2] = 1 × 2 × 4 = 8
  answer[3] = 1 × 2 × 3 = 6
```

More examples:

```
Input:  [-1, 1, 0, -3, 3]
Output: [0, 0, 9, 0, 0]
```

---

# 🧠 Approach: Prefix and Suffix Products

The key insight is:

> For each element `nums[i]`, the product of all elements except itself = **(product of all elements to the LEFT)** × **(product of all elements to the RIGHT)**.

```
answer[i] = prefix_product[i] × suffix_product[i]
```

### Two-pass strategy:

1. **Pass 1 (Left → Right)**: Compute prefix products (product of all elements before index `i`).
2. **Pass 2 (Right → Left)**: Multiply by suffix products (product of all elements after index `i`).

### Why no division?

The constraint says we **cannot use division**. Otherwise we could just compute total product and divide by `nums[i]` — but that fails when zeros exist and is explicitly forbidden.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        // Step 1: Calculate prefix products
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // Step 2: Multiply by suffix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 `vector<int> answer(n, 1);`

* Create the result array of size `n`, initialized to `1`.
* We'll build the answer in-place using two passes.
* Initializing to `1` because it's the multiplicative identity.

---

### 🔹 Step 1: Prefix Products (Left → Right)

```cpp
int prefix = 1;
for (int i = 0; i < n; i++) {
    answer[i] = prefix;
    prefix *= nums[i];
}
```

#### What happens:

* `prefix` starts at `1` (no elements to the left of index 0).
* For each `i`, store the running prefix product in `answer[i]`.
* Then multiply `prefix` by `nums[i]` for the next iteration.

#### After this pass, `answer[i]` = product of all elements **before** index `i`:

```
nums    = [1,  2,  3,  4]
answer  = [1,  1,  2,  6]
           ↑   ↑   ↑   ↑
           1   1   1×2 1×2×3
```

---

### 🔹 Step 2: Suffix Products (Right → Left)

```cpp
int suffix = 1;
for (int i = n - 1; i >= 0; i--) {
    answer[i] *= suffix;
    suffix *= nums[i];
}
```

#### What happens:

* `suffix` starts at `1` (no elements to the right of last index).
* For each `i` (going right to left), multiply `answer[i]` by the running suffix.
* Then multiply `suffix` by `nums[i]` for the next iteration.

#### After this pass, `answer[i]` = prefix × suffix = product of everything except `nums[i]`:

```
Before suffix pass:  answer = [1,  1,  2,  6]
Suffix values:                [24, 12,  4,  1]
After multiply:      answer = [24, 12,  8,  6]
```

---

### 🔹 `return answer;`

* Return the completed result array.

---

# 📊 Step-by-Step Example

Input:

```
nums = [1, 2, 3, 4]
```

### Pass 1: Prefix Products (Left → Right)

| i | prefix (before) | answer[i] = prefix | prefix (after) = prefix × nums[i] |
| - | --------------- | ------------------- | ---------------------------------- |
| 0 | 1               | 1                   | 1 × 1 = 1                         |
| 1 | 1               | 1                   | 1 × 2 = 2                         |
| 2 | 2               | 2                   | 2 × 3 = 6                         |
| 3 | 6               | 6                   | 6 × 4 = 24                        |

**answer after Pass 1** = `[1, 1, 2, 6]`

### Pass 2: Suffix Products (Right → Left)

| i | suffix (before) | answer[i] *= suffix | suffix (after) = suffix × nums[i] |
| - | --------------- | ------------------- | ---------------------------------- |
| 3 | 1               | 6 × 1 = 6          | 1 × 4 = 4                         |
| 2 | 4               | 2 × 4 = 8          | 4 × 3 = 12                        |
| 1 | 12              | 1 × 12 = 12        | 12 × 2 = 24                       |
| 0 | 24              | 1 × 24 = 24        | 24 × 1 = 24                       |

**answer after Pass 2** = `[24, 12, 8, 6]`

✅ Final Answer = **[24, 12, 8, 6]**

---

# 🎯 Why This Works — Visual Proof

For `nums = [a, b, c, d]`:

```
answer[0] = _ × b × c × d     (everything except a)
answer[1] = a × _ × c × d     (everything except b)
answer[2] = a × b × _ × d     (everything except c)
answer[3] = a × b × c × _     (everything except d)
```

Split into prefix × suffix:

```
answer[0] = (1)     × (b×c×d)  = prefix[0] × suffix[0]
answer[1] = (a)     × (c×d)    = prefix[1] × suffix[1]
answer[2] = (a×b)   × (d)      = prefix[2] × suffix[2]
answer[3] = (a×b×c) × (1)      = prefix[3] × suffix[3]
```

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(n)**

* Pass 1: One traversal left to right → O(n).
* Pass 2: One traversal right to left → O(n).
* Total: **O(2n) = O(n)**.

---

### 🔹 Space Complexity: **O(1)** (excluding output)

* We only use two extra variables: `prefix` and `suffix`.
* The `answer` array is the required output, not extra space.

---

# ⚔️ Comparison With Other Approaches

| Approach                    | Time Complexity | Space Complexity | Division? |
| --------------------------- | --------------- | ---------------- | --------- |
| Brute Force (Nested Loops)  | O(n²)           | O(1)             | No        |
| Division Method             | O(n)            | O(1)             | Yes ❌    |
| Two Extra Arrays             | O(n)            | O(n)             | No        |
| Prefix + Suffix (Optimized) | O(n)            | O(1)             | No ✅     |

The prefix-suffix approach is **optimal** — O(n) time, O(1) extra space, no division 🚀

---

# ⭐ Key Concepts Learned

* **Prefix product** and **suffix product** technique
* Building the answer in-place using two passes
* Avoiding division — important constraint handling
* Using the output array as working space to save memory
* Multiplicative identity (`1`) as the base case

---

# 🏆 Why This Problem Is Important

* One of the **top 50 most asked** LeetCode problems
* Teaches the prefix/suffix pattern used in many array problems
* Tests ability to handle constraints (no division, O(n) time)
* Demonstrates space optimization by reusing the output array
* Frequently asked at Amazon, Google, Apple, Microsoft, Meta
