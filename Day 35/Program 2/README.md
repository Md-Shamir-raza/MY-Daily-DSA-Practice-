# Valid Anagram (LeetCode #242)

## 📝 Problem Description
Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.
An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

**Example 1:**
- **Input:** s = "anagram", t = "nagaram"
- **Output:** true

**Example 2:**
- **Input:** s = "rat", t = "car"
- **Output:** false

## 💡 Solution Approach
We use a **frequency counting** approach with a fixed-size array of 26 (for lowercase English letters):
1. If the two strings have different lengths, they can't be anagrams — return `false` immediately.
2. Iterate through both strings simultaneously: increment the count for each character in `s` and decrement for each character in `t`.
3. After the loop, if all counts are zero, the strings are anagrams.

This approach is more efficient than sorting (O(N log N)) as it runs in a single pass.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(N) where N is the length of the strings. We iterate through both strings once.
- **Space Complexity:** O(1) since the frequency array has a fixed size of 26, regardless of input size.
