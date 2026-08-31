
# 🍊 Rotting Oranges – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #994 – Medium)

You are given an `m x n` `grid` where each cell can have one of three values:
* `0` representing an empty cell,
* `1` representing a fresh orange, or
* `2` representing a rotten orange.

Every minute, any fresh orange that is **4-directionally adjacent** to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return `-1`.

Example:
```
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
```

---

# 🧠 Approach: Multi-source Breadth-First Search (BFS)

The key insight is:

> This problem is asking for the "shortest time" or "shortest path" for the rot to spread. Shortest path problems on unweighted grids are perfectly solved by **BFS**.
> However, unlike a standard BFS that starts from a single node, here we might have *multiple* rotten oranges starting to spread rot at the exact same time (minute 0).
> Therefore, we need a **Multi-source BFS**. We put *all* initially rotten oranges into the queue before we even begin the BFS loop.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) freshCount++;
            }
        }

        if (freshCount == 0) return 0;

        int minutes = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int levelSize = q.size();
            bool rotted = false;

            for (int i = 0; i < levelSize; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (const auto& dir : directions) {
                    int nr = r + dir.first, nc = c + dir.second;
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; 
                        freshCount--;
                        q.push({nr, nc});
                        rotted = true;
                    }
                }
            }
            if (rotted) minutes++;
        }

        return freshCount == 0 ? minutes : -1;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 Step 1: Scan the Grid

```cpp
queue<pair<int, int>> q;
int freshCount = 0;

for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        if (grid[i][j] == 2) q.push({i, j});
        else if (grid[i][j] == 1) freshCount++;
    }
}
```
* We must iterate through the entire grid once before doing anything.
* **Why?** We need to find *all* the sources of rot (`2`) and push their coordinates `(i, j)` into the queue immediately.
* We also count the total number of fresh oranges (`1`). This allows us to easily check at the end if any fresh oranges survived.

---

### 🔹 Edge Case Check

```cpp
if (freshCount == 0) return 0;
```
* If there were no fresh oranges to begin with, the time required is `0`.

---

### 🔹 BFS Setup

```cpp
int minutes = 0;
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
```
* `minutes` tracks our time.
* `directions` is a handy array to easily iterate over the 4 cardinal directions (Up, Down, Left, Right).

---

### 🔹 The Multi-source BFS Loop

```cpp
while (!q.empty()) {
    int levelSize = q.size();
    bool rotted = false;
```
* Just like in Level Order Tree Traversal, we use a `levelSize` variable. This ensures we process *all* oranges that rotted in the *current* minute before moving on to the next minute.
* `rotted` tracks if we actually managed to rot a new orange during this specific minute.

---

### 🔹 Rotting Neighbors

```cpp
    for (int i = 0; i < levelSize; i++) {
        // ... pop current rotting orange ...

        for (const auto& dir : directions) {
            int nr = r + dir.first, nc = c + dir.second;
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                grid[nr][nc] = 2; // Rot it!
                freshCount--;
                q.push({nr, nc});
                rotted = true;
            }
        }
    }
```
* For every rotting orange popped from the queue, we check its 4 neighbors.
* If a neighbor is within the grid boundaries AND is a fresh orange (`1`):
  - We turn it into a `2` (so it doesn't get double-counted by another rotting orange).
  - We decrement `freshCount`.
  - We push it into the queue. It will start rotting its neighbors in the *next* minute.
  - We mark `rotted = true`.

---

### 🔹 Increment Time & Check Result

```cpp
    if (rotted) minutes++;
}

return freshCount == 0 ? minutes : -1;
```
* After processing the whole level, if we rotted anything, 1 minute has passed. (If we didn't rot anything, it means the queue was just emptying out its last elements, so time doesn't increase).
* Finally, if `freshCount` reached `0`, all oranges are rotten. Return the `minutes`.
* If `freshCount > 0`, some fresh oranges were trapped behind empty cells (`0`) and could never be reached. Return `-1`.

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(M × N)**
* Where `M` is rows, `N` is columns.
* We scan the grid once to find the initial state.
* Then, in the BFS, every cell is pushed to the queue at most once. Checking 4 directions takes `O(1)`.
* Total time is strictly proportional to the number of cells in the grid.

### 🔹 Space Complexity: **O(M × N)**
* In the worst case (a grid full of rotten oranges), the queue will hold `M × N` elements.
