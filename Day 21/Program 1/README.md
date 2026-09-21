# Valid Parentheses (LeetCode #20)

## 📝 Problem Description
Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.
An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

**Example 1:**
- **Input:** s = "()"
- **Output:** true

**Example 2:**
- **Input:** s = "()[]{}"
- **Output:** true

**Example 3:**
- **Input:** s = "(]"
- **Output:** false

## 💡 Solution Approach
We can use a Stack to keep track of the open brackets. We iterate through the string `s`. If we encounter an open bracket, we push it onto the stack. If we encounter a close bracket, we check if the stack is empty (if so, return false), and if the top of the stack is the matching open bracket. If it matches, we pop the top of the stack. After the loop, the stack should be empty if all brackets were validly matched.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(N) where N is the length of the string, since we traverse it once.
- **Space Complexity:** O(N) in the worst case (e.g., all open brackets), where we push all characters onto the stack.
