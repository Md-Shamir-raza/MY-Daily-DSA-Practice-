
# ➕ Combination Sum – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #39 – Medium)

Given an array of **distinct** integers `candidates` and a target integer `target`, return a list of all **unique combinations** of `candidates` where the chosen numbers sum to `target`. You may return the combinations in **any order**.

The **same** number may be chosen from `candidates` an **unlimited number of times**. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

Example:

```
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
```

More examples:

```
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Input: candidates = [2], target = 1
Output: []
```

---

# 🧠 Approach: Backtracking

The key insight is:

> We can build combinations element by element. To reach the `target`, we subtract the chosen number from a `remain` variable. Since we can reuse numbers, we don't move to the next index immediately. To avoid duplicates (like `[2,3]` and `[3,2]`), we enforce an ordering: once we move past an element, we can never look back at it.

### The Backtracking Logic:
1. **Target Met**: If `remain == 0`, we found a valid combination.
2. **Overshoot**: If `remain < 0`, we went too far; stop exploring this path.
3. **Explore Choices**: Loop through candidates starting from index `start`.
4. **Recursive Step**: Call backtrack, but pass `i` as the `start` index (so we can reuse the current element, but we can't go backward to `i-1`).

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& candidates, int remain, int start, vector<int>& current, vector<vector<int>>& result) {
        if (remain == 0) {
            result.push_back(current);
            return;
        }
        
        if (remain < 0) {
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            backtrack(candidates, remain - candidates[i], i, current, result);
            current.pop_back();
        }
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 Two Base Cases

```cpp
if (remain == 0) {
    result.push_back(current);
    return;
}
if (remain < 0) {
    return;
}
```
* **Success (`remain == 0`)**: The sum of numbers in `current` exactly matches the `target`. Save a copy of `current` into `result`.
* **Failure (`remain < 0`)**: The sum exceeded the `target`. No point in adding more positive numbers. We cut off this branch of the recursion (pruning).

---

### 🔹 The Loop and `start` Index

```cpp
for (int i = start; i < candidates.size(); i++) {
```
* Why `start` instead of `0`?
* If we started from `0` every time, we would generate permutations (e.g., `[2,2,3]` and `[3,2,2]`).
* By starting from `start`, we enforce that after we finish using the number at index `0`, we only use numbers at index `1` and beyond. This guarantees unique combinations!

---

### 🔹 Choose, Explore, Un-choose

```cpp
current.push_back(candidates[i]);
backtrack(candidates, remain - candidates[i], i, current, result);
current.pop_back();
```
* **Choose**: Add the current candidate to our combination.
* **Explore**: Recursively call `backtrack`.
  * We pass `remain - candidates[i]` as the new target to reach.
  * We pass `i` (not `i + 1`) as the new `start`. This allows the algorithm to pick `candidates[i]` again on the next level of recursion!
* **Un-choose (Backtrack)**: Remove the candidate we just added to try the next `i` in the loop.

---

# 📊 Step-by-Step Example (Decision Tree)

Input: `candidates = [2, 3, 6, 7]`, `target = 7`

```
backtrack(remain=7, start=0, current=[])
|
|-- i=0 (pick 2) -> backtrack(5, 0, [2])
|   |-- i=0 (pick 2) -> backtrack(3, 0, [2,2])
|   |   |-- i=0 (pick 2) -> backtrack(1, 0, [2,2,2])
|   |   |   |-- i=0 (pick 2) -> backtrack(-1, 0, [2,2,2,2]) -> BASE CASE 2 (return)
|   |   |   |-- i=1 (pick 3) -> backtrack(-2, 1, [2,2,2,3]) -> BASE CASE 2 (return)
|   |   |
|   |   |-- i=1 (pick 3) -> backtrack(0, 1, [2,2,3]) -> BASE CASE 1 (Found!) ✅
|   |
|   |-- i=1 (pick 3) -> backtrack(2, 1, [2,3])
|       |-- i=1 (pick 3) -> backtrack(-1, 1, [2,3,3]) -> BASE CASE 2
|
|-- i=1 (pick 3) -> backtrack(4, 1, [3])
|   |-- i=1 (pick 3) -> backtrack(1, 1, [3,3])
|       |-- ...
|
|-- i=2 (pick 6) -> backtrack(1, 2, [6]) -> ...
|
|-- i=3 (pick 7) -> backtrack(0, 3, [7]) -> BASE CASE 1 (Found!) ✅
```

✅ Final Answer = `[[2,2,3], [7]]`

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(N^(T/M))**
* `N` is the number of candidates. `T` is the target. `M` is the minimal value among candidates.
* In the worst case, the height of the recursion tree is `T/M` (if we just keep picking the smallest element). The fan-out is `N`.
* This is a loose upper bound. In reality, pruning (`remain < 0`) cuts off many branches early.

---

### 🔹 Space Complexity: **O(T/M)**
* The maximum depth of the recursion tree is `T/M`.
* The `current` array will at most store `T/M` elements.
* (Excluding space for output `result`).

---

# ⭐ Key Concepts Learned
* **Unbounded Knapsack-like Backtracking**: Allowing items to be reused by passing `i` instead of `i+1` to the recursive call.
* **Duplicate Avoidance**: Using a `start` parameter to enforce an order, preventing duplicate sets with different arrangements.
* **Pruning**: Using `remain < 0` to immediately stop exploring invalid paths, optimizing execution time.

---

# 🏆 Why This Problem Is Important
* Essential pattern for combinations/subsets with replacement.
* Perfects your understanding of how parameters in a backtracking function control the search space.
* Often asked as a follow-up or precursor to "Combination Sum II" (where elements can only be used once).
