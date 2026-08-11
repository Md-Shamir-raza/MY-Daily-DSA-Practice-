#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);   // Find leftmost
        int last = findBound(nums, target, false);    // Find rightmost
        return {first, last};
    }

private:
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                result = mid;  // Record this position

                if (isFirst) {
                    // Keep searching LEFT for the first occurrence
                    right = mid - 1;
                } else {
                    // Keep searching RIGHT for the last occurrence
                    left = mid + 1;
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};

// Helper function to print result
void printResult(vector<int>& res) {
    cout << "[" << res[0] << ", " << res[1] << "]" << endl;
}

int main() {
    Solution obj;

    // Test case 1
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    vector<int> ans1 = obj.searchRange(nums1, 8);
    cout << "Test 1: [5,7,7,8,8,10], target=8 -> "; printResult(ans1);

    // Test case 2
    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    vector<int> ans2 = obj.searchRange(nums2, 6);
    cout << "Test 2: [5,7,7,8,8,10], target=6 -> "; printResult(ans2);

    // Test case 3
    vector<int> nums3 = {};
    vector<int> ans3 = obj.searchRange(nums3, 0);
    cout << "Test 3: [], target=0 -> "; printResult(ans3);

    // Test case 4
    vector<int> nums4 = {1};
    vector<int> ans4 = obj.searchRange(nums4, 1);
    cout << "Test 4: [1], target=1 -> "; printResult(ans4);

    // Test case 5
    vector<int> nums5 = {2, 2, 2, 2, 2};
    vector<int> ans5 = obj.searchRange(nums5, 2);
    cout << "Test 5: [2,2,2,2,2], target=2 -> "; printResult(ans5);

    // Test case 6
    vector<int> nums6 = {1, 2, 3, 3, 3, 3, 4, 5, 9};
    vector<int> ans6 = obj.searchRange(nums6, 3);
    cout << "Test 6: [1,2,3,3,3,3,4,5,9], target=3 -> "; printResult(ans6);

    return 0;
}
