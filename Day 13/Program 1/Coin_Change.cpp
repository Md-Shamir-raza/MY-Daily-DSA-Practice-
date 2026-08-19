#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] will store the minimum number of coins needed for amount i
        // Initialize with amount + 1 (which is effectively infinity for this problem)
        vector<int> dp(amount + 1, amount + 1);
        
        // Base case: 0 coins are needed to make amount 0
        dp[0] = 0;
        
        // Build up the dp array from 1 to amount
        for (int i = 1; i <= amount; i++) {
            // Try every coin for the current amount i
            for (int coin : coins) {
                // If the coin value is less than or equal to the current amount
                if (coin <= i) {
                    // Update dp[i] with the minimum of its current value 
                    // and 1 + the minimum coins needed for the remaining amount (i - coin)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        // If dp[amount] is still amount + 1, it means the amount cannot be made
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main() {
    Solution obj;
    
    // Test case 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Test 1: coins=[1,2,5], amount=11 -> " << obj.coinChange(coins1, amount1) << endl;
    
    // Test case 2
    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Test 2: coins=[2], amount=3 -> " << obj.coinChange(coins2, amount2) << endl;
    
    // Test case 3
    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Test 3: coins=[1], amount=0 -> " << obj.coinChange(coins3, amount3) << endl;

    // Test case 4
    vector<int> coins4 = {186, 419, 83, 408};
    int amount4 = 6249;
    cout << "Test 4: coins=[186,419,83,408], amount=6249 -> " << obj.coinChange(coins4, amount4) << endl;
    
    return 0;
}
