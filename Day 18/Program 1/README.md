
# 📶 Network Delay Time – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #743 – Medium)

You are given a network of `n` nodes, labeled from `1` to `n`. You are also given `times`, a list of travel times as directed edges `times[i] = (ui, vi, wi)`, where `ui` is the source node, `vi` is the target node, and `wi` is the time it takes for a signal to travel from source to target.

We will send a signal from a given node `k`. Return the **minimum time** it takes for all the `n` nodes to receive the signal. If it is impossible for all the `n` nodes to receive the signal, return `-1`.

Example:
```
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
```

---

# 🧠 Approach: Dijkstra's Algorithm

The key insight is:

> We need to find the **Shortest Path** from a single source node `k` to *all* other nodes in a directed, weighted graph.
> The time it takes for the signal to reach everyone is simply the *longest* of all these shortest paths (because the signal travels simultaneously along all edges).
> The standard algorithm for Single-Source Shortest Path on a graph with non-negative weights is **Dijkstra's Algorithm**.

### Dijkstra's Algorithm in a nutshell:
1. Keep track of the `minTime` to reach every node (initialize to Infinity).
2. Start at node `k` with time `0`. Use a Min-Heap (Priority Queue) to always process the node we can reach the fastest.
3. For the current node, look at its neighbors. If `current_time + edge_weight < minTime[neighbor]`, update the neighbor's time and push it into the heap.
4. Repeat until the heap is empty.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> minTime(n + 1, 1e9);

        pq.push({0, k});
        minTime[k] = 0;

        while (!pq.empty()) {
            int currentTime = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (currentTime > minTime[u]) continue;

            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (currentTime + weight < minTime[v]) {
                    minTime[v] = currentTime + weight;
                    pq.push({minTime[v], v});
                }
            }
        }

        int maxDelay = 0;
        for (int i = 1; i <= n; i++) {
            if (minTime[i] == 1e9) return -1;
            maxDelay = max(maxDelay, minTime[i]);
        }

        return maxDelay;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 Step 1: Build the Graph

```cpp
vector<vector<pair<int, int>>> adj(n + 1);
for (const auto& time : times) {
    adj[time[0]].push_back({time[1], time[2]});
}
```
* The nodes are 1-indexed, so we create an adjacency list of size `n + 1`.
* `adj[u]` stores a list of pairs `{v, weight}` representing an edge from `u` to `v` with a specific travel time.

---

### 🔹 Step 2: Initialize Dijkstra Data Structures

```cpp
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> minTime(n + 1, 1e9);
```
* **Min-Heap**: Stores pairs of `{time_to_reach_node, node_id}`. It's crucial that `time` is the *first* element of the pair so the min-heap sorts by time!
* **Distances Array (`minTime`)**: Stores the absolute shortest time to reach every node. Initialized to a very large number `1e9` (Infinity).

---

### 🔹 Step 3: Start Node

```cpp
pq.push({0, k});
minTime[k] = 0;
```
* We start at node `k`. It takes `0` time to reach `k` from `k`. We push this initial state into the heap.

---

### 🔹 Step 4: Process the Min-Heap

```cpp
while (!pq.empty()) {
    int currentTime = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    
    if (currentTime > minTime[u]) continue;
```
* Pop the node we can reach the fastest.
* **Optimization**: A node might be pushed into the queue multiple times if we find progressively shorter paths to it. If `currentTime > minTime[u]`, it means we already found an even shorter path earlier, so this is a "stale" queue entry. Skip it.

---

### 🔹 Step 5: Relaxation (Updating Neighbors)

```cpp
    for (const auto& edge : adj[u]) {
        int v = edge.first;
        int weight = edge.second;

        if (currentTime + weight < minTime[v]) {
            minTime[v] = currentTime + weight;
            pq.push({minTime[v], v});
        }
    }
}
```
* We look at all neighbors `v` of the current node `u`.
* If traveling to `v` *through* `u` is faster than any path to `v` we've found so far (`currentTime + weight < minTime[v]`), we update `minTime[v]` and push the new path into the heap to be explored later.

---

### 🔹 Step 6: Find Maximum Time

```cpp
int maxDelay = 0;
for (int i = 1; i <= n; i++) {
    if (minTime[i] == 1e9) return -1;
    maxDelay = max(maxDelay, minTime[i]);
}
return maxDelay;
```
* The signal is sent simultaneously. The total time for *everyone* to get it is simply the time it takes for the *last* person to get it.
* We loop through `minTime`. If any node is still at `1e9` (Infinity), it means it was completely unreachable (disconnected graph). Return `-1`.
* Otherwise, we find the maximum time and return it.

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O((V + E) log V)**
* `V` is the number of vertices (nodes), `E` is the number of edges (`times`).
* In the worst case, every edge gets processed and pushes to the priority queue. Priority queue operations take `O(log V)`.
* This is the standard time complexity for Dijkstra's Algorithm using a binary heap.

### 🔹 Space Complexity: **O(V + E)**
* The adjacency list takes `O(V + E)` space.
* The Priority Queue and `minTime` array take `O(V)` space.
