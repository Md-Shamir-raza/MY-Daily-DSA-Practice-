#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;
        
        for (int num : numSet) {
            // Check if it's the start of a sequence (i.e., num - 1 is not in the set)
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;
                
                // Count the length of the consecutive sequence
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        
        return longestStreak;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Longest consecutive sequence length for {100, 4, 200, 1, 3, 2}: " 
         << solution.longestConsecutive(nums1) << endl;
         
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Longest consecutive sequence length for {0, 3, 7, 2, 5, 8, 4, 6, 0, 1}: " 
         << solution.longestConsecutive(nums2) << endl;
         
    return 0;
}
