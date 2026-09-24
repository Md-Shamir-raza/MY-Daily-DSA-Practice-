#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int prev1 = max(nums[0], nums[1]); // max loot at house 1
        int prev2 = nums[0];               // max loot at house 0
        
        for (int i = 2; i < n; i++) {
            int current = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Max money from {1, 2, 3, 1}: " << solution.rob(nums1) << endl;
    
    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << "Max money from {2, 7, 9, 3, 1}: " << solution.rob(nums2) << endl;
    
    return 0;
}
