
# 🔗 Merge Intervals – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #56 – Medium)

Given an array of `intervals` where `intervals[i] = [start_i, end_i]`, merge all **overlapping intervals**, and return an array of the **non-overlapping intervals** that cover all the intervals in the input.

Example:

```
Input:  intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: [1,3] and [2,6] overlap → merge into [1,6]
```

More examples:

```
Input:  [[1,4],[4,5]]   → Output: [[1,5]]
Input:  [[1,4],[0,4]]   → Output: [[0,4]]
Input:  [[1,4],[2,3]]   → Output: [[1,4]]  (second is inside first)
```

---

# 🧠 Approach: Sort + Linear Merge

The key insight is:

> If intervals are **sorted by start time**, overlapping intervals will be **adjacent**. We just need to check if the current interval overlaps with the last merged one.

### Two intervals overlap when:

```
last_end >= current_start
```

### Merge strategy:

- If overlap → extend the end: `merged_end = max(last_end, current_end)`
- If no overlap → add as a new separate interval

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        for (auto& interval : intervals) {
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 `sort(intervals.begin(), intervals.end());`

* Sort all intervals by their **start time** (ascending).
* `vector<vector<int>>` sorts by the first element by default.
* This ensures overlapping intervals are **next to each other**.

Example:
```
Before: [[6,8],[1,9],[2,4],[4,7]]
After:  [[1,9],[2,4],[4,7],[6,8]]
```

---

### 🔹 `vector<vector<int>> merged;`

* The result array to store merged intervals.
* We build it one interval at a time.

---

### 🔹 `for (auto& interval : intervals)`

* Iterate through each interval in the sorted order.
* `auto&` avoids making copies.

---

### 🔹 Check for Overlap

```cpp
if (merged.empty() || merged.back()[1] < interval[0])
```

#### Two conditions where we add a new interval:

1. **`merged.empty()`** → No intervals added yet, so just add the first one.
2. **`merged.back()[1] < interval[0]`** → The last merged interval **ends before** the current one starts → **no overlap**.

```
Last:     [1,---3]
Current:            [8,---10]
                 ↑ gap → no overlap
```

---

### 🔹 No Overlap → Add New Interval

```cpp
merged.push_back(interval);
```

* Simply add the current interval as a separate entry.

---

### 🔹 Overlap → Merge

```cpp
merged.back()[1] = max(merged.back()[1], interval[1]);
```

* The current interval overlaps with the last merged interval.
* Extend the **end** of the last merged interval to cover both.
* We use `max()` because the current interval might be **completely inside** the last one.

```
Case 1: Partial overlap
Last:     [1,------6]
Current:      [2,------8]
Merged:   [1,-----------8]   → end = max(6, 8) = 8

Case 2: Complete containment
Last:     [1,----------9]
Current:    [2,---4]
Merged:   [1,----------9]   → end = max(9, 4) = 9
```

---

### 🔹 `return merged;`

* Return the final list of non-overlapping intervals.

---

# 📊 Step-by-Step Example

Input:

```
intervals = [[1,3],[2,6],[8,10],[15,18]]
```

Already sorted by start time.

| Step | Current | merged (before) | Overlap? | Action | merged (after) |
| ---- | ------- | --------------- | -------- | ------ | -------------- |
| 1    | [1,3]   | []              | — (empty)| Add    | [[1,3]]        |
| 2    | [2,6]   | [[1,3]]         | Yes (3≥2)| Merge  | [[1,6]]        |
| 3    | [8,10]  | [[1,6]]         | No (6<8) | Add    | [[1,6],[8,10]] |
| 4    | [15,18] | [[1,6],[8,10]]  | No (10<15)| Add   | [[1,6],[8,10],[15,18]] |

✅ Final Answer = **[[1,6],[8,10],[15,18]]**

---

# 🎯 Visual Representation

```
Input intervals on a number line:

[1,---3]
   [2,-------6]
                  [8,--10]
                              [15,--18]

After merging:

[1,---------6]   [8,--10]    [15,--18]
```

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(n log n)**

* Sorting takes `O(n log n)`.
* The merging loop takes `O(n)`.
* Total: `O(n log n)` — dominated by sorting.

---

### 🔹 Space Complexity: **O(n)**

* The `merged` array stores at most `n` intervals.
* If we consider the output as required space → **O(1)** extra space.

---

# ⚔️ Comparison With Other Approaches

| Approach                      | Time Complexity | Space Complexity |
| ----------------------------- | --------------- | ---------------- |
| Brute Force (Compare All)     | O(n²)           | O(n)             |
| Sort + Linear Merge (Optimal) | O(n log n)      | O(n)             |

The sort-based approach is **optimal** — you can't do better than O(n log n) since sorting is required 🚀

---

# ⭐ Key Concepts Learned

* **Interval merging** — fundamental technique for range problems
* Sorting as a preprocessing step to group overlapping intervals
* Using `max()` to handle both partial overlap and containment
* Building result arrays incrementally with `push_back`
* Edge cases: touching intervals [1,4] and [4,5] count as overlapping

---

# 🏆 Why This Problem Is Important

* One of the **most frequently asked** interview problems
* Foundation for many interval-based problems (Insert Interval, Meeting Rooms)
* Tests sorting + greedy logic combined
* Real-world applications: calendar merging, time scheduling, range consolidation
* Commonly asked at Google, Amazon, Facebook, Microsoft, Bloomberg
