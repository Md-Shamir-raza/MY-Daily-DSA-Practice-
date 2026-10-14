#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        
        // Space-optimized: use two 1D arrays instead of a 2D matrix
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = prev[j - 1] + 1;
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            swap(prev, curr);
            fill(curr.begin(), curr.end(), 0);
        }
        
        return prev[n];
    }
};

int main() {
    Solution solution;
    
    cout << "LCS of 'abcde' and 'ace': " 
         << solution.longestCommonSubsequence("abcde", "ace") << endl;
    
    cout << "LCS of 'abc' and 'abc': " 
         << solution.longestCommonSubsequence("abc", "abc") << endl;
    
    cout << "LCS of 'abc' and 'def': " 
         << solution.longestCommonSubsequence("abc", "def") << endl;
    
    cout << "LCS of 'oxcpqrsvwf' and 'shmtulqrypy': " 
         << solution.longestCommonSubsequence("oxcpqrsvwf", "shmtulqrypy") << endl;
    
    return 0;
}
