# Task Scheduler (LeetCode #621)

## 📝 Problem Description
Given a characters array `tasks`, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
However, there is a non-negative integer `n` that represents the cooldown period between two **same** tasks. There must be at least `n` units of time between any two same tasks.
Return the least number of units of times that the CPU will take to finish all the given tasks.

**Example 1:**
- **Input:** tasks = ["A","A","A","B","B","B"], n = 2
- **Output:** 8
- **Explanation:** A -> B -> idle -> A -> B -> idle -> A -> B

**Example 2:**
- **Input:** tasks = ["A","A","A","B","B","B"], n = 0
- **Output:** 6
- **Explanation:** No cooldown required, tasks execute consecutively.

## 💡 Solution Approach
The key insight is that the most frequent task dictates the minimum number of intervals. If the most frequent task appears `maxFreq` times, we need at least `(maxFreq - 1)` gaps of size `(n + 1)` between them, plus the last group of tasks that share the maximum frequency (`maxCount`).
The formula is: `result = max(total_tasks, (maxFreq - 1) * (n + 1) + maxCount)`.
We take the max with `total_tasks` because when there are many different tasks and the cooldown is small, we might not need any idle time at all.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(N) where N is the number of tasks (one pass to count frequencies, one pass to find max).
- **Space Complexity:** O(1) since the frequency array is always of fixed size 26 (for uppercase letters).
