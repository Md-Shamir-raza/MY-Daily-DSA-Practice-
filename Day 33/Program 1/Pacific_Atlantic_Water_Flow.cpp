#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        // BFS from Pacific borders (top row and left column)
        queue<pair<int, int>> pacQueue, atlQueue;
        
        for (int i = 0; i < m; i++) {
            pacQueue.push({i, 0});
            pacific[i][0] = true;
            atlQueue.push({i, n - 1});
            atlantic[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            pacQueue.push({0, j});
            pacific[0][j] = true;
            atlQueue.push({m - 1, j});
            atlantic[m - 1][j] = true;
        }
        
        bfs(heights, pacQueue, pacific);
        bfs(heights, atlQueue, atlantic);
        
        // Collect cells that can reach both oceans
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
    
private:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, 
             vector<vector<bool>>& visited) {
        int m = heights.size(), n = heights[0].size();
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n 
                    && !visited[nr][nc] 
                    && heights[nr][nc] >= heights[r][c]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
};

int main() {
    Solution solution;
    
    vector<vector<int>> heights1 = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };
    
    vector<vector<int>> result = solution.pacificAtlantic(heights1);
    cout << "Cells that can reach both oceans:" << endl;
    for (auto& cell : result) {
        cout << "[" << cell[0] << ", " << cell[1] << "] ";
    }
    cout << endl;
    
    vector<vector<int>> heights2 = {{1}};
    result = solution.pacificAtlantic(heights2);
    cout << "Single cell: [" << result[0][0] << ", " << result[0][1] << "]" << endl;
    
    return 0;
}
