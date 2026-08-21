
# 🏝️ Number of Islands – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #200 – Medium)

Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return the number of islands.

An **island** is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

```
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
```

---

# 🧠 Approach: Depth-First Search (DFS)

The key insight is:

> We can think of the grid as a graph where each `'1'` is a node, and edges exist between adjacent `'1'`s.
> Finding the number of islands is equivalent to finding the number of **connected components** in the graph.
> We scan the grid. Whenever we find a `'1'`, it means we found a new island. We then use DFS to explore that entire island and "sink" it (change all its `'1'`s to `'0'`s) so we don't count it again later.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int numIslands = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    dfs(grid, i, j);
                }
            }
        }
        return numIslands;
    }

private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0';

        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 Initialization and Edge Cases

```cpp
if (grid.empty() || grid[0].empty()) return 0;
int numIslands = 0;
```
* Handle edge case: if the grid is empty, there are 0 islands.
* Initialize our counter.

---

### 🔹 Scanning the Grid

```cpp
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        if (grid[i][j] == '1') {
            numIslands++;
            dfs(grid, i, j);
        }
    }
}
```
* Iterate through every single cell in the grid.
* When we hit a `'1'`, it means we've stumbled upon land that hasn't been explored yet.
* We increment `numIslands`.
* We immediately call `dfs(grid, i, j)` to explore and "sink" this entire contiguous landmass. By sinking it, we ensure that as the nested loops continue, we won't double-count parts of the same island.

---

### 🔹 The DFS Function (Sinking the Island)

```cpp
void dfs(vector<vector<char>>& grid, int r, int c) {
```
* This helper function takes the grid (by reference, so changes apply globally) and current coordinates `(r, c)`.

---

### 🔹 DFS Base Case (Out of Bounds / Water)

```cpp
if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') {
    return;
}
```
* The recursion stops if:
  1. We go off the top or bottom edges (`r < 0 || r >= rows`).
  2. We go off the left or right edges (`c < 0 || c >= cols`).
  3. The current cell is already water `'0'`.

---

### 🔹 Mark as Visited

```cpp
grid[r][c] = '0';
```
* "Sink" the current piece of land. This serves as our "visited" tracker, saving us from needing an extra `visited[m][n]` boolean array, thus optimizing space!

---

### 🔹 Explore Neighbors

```cpp
dfs(grid, r - 1, c); // up
dfs(grid, r + 1, c); // down
dfs(grid, r, c - 1); // left
dfs(grid, r, c + 1); // right
```
* Recursively attempt to step in all 4 cardinal directions. If there is more land connected to this piece, the DFS will naturally follow it and sink it too.

---

# 📊 Step-by-Step Example

Grid:
```
1 1 0
0 1 0
0 0 1
```

1. Outer loops hit `(0, 0)` -> It's `'1'`.
   - `numIslands++` (now 1).
   - Call `dfs(0, 0)`.
     - Sink `(0, 0)`. Grid becomes `0 1 0 ...`
     - DFS Right to `(0, 1)`. Sink it. Grid becomes `0 0 0 ...`
     - DFS Down from `(0,1)` to `(1, 1)`. Sink it. Grid becomes `... 0 0 0 ...`
   - DFS finishes. The whole connected blob is now `'0'`.

2. Outer loops continue. They skip `(0,1)`, `(0,2)`, `(1,0)`, `(1,1)`, `(1,2)` because they are all `'0'`.

3. Outer loops hit `(2, 2)` -> It's `'1'`.
   - `numIslands++` (now 2).
   - Call `dfs(2, 2)`. Sink it.
   - DFS finishes.

✅ Returns **2**.

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(M × N)**
* `M` is rows, `N` is columns.
* We visit every cell in the grid via the nested loops.
* During the DFS, a cell is visited at most 4 times (once from each neighbor) before returning immediately (since it was turned to `'0'`). Thus, total time is linear with respect to the number of cells.

---

### 🔹 Space Complexity: **O(M × N)**
* In the worst case (a grid entirely filled with land), the DFS call stack will go as deep as the number of cells in the grid, taking `O(M × N)` space.

---

# ⭐ Key Concepts Learned
* **Implicit Graph Traversal**: Treating a 2D matrix as a graph.
* **Connected Components**: Using DFS to find isolated clusters in a graph.
* **In-place State Modification**: Mutating the input grid (turning `'1'` to `'0'`) to track visited nodes, saving `O(M × N)` auxiliary space.

---

# 🏆 Why This Problem Is Important
* It is the quintessential 2D grid graph traversal problem.
* Mastering this pattern allows you to easily solve related problems like "Max Area of Island", "Surrounded Regions", and "Word Search".
