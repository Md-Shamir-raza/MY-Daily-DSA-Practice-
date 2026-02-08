#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Using a map to store value-index pairs
        unordered_map<int, int> hash_map;
        vector<int> result;
        
        // Traverse through the array
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if the complement exists in the map
            if (hash_map.find(complement) != hash_map.end()) {
                // If found, return the indices
                result.push_back(hash_map[complement]);
                result.push_back(i);
                return result;
            }
            
            // Store current number and its index in the map
            hash_map[nums[i]] = i;
        }
        
        // If no solution is found, return an empty vector or handle appropriately
        return result;
    }
};
  
int main(){
    Solution obj;
    //first testcase
    vector<int> nums = {3,2,4};
    int target = 6;
    vector<int> ans=obj.twoSum(nums,target);
    for(auto i:ans) {cout<<ans[i]<<" ";}cout<<endl;
    
    return 0;
}