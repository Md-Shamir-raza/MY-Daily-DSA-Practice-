
# ⚡ Pow(x, n) – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #50 – Medium)

Implement `pow(x, n)`, which calculates `x` raised to the power `n` (i.e., `xⁿ`).

Example:

```
Input:  x = 2.0, n = 10
Output: 1024.0

Input:  x = 2.1, n = 3
Output: 9.261

Input:  x = 2.0, n = -2
Output: 0.25  (because 2⁻² = 1/2² = 0.25)
```

---

# 🧠 Approach: Binary Exponentiation (Fast Power)

The key insight is:

> Instead of multiplying `x` by itself `n` times (O(n)), we can **square and halve** to achieve **O(log n)**.

### The math behind it:

```
x¹⁰ = (x⁵)²
x⁵  = x × (x²)²
x²  = (x¹)²
```

So `x¹⁰` only needs **4 multiplications** instead of 10!

### Rules:

| Power | Action |
| ----- | ------ |
| Even  | `x^n = (x²)^(n/2)` → square x, halve n |
| Odd   | `x^n = x × x^(n-1)` → multiply result by x, then handle even |

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;

        if (power < 0) {
            x = 1.0 / x;
            power = -power;
        }

        double result = 1.0;

        while (power > 0) {
            if (power % 2 == 1) {
                result *= x;
            }
            x *= x;
            power /= 2;
        }

        return result;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 `long long power = n;`

* Convert `n` to `long long` to handle the edge case of `n = INT_MIN (-2147483648)`.
* `-INT_MIN` overflows in `int`, but fits in `long long`.

---

### 🔹 Handling Negative Exponents

```cpp
if (power < 0) {
    x = 1.0 / x;
    power = -power;
}
```

#### What happens:

* `x⁻ⁿ = (1/x)ⁿ`
* Convert the problem: invert `x` and make `power` positive.

Example:
```
2.0⁻² = (1/2.0)² = 0.5² = 0.25
```

---

### 🔹 `double result = 1.0;`

* Accumulates the final answer.
* Initialized to `1.0` (multiplicative identity).

---

### 🔹 The Binary Exponentiation Loop

```cpp
while (power > 0) {
    if (power % 2 == 1) {
        result *= x;
    }
    x *= x;
    power /= 2;
}
```

#### How it works:

Think of the exponent in **binary**:

```
10 in binary = 1010
x¹⁰ = x⁸ × x² = x^(1010₂)
```

The algorithm processes the binary representation from right to left:

| Bit | Action |
| --- | ------ |
| 1 (set) | Multiply `result` by current `x` |
| 0 (not set) | Skip multiplication |
| Always | Square `x` for the next bit position |

---

### 🔹 `if (power % 2 == 1)` — Odd Power Check

* If the current bit is `1`, this power of `x` contributes to the result.
* Multiply `result` by the current value of `x`.

---

### 🔹 `x *= x;` — Square

* Square `x` to represent the next higher power of 2.
* After iteration `i`: `x = original_x^(2^i)`

---

### 🔹 `power /= 2;` — Halve

* Move to the next bit of the exponent.

---

# 📊 Step-by-Step Example

Input: `x = 2.0, n = 10`

Binary of 10 = `1010`

| Step | power | power % 2 | result (before) | x (before) | Action | result (after) | x (after) |
| ---- | ----- | --------- | --------------- | ---------- | ------ | -------------- | --------- |
| 1    | 10    | 0 (even)  | 1.0             | 2.0        | Skip   | 1.0            | 4.0       |
| 2    | 5     | 1 (odd)   | 1.0             | 4.0        | Multiply | 4.0          | 16.0      |
| 3    | 2     | 0 (even)  | 4.0             | 16.0       | Skip   | 4.0            | 256.0     |
| 4    | 1     | 1 (odd)   | 4.0             | 256.0      | Multiply | 1024.0      | 65536.0   |

power = 0 → STOP

✅ Final Answer = **1024.0**

Verification: `2¹⁰ = 1024` ✅

---

# 🎯 Why Binary Exponentiation Works — Visual

```
2¹⁰ = ?

10 in binary = 1 0 1 0

Powers of 2:   2⁸ 2⁴ 2² 2¹
Bits:           1   0   1   0

2¹⁰ = 2⁸ × 2² = 256 × 4 = 1024

Only multiply the powers where the bit is 1!
```

---

# 📊 Example with Negative Exponent

Input: `x = 2.0, n = -2`

Step 1: Convert → `x = 1/2.0 = 0.5`, `power = 2`

| Step | power | power % 2 | result | x    |
| ---- | ----- | --------- | ------ | ---- |
| 1    | 2     | 0 (even)  | 1.0    | 0.25 |
| 2    | 1     | 1 (odd)   | 0.25   | 0.0625 |

✅ Final Answer = **0.25**

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(log n)**

* We halve the exponent in every iteration.
* Number of iterations = number of bits in `n` = `O(log n)`.

---

### 🔹 Space Complexity: **O(1)**

* Only a few variables used.
* No recursion stack (iterative approach).

---

# ⚔️ Comparison With Other Approaches

| Approach                    | Time Complexity | Space Complexity |
| --------------------------- | --------------- | ---------------- |
| Naive (Multiply n times)    | O(n)            | O(1)             |
| Recursive Binary Exponent   | O(log n)        | O(log n) stack   |
| Iterative Binary Exponent   | O(log n)        | O(1)             |

Iterative binary exponentiation is **optimal** — log time, constant space 🚀

---

# ⭐ Key Concepts Learned

* **Binary Exponentiation** (Fast Power) — fundamental algorithm
* Processing exponents using their **binary representation**
* Handling negative exponents by inverting the base
* `INT_MIN` overflow edge case with `long long`
* Reducing O(n) to O(log n) through repeated squaring

---

# 🏆 Why This Problem Is Important

* Teaches **binary exponentiation** — used in cryptography (RSA), competitive programming
* Foundation for modular exponentiation (`x^n mod m`)
* Tests understanding of bitwise operations and math optimization
* Edge case handling (negative n, INT_MIN, x = 0)
* Commonly asked at Google, Amazon, Microsoft, Facebook
