
# 🔁 Longest Repeating Character Replacement – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #424 – Medium)

You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example:

```
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
```

More examples:

```
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
```

---

# 🧠 Approach: Sliding Window

The key insight is:

> We can use a sliding window `[left, right]`.
> The core condition for a valid window is: **`WindowLength - MaxFrequencyCharacterCount <= k`**.
> This means the total characters in the window minus the most frequent character equals the number of characters we *need to replace*. If this number is greater than `k`, the window is invalid, and we must shrink it from the left.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxCount = 0;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);

            if ((right - left + 1) - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 Initialization

```cpp
vector<int> count(26, 0);
int maxCount = 0;
int maxLength = 0;
int left = 0;
```
* `count`: Array to store frequencies of each character in the current window.
* `maxCount`: The count of the most frequent character in the current window.
* `maxLength`: The global maximum valid window size found so far.
* `left`: The left pointer of our sliding window.

---

### 🔹 Expand Window

```cpp
for (int right = 0; right < s.length(); right++) {
    count[s[right] - 'A']++;
    maxCount = max(maxCount, count[s[right] - 'A']);
```
* The `right` pointer expands the window one character at a time.
* We increment the count of the character at `s[right]`.
* We update `maxCount`. Note: we don't need to recalculate `maxCount` from scratch when we shrink the window. A valid window will only get *larger* if we find a new `maxCount` that exceeds the historical `maxCount`.

---

### 🔹 Validate and Shrink Window

```cpp
    if ((right - left + 1) - maxCount > k) {
        count[s[left] - 'A']--;
        left++;
    }
```
* `right - left + 1` is the current window size.
* Window size minus `maxCount` is the number of characters that need to be replaced.
* If this exceeds `k`, the window is invalid. We must shrink it by moving `left` forward.
* When we move `left`, we also decrement the frequency count of the character that just left the window.

---

### 🔹 Update Max Length

```cpp
    maxLength = max(maxLength, right - left + 1);
}
return maxLength;
```
* Once the window is guaranteed to be valid (after the `if` statement), we update `maxLength`.

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(N)**
* Both `left` and `right` pointers traverse the string at most once.

### 🔹 Space Complexity: **O(1)**
* The `count` array is always size 26, which is constant space.
