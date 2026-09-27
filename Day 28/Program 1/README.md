# Clone Graph (LeetCode #133)

## 📝 Problem Description
Given a reference of a node in a **connected** undirected graph.
Return a **deep copy** (clone) of the graph.
Each node in the graph contains a value (`int`) and a list (`List[Node]`) of its neighbors.

**Example 1:**
- **Input:** adjList = [[2,4],[1,3],[2,4],[1,3]]
- **Output:** [[2,4],[1,3],[2,4],[1,3]]
- **Explanation:** There are 4 nodes in the graph. The graph represents an undirected square.

## 💡 Solution Approach
To create a deep copy of the graph, we must traverse it using either Depth-First Search (DFS) or Breadth-First Search (BFS). 
We use an `unordered_map` (hash map) to keep track of nodes we have already visited and cloned. The keys are the original nodes, and the values are the cloned nodes. 
As we traverse, if we encounter a node that is already in our map, we simply return the cloned counterpart. If not, we create a new node, store it in the map, and recursively clone all its neighbors.

## ⏱ Time & Space Complexity
- **Time Complexity:** O(V + E) where V is the number of vertices (nodes) and E is the number of edges. We visit each node and each edge exactly once.
- **Space Complexity:** O(V) to store the visited nodes in the hash map and the recursion stack during the DFS traversal.
