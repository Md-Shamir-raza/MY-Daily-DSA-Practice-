# Pacific Atlantic Water Flow (LeetCode #417)

## 📝 Problem Description
There is an `m x n` rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
The island is partitioned into a grid of square cells. You are given an `m x n` integer matrix `heights` where `heights[r][c]` represents the height above sea level of the cell at coordinate `(r, c)`.
Rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is **less than or equal to** the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.
Return a 2D list of grid coordinates `result` where `result[i] = [ri, ci]` denotes that rain water can flow from cell `(ri, ci)` to both the Pacific and Atlantic oceans.

**Example 1:**
- **Input:** heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
- **Output:** [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

## 💡 Solution Approach
Instead of checking every cell to see if water can flow to both oceans (expensive), we **reverse the problem**. We start from the ocean borders and perform a BFS/DFS *uphill* (to cells with height ≥ current). We do this separately for the Pacific and Atlantic oceans, marking which cells are reachable from each. The answer is all cells that are reachable from **both** oceans.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(m × n) since each cell is visited at most twice (once per ocean BFS).
- **Space Complexity:** O(m × n) for the two visited matrices and the BFS queue.
