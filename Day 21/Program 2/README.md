# Min Stack (LeetCode #155)

## 📝 Problem Description
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the `MinStack` class:
- `MinStack()` initializes the stack object.
- `void push(int val)` pushes the element `val` onto the stack.
- `void pop()` removes the element on the top of the stack.
- `int top()` gets the top element of the stack.
- `int getMin()` retrieves the minimum element in the stack.

You must implement a solution with `O(1)` time complexity for each function.

**Example:**
```cpp
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
```

## 💡 Solution Approach
To achieve O(1) time for `getMin()`, we can use an auxiliary stack (`min_s`). The main stack `s` keeps all elements as they are pushed. The auxiliary stack `min_s` keeps track of the minimums. When pushing an element, if it's less than or equal to the top of `min_s` (or if `min_s` is empty), we push it to `min_s` as well. When popping, if the top of `s` is equal to the top of `min_s`, we also pop from `min_s`. This ensures `min_s` always has the current minimum on top.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(1) for all operations.
- **Space Complexity:** O(N) where N is the number of elements in the stack, for the auxiliary stack.
