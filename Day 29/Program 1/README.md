# Non-overlapping Intervals (LeetCode #435)

## 📝 Problem Description
Given an array of intervals `intervals` where `intervals[i] = [starti, endi]`, return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

**Example 1:**
- **Input:** intervals = [[1,2],[2,3],[3,4],[1,3]]
- **Output:** 1
- **Explanation:** [1,3] can be removed and the rest of the intervals are non-overlapping.

**Example 2:**
- **Input:** intervals = [[1,2],[1,2],[1,2]]
- **Output:** 2
- **Explanation:** You need to remove two [1,2] to make the rest of the intervals non-overlapping.

## 💡 Solution Approach
This problem can be optimally solved using a **Greedy Algorithm**. 
To minimize the number of overlapping intervals to remove, we should always keep the intervals that end the earliest. This leaves the maximum possible room for future intervals. 
We sort the intervals based on their **end times**. We keep track of the `current_end` time. As we iterate through the sorted intervals, if an interval's start time is less than the `current_end`, it overlaps, and we must "remove" it (increment our counter). Otherwise, it doesn't overlap, and we update `current_end` to this new interval's end time.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(N log N) where N is the number of intervals. This is due to the sorting step. The iteration takes O(N) time.
- **Space Complexity:** O(1) or O(log N) depending on the sorting algorithm implementation under the hood (e.g., IntroSort in C++).
