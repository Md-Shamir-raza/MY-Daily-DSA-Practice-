# Maximum Product Subarray (LeetCode #152)

## 📝 Problem Description
Given an integer array `nums`, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.

**Example 1:**
- **Input:** nums = [2,3,-2,4]
- **Output:** 6
- **Explanation:** [2,3] has the largest product 6.

**Example 2:**
- **Input:** nums = [-2,0,-1]
- **Output:** 0
- **Explanation:** The result cannot be 2, because [-2,-1] is not a subarray.

## 💡 Solution Approach
To solve this efficiently, we maintain two variables as we iterate through the array: `max_so_far` and `min_so_far`. The minimum product is necessary because a negative number multiplied by a negative minimum can instantly become the new maximum product. At each step, we update both values and keep track of the global maximum product.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(N) where N is the length of the array, as we iterate through it once.
- **Space Complexity:** O(1) since we only use a few variables.
