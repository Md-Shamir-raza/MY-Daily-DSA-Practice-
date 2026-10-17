# Reverse Bits (LeetCode #190)

## 📝 Problem Description
Reverse bits of a given 32 bits unsigned integer.

**Example 1:**
- **Input:** n = 00000010100101000001111010011100
- **Output:** 964176192 (00111001011110000010100101000000)
- **Explanation:** The input binary string represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.

**Example 2:**
- **Input:** n = 11111111111111111111111111111101
- **Output:** 3221225471 (10111111111111111111111111111111)

## 💡 Solution Approach
We process each of the 32 bits one at a time:
1. **Shift `result` left** by 1 to make room for the next bit.
2. **Extract the last bit** of `n` using `n & 1` and **OR** it into `result`.
3. **Shift `n` right** by 1 to move to the next bit.

After 32 iterations, every bit of `n` has been placed in the reverse position in `result`. This is essentially reading the bits of `n` from right-to-left and writing them into `result` from left-to-right.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(1) — we always iterate exactly 32 times regardless of input.
- **Space Complexity:** O(1) — only a constant amount of extra space is used.
