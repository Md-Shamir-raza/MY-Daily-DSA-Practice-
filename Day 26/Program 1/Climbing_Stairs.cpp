#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        
        int prev1 = 2; // ways to reach step 2
        int prev2 = 1; // ways to reach step 1
        
        for (int i = 3; i <= n; i++) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};

int main() {
    Solution solution;
    
    cout << "Ways to climb 2 stairs: " << solution.climbStairs(2) << endl;
    cout << "Ways to climb 3 stairs: " << solution.climbStairs(3) << endl;
    cout << "Ways to climb 5 stairs: " << solution.climbStairs(5) << endl;
    cout << "Ways to climb 10 stairs: " << solution.climbStairs(10) << endl;
    
    return 0;
}
