# Counting Bits (LeetCode #338)

## 📝 Problem Description
Given an integer `n`, return an array `ans` of length `n + 1` such that for each `i` (`0 <= i <= n`), `ans[i]` is the **number of 1's** in the binary representation of `i`.

**Example 1:**
- **Input:** n = 2
- **Output:** [0, 1, 1]
- **Explanation:** 0 → 0, 1 → 1, 2 → 10

**Example 2:**
- **Input:** n = 5
- **Output:** [0, 1, 1, 2, 1, 2]
- **Explanation:** 0→0, 1→1, 2→10, 3→11, 4→100, 5→101

## 💡 Solution Approach
We use a clever **Dynamic Programming + Bit Manipulation** approach. The key recurrence is:
`countBits(i) = countBits(i >> 1) + (i & 1)`
- `i >> 1` is `i` right-shifted by 1 (equivalent to `i / 2`), which we've already computed.
- `i & 1` checks if the last bit is a `1`.

This lets us build up the answer array iteratively, reusing previously computed values.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(N) — a single pass from 1 to N, each step is O(1).
- **Space Complexity:** O(N) for the output array (which is required by the problem).
