# Climbing Stairs (LeetCode #70)

## 📝 Problem Description
You are climbing a staircase. It takes `n` steps to reach the top.
Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?

**Example 1:**
- **Input:** n = 2
- **Output:** 2
- **Explanation:** There are two ways to climb to the top.
  1. 1 step + 1 step
  2. 2 steps

**Example 2:**
- **Input:** n = 3
- **Output:** 3
- **Explanation:** There are three ways to climb to the top.
  1. 1 step + 1 step + 1 step
  2. 1 step + 2 steps
  3. 2 steps + 1 step

## 💡 Solution Approach
This problem can be reduced to the Fibonacci sequence. To reach the `n`th step, you must have come from either the `n-1`th step (taking 1 step) or the `n-2`th step (taking 2 steps). Thus, `ways(n) = ways(n-1) + ways(n-2)`. We can solve this optimally using Dynamic Programming with space optimization. Instead of storing an entire DP array, we only need to keep track of the results for the previous two steps.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(N) where N is the number of steps. We iterate from 3 to N.
- **Space Complexity:** O(1) since we only use a few integer variables (`prev1`, `prev2`) to store intermediate results, rather than an O(N) array.
