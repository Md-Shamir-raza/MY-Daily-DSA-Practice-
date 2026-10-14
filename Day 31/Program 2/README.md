# Longest Common Subsequence (LeetCode #1143)

## 📝 Problem Description
Given two strings `text1` and `text2`, return the length of their **longest common subsequence**. If there is no common subsequence, return `0`.
A **subsequence** of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

**Example 1:**
- **Input:** text1 = "abcde", text2 = "ace"
- **Output:** 3
- **Explanation:** The longest common subsequence is "ace" and its length is 3.

**Example 2:**
- **Input:** text1 = "abc", text2 = "abc"
- **Output:** 3

**Example 3:**
- **Input:** text1 = "abc", text2 = "def"
- **Output:** 0
- **Explanation:** There is no such common subsequence, so the result is 0.

## 💡 Solution Approach
This is a textbook **2D Dynamic Programming** problem. We define `dp[i][j]` as the length of the LCS of `text1[0..i-1]` and `text2[0..j-1]`.
- If `text1[i-1] == text2[j-1]`, then `dp[i][j] = dp[i-1][j-1] + 1` (extend the LCS by this matching character).
- Otherwise, `dp[i][j] = max(dp[i-1][j], dp[i][j-1])` (take the best LCS from either excluding the current character of text1 or text2).
We optimize space to O(n) by using two 1D arrays (`prev` and `curr`) since each row only depends on the previous row.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(m × n) where m and n are the lengths of `text1` and `text2`.
- **Space Complexity:** O(n) with the space-optimized approach using two 1D arrays.
