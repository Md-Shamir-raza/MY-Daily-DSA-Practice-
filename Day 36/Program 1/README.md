# Evaluate Reverse Polish Notation (LeetCode #150)

## 📝 Problem Description
You are given an array of strings `tokens` that represents an arithmetic expression in a **Reverse Polish Notation** (postfix notation).
Evaluate the expression. Return an integer that represents the value of the expression.
Valid operators are `+`, `-`, `*`, and `/`. Each operand may be an integer or another expression. Division between two integers truncates toward zero.

**Example 1:**
- **Input:** tokens = ["2","1","+","3","*"]
- **Output:** 9
- **Explanation:** ((2 + 1) * 3) = 9

**Example 2:**
- **Input:** tokens = ["4","13","5","/","+"]
- **Output:** 6
- **Explanation:** (4 + (13 / 5)) = 6

**Example 3:**
- **Input:** tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
- **Output:** 22

## 💡 Solution Approach
We use a **Stack** to evaluate the expression:
1. Iterate through each token.
2. If the token is a number, push it onto the stack.
3. If the token is an operator, pop two operands from the stack (`b` first, then `a`), apply the operation `a op b`, and push the result back.
4. After processing all tokens, the single remaining element on the stack is the result.

The key insight is that RPN eliminates the need for parentheses — the order of operations is implicitly defined by the position of operators.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(N) where N is the number of tokens. We process each token exactly once.
- **Space Complexity:** O(N) for the stack, which in the worst case holds all numbers before any operator is encountered.
