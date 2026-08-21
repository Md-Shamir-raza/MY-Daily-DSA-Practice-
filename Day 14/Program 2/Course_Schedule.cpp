#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create adjacency list and in-degree array
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        // Build the graph
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            adj[prerequisite].push_back(course);
            inDegree[course]++;
        }

        // Queue for courses with 0 prerequisites (in-degree == 0)
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int coursesCompleted = 0;

        // Process courses
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            coursesCompleted++;

            // Check all courses that depend on the current course
            for (int nextCourse : adj[current]) {
                inDegree[nextCourse]--; // We completed a prerequisite
                // If all prerequisites are met, add to queue
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // If we were able to complete all courses, there are no cycles
        return coursesCompleted == numCourses;
    }
};

int main() {
    Solution obj;

    // Test case 1
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "Test 1: numCourses = 2, pre = [[1,0]] -> " 
         << (obj.canFinish(numCourses1, prerequisites1) ? "true" : "false") << endl;

    // Test case 2
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << "Test 2: numCourses = 2, pre = [[1,0],[0,1]] -> " 
         << (obj.canFinish(numCourses2, prerequisites2) ? "true" : "false") << endl;

    // Test case 3
    int numCourses3 = 4;
    vector<vector<int>> prerequisites3 = {{1, 0}, {2, 1}, {3, 2}};
    cout << "Test 3: numCourses = 4, pre = [[1,0],[2,1],[3,2]] -> " 
         << (obj.canFinish(numCourses3, prerequisites3) ? "true" : "false") << endl;

    return 0;
}
