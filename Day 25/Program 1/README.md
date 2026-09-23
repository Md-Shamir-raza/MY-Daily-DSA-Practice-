# Set Matrix Zeroes (LeetCode #73)

## 📝 Problem Description
Given an `m x n` integer matrix `matrix`, if an element is `0`, set its entire row and column to `0`'s.
You must do it in place.

**Example 1:**
- **Input:** matrix = [[1,1,1],[1,0,1],[1,1,1]]
- **Output:** [[1,0,1],[0,0,0],[1,0,1]]

**Example 2:**
- **Input:** matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
- **Output:** [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

## 💡 Solution Approach
To achieve `O(1)` space complexity, we can use the first row and first column of the matrix itself to store the states of whether a row or column needs to be zeroed out. We first check if the first row and column contain any zeros and store that in boolean variables. Then, we iterate through the rest of the matrix. Whenever we find a `0`, we mark the corresponding cell in the first row and first column. Finally, we iterate again and set the cells to zero based on our marks, and handle the first row and column separately using the boolean variables.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(M * N) where M is the number of rows and N is the number of columns, because we iterate over the matrix a few times.
- **Space Complexity:** O(1) in-place modification, using only a couple of variables.
