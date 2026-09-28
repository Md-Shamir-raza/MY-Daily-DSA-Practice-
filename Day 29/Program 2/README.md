# Insert Interval (LeetCode #57)

## 📝 Problem Description
You are given an array of non-overlapping intervals `intervals` where `intervals[i] = [starti, endi]` represent the start and the end of the `i`th interval and `intervals` is sorted in ascending order by `starti`. You are also given an interval `newInterval = [start, end]` that represents the start and end of another interval.
Insert `newInterval` into `intervals` such that `intervals` is still sorted in ascending order by `starti` and `intervals` still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return `intervals` after the insertion.

**Example 1:**
- **Input:** intervals = [[1,3],[6,9]], newInterval = [2,5]
- **Output:** [[1,5],[6,9]]

**Example 2:**
- **Input:** intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
- **Output:** [[1,2],[3,10],[12,16]]
- **Explanation:** Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

## 💡 Solution Approach
Since the given array is already sorted and non-overlapping, we can solve this in a single pass:
1. Iterate and add all intervals that end *before* the `newInterval` starts. These have no overlap.
2. Once we reach an interval that overlaps, we continually merge it with the `newInterval` by taking the minimum of their start times and the maximum of their end times. We do this for all overlapping intervals and then push the final merged `newInterval`.
3. Finally, add all remaining intervals that start *after* the `newInterval` ends.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(N) where N is the number of intervals, as we iterate through the list exactly once.
- **Space Complexity:** O(N) to store the resulting merged intervals in a new vector.
