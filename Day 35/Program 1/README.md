# Minimum Window Substring (LeetCode #76)

## 📝 Problem Description
Given two strings `s` and `t` of lengths `m` and `n` respectively, return the **minimum window substring** of `s` such that every character in `t` (including duplicates) is included in the window. If there is no such substring, return the empty string `""`.

**Example 1:**
- **Input:** s = "ADOBECODEBANC", t = "ABC"
- **Output:** "BANC"
- **Explanation:** The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

**Example 2:**
- **Input:** s = "a", t = "a"
- **Output:** "a"

**Example 3:**
- **Input:** s = "a", t = "aa"
- **Output:** ""
- **Explanation:** Both 'a's from t must be included in the window. Since the string only has one 'a', return empty string.

## 💡 Solution Approach
We use the **Sliding Window** technique with two pointers (`left` and `right`) and two hash maps:
1. `tFreq` stores the frequency of each character in `t`.
2. `windowFreq` tracks the frequency of characters in the current window.
3. We track `formed` — the count of unique characters whose frequency in the window matches `t`'s requirement.
4. **Expand** the window by moving `right`. When all characters are satisfied (`formed == required`), **contract** from `left` to find the smallest valid window.

This is one of the most important **Hard** sliding window problems for interviews.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(|s| + |t|) — each character in `s` is visited at most twice (once by `right`, once by `left`).
- **Space Complexity:** O(|s| + |t|) in the worst case for the hash maps.
