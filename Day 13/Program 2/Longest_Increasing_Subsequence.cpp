#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        // dp[i] represents the length of the longest strictly increasing subsequence 
        // that ends at index i.
        // Initialize all DP values to 1, because the element itself forms a subsequence of length 1.
        vector<int> dp(nums.size(), 1);
        int maxLength = 1;

        // Iterate through each element in the array
        for (int i = 1; i < nums.size(); i++) {
            // Compare the current element with all previous elements
            for (int j = 0; j < i; j++) {
                // If the current element is greater than the previous element,
                // we can extend the increasing subsequence that ends at j.
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            // Update the overall maximum length found so far
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
};

int main() {
    Solution obj;

    // Test case 1
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Test 1: [10,9,2,5,3,7,101,18] -> " << obj.lengthOfLIS(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    cout << "Test 2: [0,1,0,3,2,3] -> " << obj.lengthOfLIS(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
    cout << "Test 3: [7,7,7,7,7,7,7] -> " << obj.lengthOfLIS(nums3) << endl;

    // Test case 4
    vector<int> nums4 = {1};
    cout << "Test 4: [1] -> " << obj.lengthOfLIS(nums4) << endl;

    return 0;
}
