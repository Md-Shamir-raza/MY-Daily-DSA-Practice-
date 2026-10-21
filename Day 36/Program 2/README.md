# Generate Parentheses (LeetCode #22)

## 📝 Problem Description
Given `n` pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

**Example 1:**
- **Input:** n = 3
- **Output:** ["((()))","(()())","(())()","()(())","()()()"]

**Example 2:**
- **Input:** n = 1
- **Output:** ["()"]

## 💡 Solution Approach
We use **Backtracking** to generate all valid combinations. At each step, we have two choices:
1. **Add an opening parenthesis `(`** — allowed only if we've used fewer than `n` open parentheses.
2. **Add a closing parenthesis `)`** — allowed only if the count of closing parentheses is less than the count of opening ones (to ensure validity).

By only making valid choices at each step, we prune the search space and avoid generating any invalid combinations. The recursion naturally generates all valid permutations.

This is a classic example of how backtracking can efficiently enumerate structured combinatorial objects.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(4^n / √n) — this is the n-th Catalan number, which bounds the number of valid parentheses combinations.
- **Space Complexity:** O(N) for the recursion stack depth (at most 2n levels deep), plus O(4^n / √n) to store all the results.
