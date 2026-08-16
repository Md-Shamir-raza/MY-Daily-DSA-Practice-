#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Start backtracking from index 0
        backtrack(candidates, target, 0, current, result);
        
        return result;
    }

private:
    void backtrack(const vector<int>& candidates, int remain, int start, vector<int>& current, vector<vector<int>>& result) {
        // Base Case 1: If remainder is exactly 0, we found a valid combination
        if (remain == 0) {
            result.push_back(current);
            return;
        }
        
        // Base Case 2: If remainder is less than 0, we exceeded the target, stop this path
        if (remain < 0) {
            return;
        }
        
        // Iterate through candidates starting from 'start' index to avoid duplicate combinations
        for (int i = start; i < candidates.size(); i++) {
            // 1. Choose
            current.push_back(candidates[i]);
            
            // 2. Explore: Notice we pass 'i' as the start, NOT 'i + 1', because we can reuse the same element
            backtrack(candidates, remain - candidates[i], i, current, result);
            
            // 3. Un-choose (Backtrack)
            current.pop_back();
        }
    }
};

// Helper function to print combinations
void printCombinations(const vector<vector<int>>& combs) {
    cout << "[" << endl;
    for (const auto& c : combs) {
        cout << "  [";
        for (int i = 0; i < c.size(); i++) {
            cout << c[i];
            if (i < c.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main() {
    Solution obj;
    
    // Test case 1
    vector<int> candidates1 = {2, 3, 6, 7};
    int target1 = 7;
    cout << "Test 1: candidates=[2,3,6,7], target=7 ->" << endl;
    vector<vector<int>> ans1 = obj.combinationSum(candidates1, target1);
    printCombinations(ans1);
    
    // Test case 2
    vector<int> candidates2 = {2, 3, 5};
    int target2 = 8;
    cout << "\nTest 2: candidates=[2,3,5], target=8 ->" << endl;
    vector<vector<int>> ans2 = obj.combinationSum(candidates2, target2);
    printCombinations(ans2);
    
    // Test case 3
    vector<int> candidates3 = {2};
    int target3 = 1;
    cout << "\nTest 3: candidates=[2], target=1 ->" << endl;
    vector<vector<int>> ans3 = obj.combinationSum(candidates3, target3);
    printCombinations(ans3);
    
    return 0;
}
