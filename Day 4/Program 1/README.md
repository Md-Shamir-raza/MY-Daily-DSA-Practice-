
# 🪞 Longest Palindromic Substring – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #5 – Medium)

Given a string `s`, return the **longest palindromic substring** in `s`.

A **palindrome** is a string that reads the same forward and backward.

Example:

```
Input:  s = "babad"
Output: "bab"  (or "aba" — both are valid)
```

More examples:

```
Input: "cbbd"    → Output: "bb"
Input: "a"       → Output: "a"
Input: "racecar" → Output: "racecar"
```

---

# 🧠 Approach: Expand Around Center

The key insight is:

> A palindrome mirrors around its center. We can expand outward from every possible center and check how far the palindrome extends.

### Two types of centers:

| Type | Center | Example |
| ---- | ------ | ------- |
| Odd-length | Single character | "aba" → center is 'b' |
| Even-length | Gap between two characters | "abba" → center is between 'b' and 'b' |

### Total centers = `2n - 1`

For a string of length `n`:
- `n` single-character centers (odd-length palindromes)
- `n - 1` gap centers (even-length palindromes)

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            // Case 1: Odd-length palindrome
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }

            // Case 2: Even-length palindrome
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 `if (n < 2) return s;`

* **Edge case**: A string of length 0 or 1 is already a palindrome.
* Return it directly — no processing needed.

---

### 🔹 `int start = 0;` and `int maxLen = 1;`

* `start` → Starting index of the longest palindrome found so far.
* `maxLen` → Length of the longest palindrome found so far.
* Initialized to `1` because every single character is a palindrome.

---

### 🔹 `for (int i = 0; i < n; i++)`

* Try every index `i` as a potential **center** of a palindrome.
* For each `i`, we check both odd and even length palindromes.

---

### 🔹 Case 1: Odd-Length Palindrome

```cpp
int left = i, right = i;
while (left >= 0 && right < n && s[left] == s[right]) {
    if (right - left + 1 > maxLen) {
        start = left;
        maxLen = right - left + 1;
    }
    left--;
    right++;
}
```

#### What happens:

* Start with `left = right = i` (single character center).
* Expand outward: `left--` and `right++`.
* Continue as long as:
  - We're within bounds (`left >= 0 && right < n`)
  - Characters match (`s[left] == s[right]`)
* Update `start` and `maxLen` whenever we find a longer palindrome.

#### Example with "racecar", i = 3 (center = 'e'):

```
Step 1: left=3, right=3 → "e" ✅
Step 2: left=2, right=4 → "cec" ✅
Step 3: left=1, right=5 → "aceca" ✅
Step 4: left=0, right=6 → "racecar" ✅
Step 5: left=-1 → out of bounds, stop
```

---

### 🔹 Case 2: Even-Length Palindrome

```cpp
left = i;
right = i + 1;
while (left >= 0 && right < n && s[left] == s[right]) {
    ...
}
```

#### What happens:

* Start with `left = i` and `right = i + 1` (gap between two characters).
* Same expansion logic as the odd case.

#### Example with "cbbd", i = 1:

```
Step 1: left=1, right=2 → s[1]='b', s[2]='b' → "bb" ✅
Step 2: left=0, right=3 → s[0]='c', s[3]='d' → ❌ stop
```

---

### 🔹 `return s.substr(start, maxLen);`

* Extract and return the longest palindromic substring.
* `substr(start, maxLen)` returns `maxLen` characters starting from index `start`.

---

# 📊 Step-by-Step Example

Input:

```
s = "babad"
```

| i | Odd Center | Odd Palindrome | Even Center | Even Palindrome | Best So Far |
| - | ---------- | -------------- | ----------- | --------------- | ----------- |
| 0 | 'b'        | "b" (len 1)    | 'b','a'     | — (mismatch)    | "b" (1)     |
| 1 | 'a'        | "bab" (len 3)  | 'a','b'     | — (mismatch)    | "bab" (3)   |
| 2 | 'b'        | "aba" (len 3)  | 'b','a'     | — (mismatch)    | "bab" (3)   |
| 3 | 'a'        | "a" (len 1)    | 'a','d'     | — (mismatch)    | "bab" (3)   |
| 4 | 'd'        | "d" (len 1)    | — (out)     | —               | "bab" (3)   |

✅ Final Answer = **"bab"** (length 3)

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(n²)**

* For each of `n` centers, expansion takes up to `O(n)` time.
* Total: `O(n) × O(n)` = **O(n²)**.

---

### 🔹 Space Complexity: **O(1)**

* Only a few integer variables used.
* No extra data structures (unlike DP approach which uses O(n²) space).

---

# ⚔️ Comparison With Other Approaches

| Approach                   | Time Complexity | Space Complexity |
| -------------------------- | --------------- | ---------------- |
| Brute Force (All Substrings) | O(n³)         | O(1)             |
| Dynamic Programming        | O(n²)           | O(n²)            |
| Expand Around Center       | O(n²)           | O(1)             |
| Manacher's Algorithm       | O(n)            | O(n)             |

Expand Around Center gives the **best balance** of simplicity and efficiency 🚀

---

# ⭐ Key Concepts Learned

* **Palindrome** properties — mirrors around its center
* **Expand Around Center** technique
* Handling both odd and even length palindromes
* String manipulation with `substr()`
* Optimizing from O(n³) brute force to O(n²)

---

# 🏆 Why This Problem Is Important

* One of the **most classic** string problems in interviews
* Teaches center expansion — a technique used in many palindrome problems
* Tests understanding of string properties and edge cases
* Foundation for Manacher's Algorithm (O(n) solution)
* Frequently asked at Amazon, Google, Microsoft, Goldman Sachs
