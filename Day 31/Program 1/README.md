# Unique Paths (LeetCode #62)

## 📝 Problem Description
There is a robot on an `m x n` grid. The robot is initially located at the top-left corner (i.e., `grid[0][0]`). The robot tries to move to the bottom-right corner (i.e., `grid[m - 1][n - 1]`). The robot can only move either **down** or **right** at any point in time.
Given the two integers `m` and `n`, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

**Example 1:**
- **Input:** m = 3, n = 7
- **Output:** 28

**Example 2:**
- **Input:** m = 3, n = 2
- **Output:** 3
- **Explanation:** From the top-left corner, there are 3 ways to reach the bottom-right corner: Right → Down → Down, Down → Down → Right, Down → Right → Down.

## 💡 Solution Approach
This is a classic **2D Dynamic Programming** problem. The number of paths to reach cell `(i, j)` is the sum of paths to `(i-1, j)` (came from above) and `(i, j-1)` (came from left). The first row and first column always have only 1 path each. We optimize space from O(m*n) to O(n) by using a single 1D array, since we only need the previous row's data which we update in-place.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(m × n) as we iterate through each cell in the grid exactly once.
- **Space Complexity:** O(n) using the space-optimized 1D DP array.
