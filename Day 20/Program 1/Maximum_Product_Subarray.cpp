#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;
        
        for (size_t i = 1; i < nums.size(); ++i) {
            int curr = nums[i];
            int temp_max = max(curr, max(max_so_far * curr, min_so_far * curr));
            min_so_far = min(curr, min(max_so_far * curr, min_so_far * curr));
            max_so_far = temp_max;
            
            result = max(result, max_so_far);
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {2, 3, -2, 4};
    cout << "Maximum product of {2, 3, -2, 4} is: " << solution.maxProduct(nums1) << endl;

    vector<int> nums2 = {-2, 0, -1};
    cout << "Maximum product of {-2, 0, -1} is: " << solution.maxProduct(nums2) << endl;

    return 0;
}
