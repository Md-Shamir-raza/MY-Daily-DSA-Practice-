
# 🔠 Find All Anagrams in a String – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #438 – Medium)

Given two strings `s` and `p`, return an array of all the start indices of `p`'s anagrams in `s`. You may return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example:

```
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
```

---

# 🧠 Approach: Fixed-Size Sliding Window

The key insight is:

> An anagram has the exact same character frequencies as the original string.
> Since we are looking for anagrams of `p`, the length of our target substring is fixed to `p.length()`.
> We can use a **fixed-size sliding window**. We maintain frequency arrays for `p` and the current window in `s`. As the window slides, we add the new character and remove the old character from our frequency array. If the two frequency arrays match, we found an anagram!

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.length() < p.length()) return result;

        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);

        for (char c : p) {
            pCount[c - 'a']++;
        }

        int pLen = p.length();
        
        for (int i = 0; i < s.length(); i++) {
            sCount[s[i] - 'a']++;

            if (i >= pLen) {
                sCount[s[i - pLen] - 'a']--;
            }

            if (sCount == pCount) {
                result.push_back(i - pLen + 1);
            }
        }

        return result;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 Edge Case & Setup

```cpp
vector<int> result;
if (s.length() < p.length()) return result;
```
* If `s` is shorter than `p`, it's impossible to find any anagrams. Return empty result immediately.

---

### 🔹 Frequency Arrays

```cpp
vector<int> pCount(26, 0);
vector<int> sCount(26, 0);

for (char c : p) {
    pCount[c - 'a']++;
}
```
* We use arrays of size 26 to count character frequencies (`a-z`).
* We pre-fill `pCount` with the frequencies of the target string `p`. This acts as our "fingerprint".

---

### 🔹 The Sliding Window

```cpp
int pLen = p.length();
for (int i = 0; i < s.length(); i++) {
    sCount[s[i] - 'a']++;
```
* We iterate through `s`. `i` represents the right edge of our window.
* We add the character at `s[i]` to our current window's frequency array `sCount`.

---

### 🔹 Shrinking the Window

```cpp
    if (i >= pLen) {
        sCount[s[i - pLen] - 'a']--;
    }
```
* Our window size must be exactly `pLen`.
* If `i >= pLen`, it means the window has grown too large. We need to remove the character that just fell out of the left side of the window.
* The character falling out is at index `i - pLen`. We decrement its count in `sCount`.

---

### 🔹 Checking for Anagrams

```cpp
    if (sCount == pCount) {
        result.push_back(i - pLen + 1);
    }
}
```
* C++ `vector` allows direct `==` comparison! It checks if all 26 elements match perfectly.
* If they match, our current window is an anagram.
* The starting index of this window is `i - pLen + 1` (since `i` is the end index).

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(N)**
* We iterate through `s` once (`O(N)`).
* Comparing two vectors of size 26 takes `O(26)` which is `O(1)` constant time.
* Total: `O(N)`.

### 🔹 Space Complexity: **O(1)**
* The vectors `pCount` and `sCount` are always of fixed size 26.
