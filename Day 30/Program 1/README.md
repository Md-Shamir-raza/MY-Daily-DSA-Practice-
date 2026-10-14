# Minimum Number of Arrows to Burst Balloons (LeetCode #452)

## 📝 Problem Description
There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array `points` where `points[i] = [xstart, xend]` denotes a balloon whose horizontal diameter stretches between `xstart` and `xend`. You do not know the exact y-coordinates of the balloons.
Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with `xstart` and `xend` is burst by an arrow shot at `x` if `xstart <= x <= xend`.
Given the array `points`, return the **minimum** number of arrows that must be shot to burst all balloons.

**Example 1:**
- **Input:** points = [[10,16],[2,8],[1,6],[7,12]]
- **Output:** 2
- **Explanation:** The balloons can be burst by 2 arrows: Shoot at x = 6 (bursts [2,8] and [1,6]) and shoot at x = 11 (bursts [10,16] and [7,12]).

**Example 2:**
- **Input:** points = [[1,2],[3,4],[5,6],[7,8]]
- **Output:** 4
- **Explanation:** Each balloon requires its own arrow since none overlap.

## 💡 Solution Approach
This is a classic **Greedy** problem very similar to Non-overlapping Intervals. We sort the balloons by their **end coordinate**. We then greedily shoot an arrow at the end of the first balloon. Any subsequent balloon whose start is less than or equal to the current arrow position is already burst. If a balloon starts after the current arrow, we need a new arrow at that balloon's end.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(N log N) due to sorting. The iteration is O(N).
- **Space Complexity:** O(log N) for the sorting algorithm's internal stack.
