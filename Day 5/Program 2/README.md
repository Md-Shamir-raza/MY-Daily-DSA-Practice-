
# 🔄 Rotate Image – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #48 – Medium)

You are given an `n × n` 2D matrix representing an image. Rotate the image by **90 degrees clockwise**.

You have to rotate it **in-place**, which means you have to modify the input matrix directly. **Do NOT** allocate another 2D matrix.

Example:

```
Input:                  Output:
[1, 2, 3]              [7, 4, 1]
[4, 5, 6]     →        [8, 5, 2]
[7, 8, 9]              [9, 6, 3]
```

More examples:

```
Input:                          Output:
[ 5,  1,  9, 11]               [15, 13,  2,  5]
[ 2,  4,  8, 10]       →       [14,  3,  4,  1]
[13,  3,  6,  7]               [12,  6,  8,  9]
[15, 14, 12, 16]               [16,  7, 10, 11]
```

---

# 🧠 Approach: Transpose + Reverse

The key insight is:

> A 90° clockwise rotation = **Transpose** the matrix + **Reverse each row**.

### What is Transpose?

Swapping rows and columns: `matrix[i][j]` ↔ `matrix[j][i]`

```
Original:       Transposed:
[1, 2, 3]       [1, 4, 7]
[4, 5, 6]   →   [2, 5, 8]
[7, 8, 9]       [3, 6, 9]
```

### Then Reverse Each Row:

```
Transposed:     Reversed:
[1, 4, 7]      [7, 4, 1]
[2, 5, 8]  →   [8, 5, 2]
[3, 6, 9]      [9, 6, 3]
```

✅ This gives us the 90° clockwise rotation!

### Why does this work?

Mathematically, for a 90° clockwise rotation:
```
new_position[j][n-1-i] = old_position[i][j]
```

This is equivalent to:
1. Transpose: `(i, j) → (j, i)`
2. Reverse row: `(j, i) → (j, n-1-i)`

Combined: `(i, j) → (j, n-1-i)` ✅

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 `int n = matrix.size();`

* Get the dimension of the matrix.
* Since it's `n × n`, we only need one variable.

---

### 🔹 Step 1: Transpose

```cpp
for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
}
```

#### What happens:

* We swap `matrix[i][j]` with `matrix[j][i]` — turning rows into columns.
* **Important**: `j` starts from `i + 1` (not 0).

#### Why `j = i + 1`?

* If we swap `(i,j)` and `(j,i)`, and later also swap `(j,i)` and `(i,j)`, we'd undo the first swap!
* By only processing the **upper triangle** (where `j > i`), each pair is swapped exactly once.
* The diagonal (`i == j`) doesn't need swapping.

#### Example:

```
Before:         After Transpose:
[1, 2, 3]      [1, 4, 7]
[4, 5, 6]  →   [2, 5, 8]
[7, 8, 9]      [3, 6, 9]

Swaps: (0,1)↔(1,0), (0,2)↔(2,0), (1,2)↔(2,1)
       2↔4,         3↔7,          6↔8
```

---

### 🔹 Step 2: Reverse Each Row

```cpp
for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
}
```

#### What happens:

* For each row, reverse the order of elements.
* `reverse()` is a built-in STL function that reverses in-place.

#### Example:

```
Before:         After Reverse:
[1, 4, 7]      [7, 4, 1]
[2, 5, 8]  →   [8, 5, 2]
[3, 6, 9]      [9, 6, 3]
```

✅ This is the 90° clockwise rotation!

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

### Step 1: Transpose

| Swap | Elements | Before → After |
| ---- | -------- | -------------- |
| (0,1) ↔ (1,0) | 2 ↔ 4 | matrix[0][1]=4, matrix[1][0]=2 |
| (0,2) ↔ (2,0) | 3 ↔ 7 | matrix[0][2]=7, matrix[2][0]=3 |
| (1,2) ↔ (2,1) | 6 ↔ 8 | matrix[1][2]=8, matrix[2][1]=6 |

After transpose:
```
[1, 4, 7]
[2, 5, 8]
[3, 6, 9]
```

### Step 2: Reverse Each Row

| Row | Before | After |
| --- | ------ | ----- |
| 0   | [1, 4, 7] | [7, 4, 1] |
| 1   | [2, 5, 8] | [8, 5, 2] |
| 2   | [3, 6, 9] | [9, 6, 3] |

✅ Final Result:
```
[7, 4, 1]
[8, 5, 2]
[9, 6, 3]
```

---

# 🎯 Other Rotation Directions

This transpose + reverse technique can achieve all rotations:

| Rotation | Method |
| -------- | ------ |
| 90° Clockwise | Transpose → Reverse rows |
| 90° Counter-clockwise | Transpose → Reverse columns |
| 180° | Reverse rows → Reverse columns |

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(n²)**

* Transpose: Visit each element in the upper triangle → `O(n²/2)`.
* Reverse rows: Reverse `n` rows of length `n` → `O(n²/2)`.
* Total: **O(n²)** — which is optimal since we must touch every element.

---

### 🔹 Space Complexity: **O(1)**

* All operations are done **in-place**.
* Only a constant number of variables used for swapping.
* No extra matrix allocated.

---

# ⚔️ Comparison With Other Approaches

| Approach                      | Time Complexity | Space Complexity |
| ----------------------------- | --------------- | ---------------- |
| New Matrix (Copy)             | O(n²)           | O(n²)            |
| Layer-by-Layer Rotation       | O(n²)           | O(1)             |
| Transpose + Reverse (Optimal) | O(n²)           | O(1)             |

Transpose + Reverse is the cleanest and most intuitive O(1) space solution 🚀

---

# ⭐ Key Concepts Learned

* **Matrix transpose** — fundamental operation in linear algebra
* In-place matrix manipulation without extra space
* Breaking a complex operation into two simple steps
* Understanding why `j = i + 1` prevents double-swapping
* STL `swap()` and `reverse()` functions

---

# 🏆 Why This Problem Is Important

* Classic **matrix manipulation** problem in interviews
* Tests spatial reasoning and in-place transformation skills
* Foundation for understanding image processing algorithms
* Teaches decomposition — breaking complex operations into simpler ones
* Commonly asked at Amazon, Google, Microsoft, Apple, Goldman Sachs
