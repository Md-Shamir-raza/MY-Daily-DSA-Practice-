
# ⛽ Gas Station – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #134 – Medium)

There are `n` gas stations along a circular route, where the amount of gas at the `i`th station is `gas[i]`.

You have a car with an unlimited gas tank and it costs `cost[i]` of gas to travel from the `i`th station to its next `(i + 1)`th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays `gas` and `cost`, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return `-1`. If there exists a solution, it is **guaranteed to be unique**.

Example:

```
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
```

---

# 🧠 Approach: Greedy

The key insights are:

1. **Global Check**: If the total sum of `gas` across all stations is less than the total sum of `cost`, it is mathematically impossible to complete the circuit. If `sum(gas) >= sum(cost)`, a solution *must* exist.
2. **Local Check (Greedy part)**: If we start at station `A` and run out of gas at station `B`, it means no station between `A` and `B` could possibly be a valid starting point either. Why? Because reaching `B` from `A` means we arrived at every intermediate station with `tank >= 0`. If we started at one of those intermediate stations instead, our tank would start at `0`, meaning we'd have even *less* gas and would definitely still fail at `B`.
   - Therefore, if we run out of gas at `i`, the next possible starting point is `i + 1`.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int currentTank = 0;
        int startingStation = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            
            currentTank += gas[i] - cost[i];

            if (currentTank < 0) {
                startingStation = i + 1;
                currentTank = 0;
            }
        }

        if (totalGas < totalCost) return -1;
        return startingStation;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 Initialization

```cpp
int totalGas = 0;
int totalCost = 0;
int currentTank = 0;
int startingStation = 0;
```
* `totalGas` and `totalCost`: Used for our Global Check at the very end.
* `currentTank`: Simulates the gas in our car as we try a specific starting route.
* `startingStation`: Our current hypothesis for the correct starting index.

---

### 🔹 The Simulation Loop

```cpp
for (int i = 0; i < gas.size(); i++) {
    totalGas += gas[i];
    totalCost += cost[i];
    
    currentTank += gas[i] - cost[i];
```
* We iterate through the stations once.
* We keep running totals of gas and cost.
* We update `currentTank` by adding the gas we get at the station and subtracting the cost to leave it.

---

### 🔹 The Greedy Reset

```cpp
    if (currentTank < 0) {
        startingStation = i + 1;
        currentTank = 0;
    }
}
```
* If `currentTank` drops below zero, our car stalled!
* Our current `startingStation` is invalid. Furthermore, as explained in the Greedy logic above, *none* of the stations we visited so far could be valid starts either.
* So, we greedily set our new hypothesis `startingStation = i + 1`.
* We reset `currentTank = 0` to try again from the new start point.

---

### 🔹 The Global Check

```cpp
if (totalGas < totalCost) return -1;
return startingStation;
```
* The loop finishes. Maybe `startingStation` is `3`. Does that mean it definitely works? Not necessarily. It just means `3` didn't fail before the array ended.
* How do we know it wraps around successfully? By using the Global Check! If `totalGas >= totalCost`, mathematics guarantees that a valid starting point exists. Since the problem promises a unique solution, the `startingStation` we found *must* be the correct one!
* If `totalGas < totalCost`, we return `-1`.

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(N)**
* We iterate through the `gas` and `cost` arrays exactly once. There are no nested loops.

### 🔹 Space Complexity: **O(1)**
* We only use a few integer variables (`totalGas`, `totalCost`, `currentTank`, `startingStation`), regardless of the array sizes.
