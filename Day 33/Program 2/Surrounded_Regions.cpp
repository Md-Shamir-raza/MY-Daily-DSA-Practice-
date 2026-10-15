#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        
        int m = board.size(), n = board[0].size();
        
        // Step 1: Mark all 'O' cells connected to the border as safe (using DFS)
        // Check first and last columns
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1);
        }
        // Check first and last rows
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j);
        }
        
        // Step 2: Flip all remaining 'O' to 'X' (they are surrounded)
        //         and restore all 'S' (safe) back to 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // Surrounded, capture it
                } else if (board[i][j] == 'S') {
                    board[i][j] = 'O'; // Restore safe cells
                }
            }
        }
    }
    
private:
    void dfs(vector<vector<char>>& board, int r, int c) {
        int m = board.size(), n = board[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') return;
        
        board[r][c] = 'S'; // Mark as safe
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }
};

void printBoard(const vector<vector<char>>& board) {
    for (auto& row : board) {
        for (char c : row) cout << c << " ";
        cout << endl;
    }
}

int main() {
    Solution solution;
    
    vector<vector<char>> board1 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    
    cout << "Before:" << endl;
    printBoard(board1);
    solution.solve(board1);
    cout << "After:" << endl;
    printBoard(board1);
    
    cout << endl;
    
    vector<vector<char>> board2 = {{'X'}};
    solution.solve(board2);
    cout << "Single cell: " << board2[0][0] << endl;
    
    return 0;
}
