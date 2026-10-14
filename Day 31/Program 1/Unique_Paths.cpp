#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp[j] represents the number of unique paths to reach column j in the current row
        vector<int> dp(n, 1);
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }
        
        return dp[n - 1];
    }
};

int main() {
    Solution solution;
    
    cout << "Unique paths for 3x7 grid: " << solution.uniquePaths(3, 7) << endl;
    cout << "Unique paths for 3x2 grid: " << solution.uniquePaths(3, 2) << endl;
    cout << "Unique paths for 1x1 grid: " << solution.uniquePaths(1, 1) << endl;
    cout << "Unique paths for 7x3 grid: " << solution.uniquePaths(7, 3) << endl;
    
    return 0;
}
