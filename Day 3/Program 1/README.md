
# 🔤 Longest Substring Without Repeating Characters – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #3 – Medium)

Given a string `s`, find the length of the **longest substring** without repeating characters.

A **substring** is a contiguous sequence of characters within the string.

Example:

```
Input:  s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with length 3.
```

More examples:

```
Input: "bbbbb"   → Output: 1  (just "b")
Input: "pwwkew"  → Output: 3  (either "wke" or "kew")
Input: ""        → Output: 0
```

---

# 🧠 Approach: Sliding Window + Hash Set

The key insight is:

> Use two pointers (left, right) to maintain a "window" of unique characters. Expand the window by moving `right`. When a duplicate is found, shrink from `left` until the duplicate is removed.

### Why this works:

1. The **window** always contains unique characters.
2. We **expand** when we can (no duplicate).
3. We **shrink** when we must (duplicate found).
4. We track the **maximum window size** seen.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;

        unordered_set<char> charSet;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {
            // If character already exists in the window, shrink from left
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }

            // Add current character to the set
            charSet.insert(s[right]);

            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 `int n = s.size();`

* Store the length of the string.
* Used to control the loop boundary.

---

### 🔹 `if (n == 0) return 0;`

* **Edge case**: Empty string has no substring.
* Return 0 immediately.

---

### 🔹 `unordered_set<char> charSet;`

* A **hash set** to store characters currently in our window.
* Provides **O(1)** lookup, insert, and delete.
* At any point, this set contains exactly the characters in `s[left...right]`.

---

### 🔹 `int left = 0;`

* The **left boundary** of our sliding window.
* Starts at index 0.

---

### 🔹 `int maxLen = 0;`

* Stores the **maximum length** of a valid substring found so far.

---

### 🔹 `for (int right = 0; right < n; right++)`

* The **right pointer** expands the window one character at a time.
* This is the main loop that drives the sliding window.

---

### 🔹 Shrink Window If Duplicate Found

```cpp
while (charSet.find(s[right]) != charSet.end()) {
    charSet.erase(s[left]);
    left++;
}
```

#### What happens here:

* Before adding `s[right]`, we check if it **already exists** in the set.
* If yes → we have a **duplicate**!
* We **remove characters from the left** until the duplicate is gone.
* This shrinks the window to maintain the "all unique" invariant.

#### Example:

```
s = "abcabc"
Window: [a,b,c], right wants to add 'a'
  → 'a' exists! Remove 'a' from left → Window: [b,c]
  → Now 'a' doesn't exist → Add 'a' → Window: [b,c,a]
```

---

### 🔹 Add Current Character

```cpp
charSet.insert(s[right]);
```

* After ensuring no duplicate, add the new character to the set.

---

### 🔹 Update Maximum Length

```cpp
maxLen = max(maxLen, right - left + 1);
```

* `right - left + 1` = current window size.
* Update `maxLen` if current window is the largest seen.

---

### 🔹 Return Result

```cpp
return maxLen;
```

* Return the length of the longest substring found.

---

# 📊 Step-by-Step Example

Input:

```
s = "abcabcbb"
```

| Step | right | s[right] | charSet before | Action | left | charSet after | Window | maxLen |
| ---- | ----- | -------- | -------------- | ------ | ---- | ------------- | ------ | ------ |
| 1    | 0     | a        | {}             | Add    | 0    | {a}           | "a"    | 1      |
| 2    | 1     | b        | {a}            | Add    | 0    | {a,b}         | "ab"   | 2      |
| 3    | 2     | c        | {a,b}          | Add    | 0    | {a,b,c}       | "abc"  | 3      |
| 4    | 3     | a        | {a,b,c}        | Remove a, Add a | 1 | {b,c,a}  | "bca"  | 3      |
| 5    | 4     | b        | {b,c,a}        | Remove b, Add b | 2 | {c,a,b}  | "cab"  | 3      |
| 6    | 5     | c        | {c,a,b}        | Remove c, Add c | 3 | {a,b,c}  | "abc"  | 3      |
| 7    | 6     | b        | {a,b,c}        | Remove a,b, Add b | 5 | {c,b}  | "cb"   | 3      |
| 8    | 7     | b        | {c,b}          | Remove c,b, Add b | 7 | {b}    | "b"    | 3      |

✅ Final Answer = **3** (substring "abc")

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(n)**

* The `right` pointer moves from `0` to `n-1` → `n` steps.
* The `left` pointer also moves at most `n` steps total (across all iterations).
* Each character is added and removed from the set at most once.
* Total: **O(2n) = O(n)**.

---

### 🔹 Space Complexity: **O(min(m, n))**

* `m` = size of the character set (e.g., 26 for lowercase, 128 for ASCII).
* `n` = length of the string.
* The set stores at most `min(m, n)` characters.

---

# ⚔️ Comparison With Brute Force

| Approach                      | Time Complexity | Space Complexity     |
| ----------------------------- | --------------- | -------------------- |
| Brute Force (Check All Pairs) | O(n³)           | O(min(m, n))         |
| Sliding Window (Optimized)    | O(n)            | O(min(m, n))         |

The sliding window approach is dramatically faster 🚀

---

# ⭐ Key Concepts Learned

* **Sliding Window** technique — a fundamental pattern for substring/subarray problems
* **Hash Set** for O(1) character lookups
* Two-pointer window expansion and contraction
* Handling edge cases (empty string, all same characters)

---

# 🏆 Why This Problem Is Important

* One of the **most popular** LeetCode medium problems
* Teaches the sliding window pattern used in dozens of other problems
* Frequently asked at Amazon, Google, Microsoft, Facebook
* Foundation for more complex substring problems
* Tests understanding of hash sets and two-pointer techniques
