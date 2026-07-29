
# 🌊 Container With Most Water – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #11 – Medium)

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `i-th` line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the **most water**.

Return the **maximum amount of water** a container can store.

Example:

```
Input:  height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: Lines at index 1 (height=8) and index 8 (height=7)
             Width = 8 - 1 = 7
             Height = min(8,7) = 7
             Area = 7 × 7 = 49
```

---

# 🧠 Approach: Two Pointer Technique

The key insight is:

> Start with the widest container (left and right edges) and progressively try to find a taller container by moving the shorter side inward.

Why does this work?
- The width decreases as we move pointers inward.
- To get a larger area, we **need a taller height**.
- Moving the **taller** pointer inward can only decrease or maintain the area.
- Moving the **shorter** pointer inward might find a taller line and increase area.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int h = min(height[left], height[right]);
            int area = width * h;

            maxWater = max(maxWater, area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 `int left = 0;`

* Left pointer starts at the **beginning** of the array.

---

### 🔹 `int right = height.size() - 1;`

* Right pointer starts at the **end** of the array.
* This gives us the **widest possible container** initially.

---

### 🔹 `int maxWater = 0;`

* Stores the **maximum area** found so far.
* Initialized to `0` since area is always non-negative.

---

### 🔹 `while (left < right)`

* We continue until the two pointers meet.
* When `left == right`, no container can be formed.

---

### 🔹 Calculate Width

```cpp
int width = right - left;
```

* The distance between the two lines on the x-axis.

---

### 🔹 Calculate Height

```cpp
int h = min(height[left], height[right]);
```

* Water level is limited by the **shorter** of the two lines.
* Water would overflow over the shorter side.

---

### 🔹 Calculate Area

```cpp
int area = width * h;
```

* Area of water = `width × height`
* This is the amount of water this particular container can hold.

---

### 🔹 Update Maximum

```cpp
maxWater = max(maxWater, area);
```

* Keep track of the largest area we've seen.

---

### 🔹 Move the Shorter Pointer

```cpp
if (height[left] < height[right]) {
    left++;
} else {
    right--;
}
```

#### Why move the shorter one?

* The area is limited by the shorter line.
* Moving the taller line inward **cannot** increase the area (width decreases, and height stays capped by the shorter line).
* Moving the shorter line inward **might** find a taller line → potentially larger area.

This is the **greedy choice** that guarantees we don't miss the optimal pair.

---

# 📊 Step-by-Step Example

Input:

```
height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
```

| Step | left | right | height[left] | height[right] | width | h   | area | maxWater | Move        |
| ---- | ---- | ----- | ------------ | ------------- | ----- | --- | ---- | -------- | ----------- |
| 1    | 0    | 8     | 1            | 7             | 8     | 1   | 8    | 8        | left++      |
| 2    | 1    | 8     | 8            | 7             | 7     | 7   | 49   | 49       | right--     |
| 3    | 1    | 7     | 8            | 3             | 6     | 3   | 18   | 49       | right--     |
| 4    | 1    | 6     | 8            | 8             | 5     | 8   | 40   | 49       | right--     |
| 5    | 1    | 5     | 8            | 4             | 4     | 4   | 16   | 49       | right--     |
| 6    | 1    | 4     | 8            | 5             | 3     | 5   | 15   | 49       | right--     |
| 7    | 1    | 3     | 8            | 2             | 2     | 2   | 4    | 49       | right--     |
| 8    | 1    | 2     | 8            | 6             | 1     | 6   | 6    | 49       | right--     |

✅ Final Answer = **49**

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(n)**

* We use two pointers that collectively traverse the array once.
* Each pointer moves at most `n` times total.

---

### 🔹 Space Complexity: **O(1)**

* Only a few integer variables are used.
* No extra data structures needed.

---

# ⚔️ Comparison With Brute Force

| Approach                   | Time Complexity | Space Complexity |
| -------------------------- | --------------- | ---------------- |
| Brute Force (All Pairs)    | O(n²)           | O(1)             |
| Two Pointer (Optimized)    | O(n)            | O(1)             |

The two-pointer approach is significantly faster for large inputs 🚀

---

# ⭐ Key Concepts Learned

* Two Pointer technique
* Greedy approach — always move the shorter pointer
* Area calculation with constraints
* Proving correctness of greedy choice

---

# 🏆 Why This Problem Is Important

* Classic two-pointer problem asked in top company interviews
* Teaches how to reduce O(n²) to O(n) with clever observations
* Foundation for understanding greedy algorithms
* Commonly asked at Google, Amazon, Microsoft, Meta
