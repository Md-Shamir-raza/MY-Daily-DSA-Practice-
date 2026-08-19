
# 🪙 Coin Change – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #322 – Medium)

You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return the **fewest number of coins** that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return `-1`.

You may assume that you have an infinite number of each kind of coin.

Example:

```
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
```

More examples:

```
Input: coins = [2], amount = 3
Output: -1

Input: coins = [1], amount = 0
Output: 0
```

---

# 🧠 Approach: Dynamic Programming (Bottom-Up)

The key insight is:

> We can break down the problem into smaller subproblems. To find the minimum coins for amount `i`, we can try subtracting each coin denomination from `i`.
> For example, if we want to make amount 11 and we have a coin 5, the problem reduces to finding the minimum coins for amount 6, and adding 1 (the coin 5 itself).
> `dp[i] = min(dp[i], dp[i - coin] + 1)`

### Why Dynamic Programming?
A greedy approach (always picking the largest coin) doesn't work for all coin sets. For example, if `coins = [1, 3, 4]` and `amount = 6`, a greedy approach would pick `4 + 1 + 1` (3 coins), but the optimal solution is `3 + 3` (2 coins). DP guarantees the optimal answer by evaluating all possibilities optimally.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 Initialize the DP Array

```cpp
vector<int> dp(amount + 1, amount + 1);
```
* Create a `vector` named `dp` of size `amount + 1`. This allows us to access indices from `0` to `amount` directly.
* We initialize every element with `amount + 1`. Since the maximum possible number of coins we could ever use is `amount` (if we only used coins of value 1), `amount + 1` acts as a placeholder for "infinity" or "impossible". (We can't use `INT_MAX` because adding 1 to it later would cause an integer overflow).

---

### 🔹 Base Case

```cpp
dp[0] = 0;
```
* The number of coins needed to make amount 0 is exactly 0. This is the foundation our DP builds upon.

---

### 🔹 Outer Loop (Building Up Amounts)

```cpp
for (int i = 1; i <= amount; i++) {
```
* We iterate from `1` up to the target `amount`. We solve the problem for every smaller amount before trying to solve for larger amounts.

---

### 🔹 Inner Loop (Trying Every Coin)

```cpp
for (int coin : coins) {
    if (coin <= i) {
        dp[i] = min(dp[i], dp[i - coin] + 1);
    }
}
```
* For the current amount `i`, we test every available `coin`.
* `if (coin <= i)`: We can only use this coin if its value is less than or equal to the target amount `i`.
* `dp[i - coin] + 1`: This is the crucial DP transition. It means: "Take the minimum coins needed for the remaining amount (`i - coin`), and add `1` because we are using this current coin".
* We take the minimum between our current best answer for `dp[i]` and this new calculated answer.

---

### 🔹 Return the Result

```cpp
return dp[amount] > amount ? -1 : dp[amount];
```
* After filling the `dp` array, our answer should be at `dp[amount]`.
* If `dp[amount]` is still greater than `amount` (i.e., it remained at our "infinity" value of `amount + 1`), it means we never found a valid combination of coins to make the amount. So, return `-1`.
* Otherwise, return the value stored in `dp[amount]`.

---

# 📊 Step-by-Step Example

Input: `coins = [1,2,5]`, `amount = 5`

**Initialization:**
`dp` size 6. Filled with 6 ("infinity").
`dp[0] = 0`.
`dp = [0, 6, 6, 6, 6, 6]`

**i = 1:**
- coin 1: `dp[1] = min(6, dp[0] + 1) = 1`
- coin 2: 2 > 1, skip.
- coin 5: 5 > 1, skip.
`dp = [0, 1, 6, 6, 6, 6]`

**i = 2:**
- coin 1: `dp[2] = min(6, dp[1] + 1) = 2`
- coin 2: `dp[2] = min(2, dp[0] + 1) = 1`
- coin 5: skip.
`dp = [0, 1, 1, 6, 6, 6]`

**i = 3:**
- coin 1: `dp[3] = min(6, dp[2] + 1) = 2`
- coin 2: `dp[3] = min(2, dp[1] + 1) = 2`
- coin 5: skip.
`dp = [0, 1, 1, 2, 6, 6]`

**i = 4:**
- coin 1: `dp[4] = min(6, dp[3] + 1) = 3`
- coin 2: `dp[4] = min(3, dp[2] + 1) = 2`
- coin 5: skip.
`dp = [0, 1, 1, 2, 2, 6]`

**i = 5:**
- coin 1: `dp[5] = min(6, dp[4] + 1) = 3`
- coin 2: `dp[5] = min(3, dp[3] + 1) = 3`
- coin 5: `dp[5] = min(3, dp[0] + 1) = 1`
`dp = [0, 1, 1, 2, 2, 1]`

✅ Result at `dp[5]` is **1**. (Just use one coin of 5).

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(S * N)**
* Where `S` is the `amount` and `N` is the number of `coins`.
* The nested loops run `S` times outer and `N` times inner.

---

### 🔹 Space Complexity: **O(S)**
* We use a single 1D array of size `amount + 1` to store our DP states.

---

# ⭐ Key Concepts Learned
* **Bottom-Up Dynamic Programming (Tabulation)**: Solving small problems first and using their answers to solve bigger problems.
* **Knapsack Variant**: This is related to the Unbounded Knapsack problem, where items can be reused infinitely.
* **Initialization Trick**: Using `amount + 1` as infinity to avoid integer overflow errors that happen with `INT_MAX`.

---

# 🏆 Why This Problem Is Important
* It is a quintessential introductory DP problem.
* It teaches you why greedy algorithms fail in certain scenarios and how DP acts as the correct alternative.
* Very frequently asked in interviews.
