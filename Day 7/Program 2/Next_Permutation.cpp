#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find the first decreasing element from the right
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // Step 2: Find the smallest element greater than nums[i] from the right
            int j = n - 1;
            while (j > i && nums[j] <= nums[i]) {
                j--;
            }

            // Step 3: Swap nums[i] and nums[j]
            swap(nums[i], nums[j]);
        }

        // Step 4: Reverse the suffix after index i
        reverse(nums.begin() + i + 1, nums.end());
    }
};

// Helper function to print array
void printArray(vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution obj;

    // Test case 1
    vector<int> nums1 = {1, 2, 3};
    cout << "Test 1: "; printArray(nums1);
    obj.nextPermutation(nums1);
    cout << " -> "; printArray(nums1); cout << endl;

    // Test case 2
    vector<int> nums2 = {3, 2, 1};
    cout << "Test 2: "; printArray(nums2);
    obj.nextPermutation(nums2);
    cout << " -> "; printArray(nums2); cout << endl;

    // Test case 3
    vector<int> nums3 = {1, 1, 5};
    cout << "Test 3: "; printArray(nums3);
    obj.nextPermutation(nums3);
    cout << " -> "; printArray(nums3); cout << endl;

    // Test case 4
    vector<int> nums4 = {1, 3, 5, 4, 2};
    cout << "Test 4: "; printArray(nums4);
    obj.nextPermutation(nums4);
    cout << " -> "; printArray(nums4); cout << endl;

    // Test case 5
    vector<int> nums5 = {2, 3, 1, 3, 3};
    cout << "Test 5: "; printArray(nums5);
    obj.nextPermutation(nums5);
    cout << " -> "; printArray(nums5); cout << endl;

    // Test case 6
    vector<int> nums6 = {1};
    cout << "Test 6: "; printArray(nums6);
    obj.nextPermutation(nums6);
    cout << " -> "; printArray(nums6); cout << endl;

    return 0;
}
