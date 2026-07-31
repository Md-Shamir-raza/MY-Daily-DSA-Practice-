#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        // Step 1: Calculate prefix products
        // answer[i] = product of all elements to the LEFT of i
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // Step 2: Multiply by suffix products
        // answer[i] *= product of all elements to the RIGHT of i
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
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
    vector<int> nums1 = {1, 2, 3, 4};
    cout << "Test 1 Input:  "; printArray(nums1);
    vector<int> ans1 = obj.productExceptSelf(nums1);
    cout << "Test 1 Output: "; printArray(ans1);

    // Test case 2
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    cout << "\nTest 2 Input:  "; printArray(nums2);
    vector<int> ans2 = obj.productExceptSelf(nums2);
    cout << "Test 2 Output: "; printArray(ans2);

    // Test case 3
    vector<int> nums3 = {2, 3, 4, 5};
    cout << "\nTest 3 Input:  "; printArray(nums3);
    vector<int> ans3 = obj.productExceptSelf(nums3);
    cout << "Test 3 Output: "; printArray(ans3);

    // Test case 4
    vector<int> nums4 = {0, 0};
    cout << "\nTest 4 Input:  "; printArray(nums4);
    vector<int> ans4 = obj.productExceptSelf(nums4);
    cout << "Test 4 Output: "; printArray(ans4);

    return 0;
}
