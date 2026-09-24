# House Robber (LeetCode #198)

## 📝 Problem Description
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.
Given an integer array `nums` representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

**Example 1:**
- **Input:** nums = [1,2,3,1]
- **Output:** 4
- **Explanation:** Rob house 1 (money = 1) and then rob house 3 (money = 3). Total amount you can rob = 1 + 3 = 4.

**Example 2:**
- **Input:** nums = [2,7,9,3,1]
- **Output:** 12
- **Explanation:** Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1). Total amount you can rob = 2 + 9 + 1 = 12.

## 💡 Solution Approach
We can use Dynamic Programming. At each house `i`, the robber has two choices:
1. Rob house `i`, which means they couldn't have robbed house `i-1`. So the loot is `nums[i] + max_loot(i-2)`.
2. Don't rob house `i`, meaning they keep the maximum loot from up to house `i-1`.
So, `dp[i] = max(dp[i-1], dp[i-2] + nums[i])`.
Similar to the Fibonacci sequence or Climbing Stairs, we only need to keep track of the maximum loot at the previous two houses (`prev1` and `prev2`) to optimize space to O(1).

## ⏱ Time & Space Complexity
- **Time Complexity:** O(N) where N is the number of houses, since we iterate through the array exactly once.
- **Space Complexity:** O(1) because we only use two variables to store previous computations.
