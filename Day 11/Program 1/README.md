
# 🔄 Permutations – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #46 – Medium)

Given an array `nums` of **distinct** integers, return all the possible **permutations**. You can return the answer in **any order**.

A permutation is a rearrangement of all the elements in the array.

Example:

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

More examples:

```
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Input: nums = [1]
Output: [[1]]
```

---

# 🧠 Approach: Backtracking

The key insight is:

> We can systematically build permutations element by element. At each step, we have choices of which number to pick next. We explore all choices, and then "backtrack" to explore other paths.

### The Backtracking Template:
Backtracking problems generally follow this structure:
1. **Choose**: Pick an element and add it to our current state.
2. **Explore**: Recursively call the function to continue building.
3. **Un-choose (Backtrack)**: Remove the element we just added to try the next option.

For permutations, we also need to keep track of which numbers are already in our `current` sequence so we don't pick them again. We use a boolean `used` array for this.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        
        backtrack(nums, current, used, result);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            
            current.push_back(nums[i]);
            used[i] = true;
            
            backtrack(nums, current, used, result);
            
            current.pop_back();
            used[i] = false;
        }
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 Initialization in `permute`

```cpp
vector<vector<int>> result;
vector<int> current;
vector<bool> used(nums.size(), false);
```
* `result`: Stores the final list of all valid permutations.
* `current`: Tracks the permutation we are currently building (e.g., `[1, 2]`).
* `used`: A boolean array. `used[i] == true` means `nums[i]` is already inside `current`.

---

### 🔹 Base Case (Stop Condition)

```cpp
if (current.size() == nums.size()) {
    result.push_back(current);
    return;
}
```
* A permutation is complete when its length matches the original array length.
* When this happens, we add a copy of `current` to `result` and `return` (stop going deeper on this path).

---

### 🔹 Iterate Over Choices

```cpp
for (int i = 0; i < nums.size(); i++) {
    if (used[i]) continue;
```
* At every step, we try to add *every* number in the original array.
* But wait! We can't reuse numbers. `if (used[i]) continue;` skips numbers that are already in `current`.

---

### 🔹 1. Choose

```cpp
current.push_back(nums[i]);
used[i] = true;
```
* We add `nums[i]` to our `current` sequence.
* We mark it as `used` so deeper recursive calls won't pick it again.

---

### 🔹 2. Explore

```cpp
backtrack(nums, current, used, result);
```
* We make a recursive call to continue building the permutation from this new state.

---

### 🔹 3. Un-choose (Backtrack)

```cpp
current.pop_back();
used[i] = false;
```
* Once the recursive call returns (meaning all permutations starting with this `current` sequence have been found), we need to **undo our choice**.
* We remove `nums[i]` from `current` and mark it as `unused`.
* This allows the `for` loop to continue to the next `i` and try a different starting path.

---

# 📊 Step-by-Step Example (Decision Tree)

Input: `nums = [1, 2, 3]`

```
Level 0: []
|
|-- Choose 1: [1] (used=[T,F,F])
|   |
|   |-- Choose 2: [1,2] (used=[T,T,F])
|   |   |-- Choose 3: [1,2,3] (used=[T,T,T]) -> BASE CASE! Add to result.
|   |       Backtrack -> [1,2] -> Backtrack -> [1]
|   |
|   |-- Choose 3: [1,3] (used=[T,F,T])
|       |-- Choose 2: [1,3,2] (used=[T,T,T]) -> BASE CASE! Add to result.
|           Backtrack -> [1,3] -> Backtrack -> [1] -> Backtrack -> []
|
|-- Choose 2: [2]
|   |-- ... generates [2,1,3] and [2,3,1]
|
|-- Choose 3: [3]
    |-- ... generates [3,1,2] and [3,2,1]
```

✅ Final Answer = `[[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]`

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(N × N!)**
* There are `N!` (N factorial) permutations.
* Generating each permutation takes O(N) time (copying `current` to `result` at the base case).
* So overall time complexity is O(N × N!).

---

### 🔹 Space Complexity: **O(N)**
* The recursion depth goes up to `N` (call stack).
* The `current` and `used` arrays take `O(N)` space.
* (Excluding the space required to hold the `result` output, which is O(N × N!)).

---

# ⭐ Key Concepts Learned
* **Backtracking Paradigm**: The core structural template (Choose, Explore, Un-choose).
* **State Management**: Using a `used` boolean array to keep track of which items are available.
* **Decision Trees**: Visualizing recursion as a tree of choices.

---

# 🏆 Why This Problem Is Important
* It is the "Hello World" of backtracking problems.
* Understanding this is crucial for solving harder combinatorial problems (Combinations, Subsets, N-Queens, Sudoku Solver).
* Extremely common interview problem at all major tech companies.
