#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        
        // Queue will store pairs of {row, col} for rotting oranges
        queue<pair<int, int>> q;
        int freshCount = 0;

        // Step 1: Scan grid to find all initially rotten oranges and count fresh ones
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        // If there are no fresh oranges to begin with, time is 0
        if (freshCount == 0) return 0;

        int minutes = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right

        // Step 2: Multi-source BFS
        while (!q.empty()) {
            int levelSize = q.size();
            bool rottedSomethingThisMinute = false;

            // Process all oranges that are currently rotting in this minute
            for (int i = 0; i < levelSize; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                // Try to rot adjacent oranges
                for (const auto& dir : directions) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    // If neighbor is within bounds and is a fresh orange
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; // Make it rotten
                        freshCount--;     // Decrease fresh count
                        q.push({nr, nc}); // Push to queue to rot its neighbors next minute
                        rottedSomethingThisMinute = true;
                    }
                }
            }

            // If we managed to rot any fresh orange during this level, increment time
            if (rottedSomethingThisMinute) {
                minutes++;
            }
        }

        // If there are still fresh oranges left, they are isolated and can never rot
        return freshCount == 0 ? minutes : -1;
    }
};

int main() {
    Solution obj;

    // Test case 1
    vector<vector<int>> grid1 = {{2,1,1},{1,1,0},{0,1,1}};
    cout << "Test 1: -> " << obj.orangesRotting(grid1) << endl; // Expected: 4

    // Test case 2
    vector<vector<int>> grid2 = {{2,1,1},{0,1,1},{1,0,1}};
    cout << "Test 2: -> " << obj.orangesRotting(grid2) << endl; // Expected: -1

    // Test case 3
    vector<vector<int>> grid3 = {{0,2}};
    cout << "Test 3: -> " << obj.orangesRotting(grid3) << endl; // Expected: 0

    return 0;
}
