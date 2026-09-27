# Longest Consecutive Sequence (LeetCode #128)

## 📝 Problem Description
Given an unsorted array of integers `nums`, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in `O(n)` time.

**Example 1:**
- **Input:** nums = [100,4,200,1,3,2]
- **Output:** 4
- **Explanation:** The longest consecutive elements sequence is `[1, 2, 3, 4]`. Therefore its length is 4.

**Example 2:**
- **Input:** nums = [0,3,7,2,5,8,4,6,0,1]
- **Output:** 9

## 💡 Solution Approach
To solve this problem in O(N) time, we can utilize a Hash Set (`unordered_set` in C++). 
First, we insert all the elements into the hash set. Then, we iterate through the set. For each number, we check if it is the *start* of a sequence by verifying if `num - 1` exists in the set. If it doesn't, it is the start. From there, we continuously check for `num + 1`, `num + 2`, etc., and count the sequence length. Using a hash set allows O(1) average time complexity for lookups, ensuring our total time is strictly O(N).

## ⏱ Time & Space Complexity
- **Time Complexity:** O(N) because we iterate through the array once to populate the set, and the inner `while` loop only runs for elements that are part of a sequence, guaranteeing each element is visited at most twice.
- **Space Complexity:** O(N) for storing the numbers in the `unordered_set`.
