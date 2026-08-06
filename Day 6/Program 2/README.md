
# 🌀 Spiral Matrix – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #54 – Medium)

Given an `m × n` matrix, return all elements of the matrix in **spiral order**.

Example:

```
Input:                  Output:
[1, 2, 3]
[4, 5, 6]      →       [1, 2, 3, 6, 9, 8, 7, 4, 5]
[7, 8, 9]
```

More examples:

```
Input:                          Output:
[ 1,  2,  3,  4]
[ 5,  6,  7,  8]       →       [1,2,3,4,8,12,11,10,9,5,6,7]
[ 9, 10, 11, 12]
```

---

# 🧠 Approach: Layer-by-Layer with Four Boundaries

The key insight is:

> Traverse the matrix in a spiral by maintaining four boundaries: `top`, `bottom`, `left`, `right`. Peel off one layer at a time, shrinking boundaries inward after each traversal direction.

### Four directions per layer:

```
1. → Right (along top row)
2. ↓ Down  (along right column)
3. ← Left  (along bottom row)
4. ↑ Up    (along left column)
```

After each direction, shrink the corresponding boundary.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // Traverse RIGHT
            for (int col = left; col <= right; col++)
                result.push_back(matrix[top][col]);
            top++;

            // Traverse DOWN
            for (int row = top; row <= bottom; row++)
                result.push_back(matrix[row][right]);
            right--;

            // Traverse LEFT (if rows remain)
            if (top <= bottom) {
                for (int col = right; col >= left; col--)
                    result.push_back(matrix[bottom][col]);
                bottom--;
            }

            // Traverse UP (if columns remain)
            if (left <= right) {
                for (int row = bottom; row >= top; row--)
                    result.push_back(matrix[row][left]);
                left++;
            }
        }

        return result;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 Four Boundary Variables

```cpp
int top = 0;
int bottom = matrix.size() - 1;
int left = 0;
int right = matrix[0].size() - 1;
```

* `top` → The topmost unvisited row.
* `bottom` → The bottommost unvisited row.
* `left` → The leftmost unvisited column.
* `right` → The rightmost unvisited column.

Initial state for a 3×4 matrix:
```
top=0 → [ 1,  2,  3,  4] ← right=3
         [ 5,  6,  7,  8]
left=0→  [ 9, 10, 11, 12] ← bottom=2
```

---

### 🔹 `while (top <= bottom && left <= right)`

* Continue as long as there are unvisited rows **and** columns.
* When boundaries cross, all elements have been visited.

---

### 🔹 Step 1: Traverse RIGHT →

```cpp
for (int col = left; col <= right; col++) {
    result.push_back(matrix[top][col]);
}
top++;
```

* Traverse the entire **top row** from left to right.
* Then move `top` down — that row is now fully visited.

```
[1, 2, 3] ← collect this row
[4, 5, 6]
[7, 8, 9]
top moves from 0 → 1
```

---

### 🔹 Step 2: Traverse DOWN ↓

```cpp
for (int row = top; row <= bottom; row++) {
    result.push_back(matrix[row][right]);
}
right--;
```

* Traverse the entire **right column** from top to bottom.
* Then move `right` left — that column is now fully visited.

```
[_, _, _]
[_, _, 6] ← collect this column
[_, _, 9]
right moves from 2 → 1
```

---

### 🔹 Step 3: Traverse LEFT ← (with guard)

```cpp
if (top <= bottom) {
    for (int col = right; col >= left; col--) {
        result.push_back(matrix[bottom][col]);
    }
    bottom--;
}
```

* Traverse the **bottom row** from right to left.
* The `if (top <= bottom)` check prevents re-traversing when only one row remains.
* Move `bottom` up after traversal.

```
[_, _, _]
[_, _, _]
[7, 8, _] ← collect this row (right to left)
bottom moves from 2 → 1
```

---

### 🔹 Step 4: Traverse UP ↑ (with guard)

```cpp
if (left <= right) {
    for (int row = bottom; row >= top; row--) {
        result.push_back(matrix[row][left]);
    }
    left++;
}
```

* Traverse the **left column** from bottom to top.
* The `if (left <= right)` check prevents re-traversing when only one column remains.
* Move `left` right after traversal.

```
[_, _, _]
[4, _, _] ← collect this column (bottom to top)
[_, _, _]
left moves from 0 → 1
```

---

### 🔹 Why Are the Guards Needed?

Without `if (top <= bottom)` and `if (left <= right)`, we'd double-count elements for non-square matrices.

Example with a single row `[[1, 2, 3]]`:
- After traversing RIGHT: `[1, 2, 3]`, top becomes 1
- After traversing DOWN: nothing (top > bottom)
- Without guard: LEFT traversal would run on the same row again!
- With guard: `top (1) <= bottom (0)` is **false** → skip ✅

---

# 📊 Step-by-Step Example

Input:

```
matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]
```

### Layer 1 (outer ring):

| Direction | Boundaries | Elements | result |
| --------- | ---------- | -------- | ------ |
| → Right   | top=0, left=0→right=2 | 1, 2, 3 | [1,2,3] |
| ↓ Down    | right=2, top=1→bottom=2 | 6, 9 | [1,2,3,6,9] |
| ← Left   | bottom=2, right=1→left=0 | 8, 7 | [1,2,3,6,9,8,7] |
| ↑ Up      | left=0, bottom=1→top=1 | 4 | [1,2,3,6,9,8,7,4] |

Boundaries now: top=1, bottom=1, left=1, right=1

### Layer 2 (center):

| Direction | Boundaries | Elements | result |
| --------- | ---------- | -------- | ------ |
| → Right   | top=1, col=1→1 | 5 | [1,2,3,6,9,8,7,4,5] |

Boundaries now: top=2, bottom=1 → `top > bottom` → STOP

✅ Final Answer = **[1, 2, 3, 6, 9, 8, 7, 4, 5]**

---

# 🎯 Visual Spiral Path

```
[1 → 2 → 3]
            ↓
[4 → 5]  [6]
 ↑        ↓
[7 ← 8 ← 9]

Path: 1 → 2 → 3 → 6 → 9 → 8 → 7 → 4 → 5
```

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(m × n)**

* Every element is visited exactly once.
* `m` = number of rows, `n` = number of columns.

---

### 🔹 Space Complexity: **O(1)** (excluding output)

* Only four boundary variables used.
* The result array is the required output, not extra space.

---

# ⚔️ Comparison With Other Approaches

| Approach                    | Time Complexity | Space Complexity |
| --------------------------- | --------------- | ---------------- |
| Simulation with Visited Set | O(m × n)        | O(m × n)         |
| Direction Vectors           | O(m × n)        | O(m × n)         |
| Boundary Shrinking (Optimal)| O(m × n)        | O(1)             |

Boundary shrinking is the **cleanest** and most space-efficient approach 🚀

---

# ⭐ Key Concepts Learned

* **Boundary pointer** technique for matrix traversal
* Layer-by-layer peeling of a matrix
* Guard conditions to prevent duplicate traversal
* Handling rectangular (non-square) matrices
* Direction-based traversal patterns: RIGHT → DOWN → LEFT → UP

---

# 🏆 Why This Problem Is Important

* Classic **matrix traversal** problem in interviews
* Tests loop control, boundary management, and edge cases
* Foundation for Spiral Matrix II (generating spiral matrices)
* Real-world applications: image processing, printing patterns
* Commonly asked at Amazon, Google, Microsoft, Apple, Goldman Sachs
