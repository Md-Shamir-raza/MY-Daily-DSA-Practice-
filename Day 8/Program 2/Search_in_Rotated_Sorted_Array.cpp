#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Found the target
            if (nums[mid] == target) {
                return mid;
            }

            // Determine which half is sorted
            if (nums[left] <= nums[mid]) {
                // LEFT half is sorted
                if (target >= nums[left] && target < nums[mid]) {
                    // Target is in the sorted left half
                    right = mid - 1;
                } else {
                    // Target is in the right half
                    left = mid + 1;
                }
            } else {
                // RIGHT half is sorted
                if (target > nums[mid] && target <= nums[right]) {
                    // Target is in the sorted right half
                    left = mid + 1;
                } else {
                    // Target is in the left half
                    right = mid - 1;
                }
            }
        }

        return -1;  // Target not found
    }
};

int main() {
    Solution obj;

    // Test case 1
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test 1: [4,5,6,7,0,1,2], target=0 -> index " << obj.search(nums1, 0) << endl;

    // Test case 2
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test 2: [4,5,6,7,0,1,2], target=3 -> index " << obj.search(nums2, 3) << endl;

    // Test case 3
    vector<int> nums3 = {1};
    cout << "Test 3: [1], target=0 -> index " << obj.search(nums3, 0) << endl;

    // Test case 4
    vector<int> nums4 = {3, 1};
    cout << "Test 4: [3,1], target=1 -> index " << obj.search(nums4, 1) << endl;

    // Test case 5
    vector<int> nums5 = {5, 1, 3};
    cout << "Test 5: [5,1,3], target=5 -> index " << obj.search(nums5, 5) << endl;

    // Test case 6 (not rotated)
    vector<int> nums6 = {1, 2, 3, 4, 5};
    cout << "Test 6: [1,2,3,4,5], target=4 -> index " << obj.search(nums6, 4) << endl;

    return 0;
}
