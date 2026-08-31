#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create adjacency list for the graph: adj[u] = {{v, w}, ...}
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }

        // Min-heap for Dijkstra's algorithm. Stores pairs of {time_to_reach_node, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Array to store the minimum time to reach each node. Initialize with infinity.
        vector<int> minTime(n + 1, 1e9);

        // Start from node k
        pq.push({0, k});
        minTime[k] = 0;

        while (!pq.empty()) {
            int currentTime = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // If we found a longer path, ignore it (stale entry in priority queue)
            if (currentTime > minTime[u]) {
                continue;
            }

            // Explore all neighbors
            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                // Relaxation step: if the new path is shorter, update and push to queue
                if (currentTime + weight < minTime[v]) {
                    minTime[v] = currentTime + weight;
                    pq.push({minTime[v], v});
                }
            }
        }

        // Find the maximum time among all nodes
        int maxDelay = 0;
        for (int i = 1; i <= n; i++) {
            if (minTime[i] == 1e9) {
                return -1; // A node is unreachable
            }
            maxDelay = max(maxDelay, minTime[i]);
        }

        return maxDelay;
    }
};

int main() {
    Solution obj;

    // Test case 1
    vector<vector<int>> times1 = {{2,1,1},{2,3,1},{3,4,1}};
    int n1 = 4, k1 = 2;
    cout << "Test 1: -> " << obj.networkDelayTime(times1, n1, k1) << endl; // Expected: 2

    // Test case 2
    vector<vector<int>> times2 = {{1,2,1}};
    int n2 = 2, k2 = 1;
    cout << "Test 2: -> " << obj.networkDelayTime(times2, n2, k2) << endl; // Expected: 1

    // Test case 3
    vector<vector<int>> times3 = {{1,2,1}};
    int n3 = 2, k3 = 2;
    cout << "Test 3: -> " << obj.networkDelayTime(times3, n3, k3) << endl; // Expected: -1

    return 0;
}
