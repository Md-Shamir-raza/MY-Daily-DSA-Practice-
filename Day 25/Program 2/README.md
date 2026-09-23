# Word Search (LeetCode #79)

## 📝 Problem Description
Given an `m x n` grid of characters `board` and a string `word`, return `true` if `word` exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

**Example 1:**
- **Input:** board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
- **Output:** true

**Example 2:**
- **Input:** board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
- **Output:** true

## 💡 Solution Approach
We can use Backtracking with Depth-First Search (DFS). We iterate through every cell in the grid. If the cell's character matches the first character of the word, we start a DFS from that cell. In the DFS, we check all four directions (up, down, left, right) for the next character. To ensure we don't reuse a cell, we temporarily mark it with a special character (e.g., `#`) and backtrack by restoring the original character after the DFS returns.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(M * N * 4^L) where M is rows, N is columns, and L is the length of the word. In the worst case, from each cell we might explore 4 directions up to length L.
- **Space Complexity:** O(L) due to the call stack during the DFS recursion, where L is the length of the word.
