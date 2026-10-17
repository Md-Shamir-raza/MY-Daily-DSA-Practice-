#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        
        // DP approach: the number of 1-bits in i is equal to
        // the number of 1-bits in i >> 1 (i / 2) plus the last bit (i & 1)
        for (int i = 1; i <= n; i++) {
            result[i] = result[i >> 1] + (i & 1);
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    vector<int> result1 = solution.countBits(2);
    cout << "countBits(2): ";
    for (int val : result1) cout << val << " ";
    cout << endl;
    
    vector<int> result2 = solution.countBits(5);
    cout << "countBits(5): ";
    for (int val : result2) cout << val << " ";
    cout << endl;
    
    vector<int> result3 = solution.countBits(8);
    cout << "countBits(8): ";
    for (int val : result3) cout << val << " ";
    cout << endl;
    
    return 0;
}
