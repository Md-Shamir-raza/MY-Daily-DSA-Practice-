#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Dutch National Flag Algorithm
        int low = 0;              // boundary for 0s
        int mid = 0;              // current element pointer
        int high = nums.size() - 1; // boundary for 2s

        while (mid <= high) {
            if (nums[mid] == 0) {
                // Swap with low boundary and move both forward
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                // 1 is in correct position, just move mid
                mid++;
            } else {
                // nums[mid] == 2, swap with high boundary
                swap(nums[mid], nums[high]);
                high--;
                // Don't increment mid — need to check swapped element
            }
        }
    }
};

// Helper function to print array
void printArray(vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution obj;

    // Test case 1
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    cout << "Test 1 Before: "; printArray(nums1);
    obj.sortColors(nums1);
    cout << "Test 1 After:  "; printArray(nums1);

    // Test case 2
    vector<int> nums2 = {2, 0, 1};
    cout << "\nTest 2 Before: "; printArray(nums2);
    obj.sortColors(nums2);
    cout << "Test 2 After:  "; printArray(nums2);

    // Test case 3
    vector<int> nums3 = {0};
    cout << "\nTest 3 Before: "; printArray(nums3);
    obj.sortColors(nums3);
    cout << "Test 3 After:  "; printArray(nums3);

    // Test case 4
    vector<int> nums4 = {1, 2, 0, 1, 2, 0, 0, 2, 1};
    cout << "\nTest 4 Before: "; printArray(nums4);
    obj.sortColors(nums4);
    cout << "Test 4 After:  "; printArray(nums4);

    return 0;
}
