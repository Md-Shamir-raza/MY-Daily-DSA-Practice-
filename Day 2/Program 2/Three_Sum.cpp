#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Fix one element and use two pointers for the rest
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // If the smallest possible sum is > 0, no solution exists
            if (nums[i] > 0) break;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    // Found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for left pointer
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicates for right pointer
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    // Move both pointers
                    left++;
                    right--;
                } else if (sum < 0) {
                    // Sum is too small, move left pointer to increase sum
                    left++;
                } else {
                    // Sum is too large, move right pointer to decrease sum
                    right--;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution obj;

    // Test case 1
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    cout << "Test 1: " << endl;
    vector<vector<int>> ans1 = obj.threeSum(nums1);
    for (auto& triplet : ans1) {
        cout << "[";
        for (int j = 0; j < triplet.size(); j++) {
            cout << triplet[j];
            if (j < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    // Test case 2
    vector<int> nums2 = {0, 1, 1};
    cout << "\nTest 2: " << endl;
    vector<vector<int>> ans2 = obj.threeSum(nums2);
    if (ans2.empty()) cout << "No triplets found" << endl;

    // Test case 3
    vector<int> nums3 = {0, 0, 0};
    cout << "\nTest 3: " << endl;
    vector<vector<int>> ans3 = obj.threeSum(nums3);
    for (auto& triplet : ans3) {
        cout << "[";
        for (int j = 0; j < triplet.size(); j++) {
            cout << triplet[j];
            if (j < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
