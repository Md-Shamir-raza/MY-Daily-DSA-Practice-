#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        
        backtrack(nums, current, used, result);
        
        return result;
    }

private:
    void backtrack(const vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& result) {
        // Base Case: If the current permutation is the same size as nums, we found a valid permutation
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        // Try adding each number to the current permutation
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue; // Skip if the number is already in the current permutation
            
            // 1. Choose: add nums[i] to the current permutation and mark as used
            current.push_back(nums[i]);
            used[i] = true;
            
            // 2. Explore: recursively build the rest of the permutation
            backtrack(nums, current, used, result);
            
            // 3. Un-choose (Backtrack): remove nums[i] and mark as unused to try the next possibility
            current.pop_back();
            used[i] = false;
        }
    }
};

// Helper function to print permutations
void printPermutations(const vector<vector<int>>& perms) {
    cout << "[" << endl;
    for (const auto& p : perms) {
        cout << "  [";
        for (int i = 0; i < p.size(); i++) {
            cout << p[i];
            if (i < p.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main() {
    Solution obj;
    
    // Test case 1
    vector<int> nums1 = {1, 2, 3};
    cout << "Test 1: [1, 2, 3] ->" << endl;
    vector<vector<int>> ans1 = obj.permute(nums1);
    printPermutations(ans1);
    
    // Test case 2
    vector<int> nums2 = {0, 1};
    cout << "\nTest 2: [0, 1] ->" << endl;
    vector<vector<int>> ans2 = obj.permute(nums2);
    printPermutations(ans2);
    
    // Test case 3
    vector<int> nums3 = {1};
    cout << "\nTest 3: [1] ->" << endl;
    vector<vector<int>> ans3 = obj.permute(nums3);
    printPermutations(ans3);
    
    return 0;
}
