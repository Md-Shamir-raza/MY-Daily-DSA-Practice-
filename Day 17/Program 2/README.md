
# 🌡️ Daily Temperatures – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #739 – Medium)

Given an array of integers `temperatures` represents the daily temperatures, return an array `answer` such that `answer[i]` is the number of days you have to wait after the `i`th day to get a warmer temperature. If there is no future day for which this is possible, keep `answer[i] == 0` instead.

Example:

```
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
```

More examples:

```
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
```

---

# 🧠 Approach: Monotonic Decreasing Stack

The key insight is:

> We want to find the **Next Greater Element** for every item in the array.
> The optimal way to solve "Next Greater Element" problems is using a **Monotonic Stack**.
> A Monotonic Decreasing Stack keeps elements in strictly decreasing order.
> We iterate through the array. If we find a temperature *higher* than the temperature at the index stored on the top of our stack, we have found the answer for that stacked index!

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0); 
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                result[prevIndex] = i - prevIndex;
            }
            st.push(i);
        }

        return result;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 Initialization

```cpp
int n = temperatures.size();
vector<int> result(n, 0); 
stack<int> st;
```
* We initialize our `result` array with `0`s. This handles the case where a warmer day is never found.
* **CRITICAL**: The stack `st` will store the **indices** of the days, not the temperatures themselves. We need the indices to calculate the "number of days to wait" (`current_index - previous_index`).

---

### 🔹 Iterate and Maintain Stack

```cpp
for (int i = 0; i < n; i++) {
    while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
```
* We iterate through the temperatures.
* `while` loop checks: Is the stack not empty AND is the current temperature *hotter* than the temperature on the top of the stack?

---

### 🔹 Pop and Calculate

```cpp
        int prevIndex = st.top();
        st.pop();
        result[prevIndex] = i - prevIndex;
    }
```
* If the current temp is hotter, it means we found the "next warmer day" for `prevIndex`!
* We pop `prevIndex` from the stack.
* The wait time is `i - prevIndex`. We save this in our result array.
* The `while` loop continues. The current hot day might be the answer for *multiple* previous colder days stacked up!

---

### 🔹 Push Current Day

```cpp
    st.push(i);
}
```
* After clearing out any colder days from the stack, we push the current day's index onto the stack so it can wait for its own warmer day in the future.

---

# 📊 Step-by-Step Example

Input: `[73, 74, 75, 71, 69, 72, ...]`

1. **i=0 (Temp 73):** Stack empty. Push index `0`. Stack: `[0]`
2. **i=1 (Temp 74):** 74 > Temps[Stack.top(0)] (73).
   - Found warmer day for index 0! `result[0] = 1 - 0 = 1`.
   - Pop 0. Push index 1. Stack: `[1]`
3. **i=2 (Temp 75):** 75 > Temps[1] (74).
   - Found warmer day for index 1! `result[1] = 2 - 1 = 1`.
   - Pop 1. Push index 2. Stack: `[2]`
4. **i=3 (Temp 71):** 71 is NOT > 75. Push index 3. Stack: `[2, 3]` (Notice stack values are decreasing: 75, 71)
5. **i=4 (Temp 69):** 69 is NOT > 71. Push index 4. Stack: `[2, 3, 4]` (Temps: 75, 71, 69)
6. **i=5 (Temp 72):**
   - 72 > Temps[4] (69). Pop 4. `result[4] = 5 - 4 = 1`. Stack: `[2, 3]`
   - 72 > Temps[3] (71). Pop 3. `result[3] = 5 - 3 = 2`. Stack: `[2]`
   - 72 is NOT > Temps[2] (75).
   - Push 5. Stack: `[2, 5]`

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(N)**
* Every element is pushed onto the stack exactly once.
* Every element is popped from the stack at most once.
* Therefore, the while loop executes at most `N` times across the *entire* for loop, resulting in `O(N)` overall.

### 🔹 Space Complexity: **O(N)**
* The stack can hold up to `N` elements in the worst case (e.g., temperatures are continuously decreasing).
