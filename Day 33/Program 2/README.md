# Surrounded Regions (LeetCode #130)

## 📝 Problem Description
Given an `m x n` matrix `board` containing `'X'` and `'O'`, capture all regions that are 4-directionally surrounded by `'X'`.
A region is captured by flipping all `'O'`s into `'X'`s in that surrounded region. An `'O'` on the border of the board cannot be surrounded, and any `'O'` connected to a border `'O'` should not be flipped either.

**Example 1:**
- **Input:** board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
- **Output:** [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
- **Explanation:** The bottom `'O'` is on the border, so it is not flipped. The other `'O'`s form a surrounded region, so they are all flipped.

## 💡 Solution Approach
Instead of trying to find surrounded regions directly, we reverse the problem:
1. **Find all safe 'O' cells:** Start DFS from every `'O'` on the border. Mark all connected `'O'` cells as `'S'` (safe), since they cannot be surrounded.
2. **Capture and restore:** Iterate through the entire board. Any remaining `'O'` is truly surrounded, so flip it to `'X'`. Any `'S'` is a safe border-connected cell, so restore it to `'O'`.

This approach elegantly avoids complex region detection logic.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(m × n) since we visit each cell at most a constant number of times.
- **Space Complexity:** O(m × n) in the worst case for the DFS recursion stack (e.g., when the entire board is `'O'`).
