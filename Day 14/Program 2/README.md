
# 📚 Course Schedule – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #207 – Medium)

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [a, b]` indicates that you **must** take course `b` first if you want to take course `a`.

Return `true` if you can finish all courses. Otherwise, return `false`.

Example:

```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: To take course 1 you should have finished course 0. So it is possible.

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. This is impossible.
```

---

# 🧠 Approach: Topological Sort (Kahn's Algorithm)

The key insight is:

> This problem is asking us to detect a **cycle** in a **directed graph**. If course A requires B, and B requires A, we have a cycle and can never finish.
> A standard way to process tasks with dependencies (and detect cycles) is **Topological Sorting** via Kahn's Algorithm (BFS).

### Kahn's Algorithm logic:
1. **In-degree**: Count how many prerequisites each course has (its "in-degree").
2. **Start Free**: Any course with an in-degree of `0` has no prerequisites. We can take these immediately (put them in a queue).
3. **Process & Unlock**: As we take a course, we conceptually "remove" it from the graph. This means any course that depended on it now has 1 fewer prerequisite (decrement their in-degree).
4. **Queue New**: If a dependent course's in-degree hits `0`, it's unlocked! Add it to the queue.
5. **Check Result**: If we successfully processed all `numCourses`, there was no cycle.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            adj[prerequisite].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        int coursesCompleted = 0;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            coursesCompleted++;

            for (int nextCourse : adj[current]) {
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        return coursesCompleted == numCourses;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 Initialize Graph Structures

```cpp
vector<vector<int>> adj(numCourses);
vector<int> inDegree(numCourses, 0);
```
* `adj`: An adjacency list to represent the graph. `adj[A]` will contain a list of courses that can only be taken *after* course A is finished.
* `inDegree`: An array tracking how many incoming edges (prerequisites) a node has.

---

### 🔹 Build the Graph

```cpp
for (const auto& pre : prerequisites) {
    int course = pre[0];
    int prerequisite = pre[1];
    adj[prerequisite].push_back(course);
    inDegree[course]++;
}
```
* For each pair `[course, prerequisite]`, we draw a directed edge: `prerequisite -> course`.
* We add `course` to `prerequisite`'s adjacency list.
* We increment the `inDegree` for `course` (it has one more requirement).

---

### 🔹 Find Starting Points

```cpp
queue<int> q;
for (int i = 0; i < numCourses; i++) {
    if (inDegree[i] == 0) q.push(i);
}
```
* We search for courses that have exactly `0` prerequisites. These are our starting points. We push them into our BFS queue.

---

### 🔹 Process the Queue (BFS)

```cpp
int coursesCompleted = 0;

while (!q.empty()) {
    int current = q.front();
    q.pop();
    coursesCompleted++;
```
* While we have available courses in the queue, we take one out (`current`).
* We increment our tally of `coursesCompleted`.

---

### 🔹 Unlock Dependent Courses

```cpp
    for (int nextCourse : adj[current]) {
        inDegree[nextCourse]--;
        if (inDegree[nextCourse] == 0) {
            q.push(nextCourse);
        }
    }
}
```
* We look at all courses (`nextCourse`) that depended on the `current` course we just finished.
* Since we finished it, their prerequisite count goes down (`inDegree[nextCourse]--`).
* If their count drops to `0`, they are completely unlocked! We push them into the queue to be taken next.

---

### 🔹 Check for Cycles

```cpp
return coursesCompleted == numCourses;
```
* If a graph has a cycle (A -> B -> A), neither A nor B will ever reach an `inDegree` of 0. They will never enter the queue.
* Thus, if `coursesCompleted` is exactly equal to `numCourses`, we successfully took everything. If it's less, there was a cycle.

---

# 📊 Step-by-Step Example

Input: `numCourses = 4`, `prerequisites = [[1,0], [2,1], [3,2]]` (0->1->2->3)

**Build Graph:**
- `adj` = `[[1], [2], [3], []]`
- `inDegree` = `[0, 1, 1, 1]`

**Find Starts:**
- Course `0` has `inDegree == 0`. Queue = `[0]`.

**Process Queue:**
1. Pop `0`. `coursesCompleted = 1`.
   - Neighbors of `0` is `[1]`. `inDegree[1]` goes 1 -> 0. Add `1` to Queue. Queue = `[1]`.
2. Pop `1`. `coursesCompleted = 2`.
   - Neighbors of `1` is `[2]`. `inDegree[2]` goes 1 -> 0. Add `2` to Queue. Queue = `[2]`.
3. Pop `2`. `coursesCompleted = 3`.
   - Neighbors of `2` is `[3]`. `inDegree[3]` goes 1 -> 0. Add `3` to Queue. Queue = `[3]`.
4. Pop `3`. `coursesCompleted = 4`.
   - Neighbors of `3` is `[]`. Queue = `[]`.

**Final Check:**
- `coursesCompleted (4) == numCourses (4)` -> **True!**

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(V + E)**
* `V` is the number of courses (vertices), `E` is the number of prerequisites (edges).
* Building the graph takes `O(E)`.
* Initializing the queue takes `O(V)`.
* The `while` loop processes each vertex at most once, and the inner `for` loop processes each edge at most once. Total: `O(V + E)`.

---

### 🔹 Space Complexity: **O(V + E)**
* `adj` list takes `O(V + E)` space.
* `inDegree` array takes `O(V)` space.
* `queue` takes up to `O(V)` space.

---

# ⭐ Key Concepts Learned
* **Topological Sort**: A way to linearly order vertices in a directed acyclic graph (DAG) such that for every directed edge `U -> V`, `U` comes before `V`.
* **Kahn's Algorithm**: The standard BFS-based approach for Topological Sort.
* **Cycle Detection in Directed Graphs**: Using Topological Sort to verify if a graph is a DAG (Directed Acyclic Graph).

---

# 🏆 Why This Problem Is Important
* It is the quintessential example of graph dependency problems (build systems, package managers, task scheduling).
* It frequently appears in interviews exactly as phrased here, or slightly disguised (e.g., "Alien Dictionary").
