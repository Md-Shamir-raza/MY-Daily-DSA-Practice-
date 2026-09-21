# Find Minimum in Rotated Sorted Array (LeetCode #153)

## 📝 Problem Description
Suppose an array of length `n` sorted in ascending order is rotated between `1` and `n` times. Given the sorted rotated array `nums` of unique elements, return the minimum element of this array.
You must write an algorithm that runs in `O(log n)` time.

**Example 1:**
- **Input:** nums = [3,4,5,1,2]
- **Output:** 1
- **Explanation:** The original array was [1,2,3,4,5] rotated 3 times.

**Example 2:**
- **Input:** nums = [4,5,6,7,0,1,2]
- **Output:** 0
- **Explanation:** The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

## 💡 Solution Approach
Since the problem requires an `O(log n)` time complexity, we must use Binary Search.
We initialize `left` and `right` pointers. We compare the middle element with the rightmost element. If the middle element is greater than the rightmost element, the minimum must be to the right of `mid`. Otherwise, the minimum is at `mid` or to the left of it.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(log N) where N is the length of the array, due to the binary search.
- **Space Complexity:** O(1) auxiliary space used.
