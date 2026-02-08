#include<iostream>
#include<iomanip>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0;
        int maxsum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            maxsum=max(currsum,maxsum);
            if(currsum<0) currsum=0;
        }
        return maxsum;
        
    }
};
int main(){
    vector<int> nums={7,89,9,8,7,-99,2,-45};

    Solution obj;
    int max=obj.maxSubArray(nums);
    cout<< "The Maximum of subarray is : "<<max<<endl;
    return 0;
}