#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Map: prefix_sum -> count of how many times this sum has occurred
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;  // Empty subarray has sum 0

        int count = 0;
        int prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Update running prefix sum
            prefixSum += nums[i];

            // Check if (prefixSum - k) exists in the map
            // If yes, there are subarrays ending at i with sum = k
            int target = prefixSum - k;
            if (prefixCount.find(target) != prefixCount.end()) {
                count += prefixCount[target];
            }

            // Store current prefix sum in the map
            prefixCount[prefixSum]++;
        }

        return count;
    }
};

int main() {
    Solution obj;

    // Test case 1
    vector<int> nums1 = {1, 1, 1};
    int k1 = 2;
    cout << "Test 1: nums=[1,1,1], k=2 -> " << obj.subarraySum(nums1, k1) << endl;

    // Test case 2
    vector<int> nums2 = {1, 2, 3};
    int k2 = 3;
    cout << "Test 2: nums=[1,2,3], k=3 -> " << obj.subarraySum(nums2, k2) << endl;

    // Test case 3 (with negatives)
    vector<int> nums3 = {1, -1, 0};
    int k3 = 0;
    cout << "Test 3: nums=[1,-1,0], k=0 -> " << obj.subarraySum(nums3, k3) << endl;

    // Test case 4
    vector<int> nums4 = {3, 4, 7, 2, -3, 1, 4, 2};
    int k4 = 7;
    cout << "Test 4: nums=[3,4,7,2,-3,1,4,2], k=7 -> " << obj.subarraySum(nums4, k4) << endl;

    // Test case 5
    vector<int> nums5 = {1};
    int k5 = 0;
    cout << "Test 5: nums=[1], k=0 -> " << obj.subarraySum(nums5, k5) << endl;

    return 0;
}
