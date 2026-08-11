#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;  // Farthest index we can reach

        for (int i = 0; i < nums.size(); i++) {
            // If current index is beyond our reach, we're stuck
            if (i > maxReach) {
                return false;
            }

            // Update the farthest we can reach from this position
            maxReach = max(maxReach, i + nums[i]);

            // Early exit: if we can already reach the end
            if (maxReach >= nums.size() - 1) {
                return true;
            }
        }

        return true;
    }
};

int main() {
    Solution obj;

    // Test case 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Test 1: [2,3,1,1,4] -> " << (obj.canJump(nums1) ? "true" : "false") << endl;

    // Test case 2
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Test 2: [3,2,1,0,4] -> " << (obj.canJump(nums2) ? "true" : "false") << endl;

    // Test case 3
    vector<int> nums3 = {0};
    cout << "Test 3: [0] -> " << (obj.canJump(nums3) ? "true" : "false") << endl;

    // Test case 4
    vector<int> nums4 = {2, 0, 0};
    cout << "Test 4: [2,0,0] -> " << (obj.canJump(nums4) ? "true" : "false") << endl;

    // Test case 5
    vector<int> nums5 = {1, 1, 1, 1, 1};
    cout << "Test 5: [1,1,1,1,1] -> " << (obj.canJump(nums5) ? "true" : "false") << endl;

    // Test case 6
    vector<int> nums6 = {5, 0, 0, 0, 0, 0};
    cout << "Test 6: [5,0,0,0,0,0] -> " << (obj.canJump(nums6) ? "true" : "false") << endl;

    // Test case 7
    vector<int> nums7 = {1, 0, 1, 0};
    cout << "Test 7: [1,0,1,0] -> " << (obj.canJump(nums7) ? "true" : "false") << endl;

    return 0;
}
