#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        
        for (int num : nums) {
            // `ones` tracks bits that have appeared exactly 1 time (mod 3)
            // `twos` tracks bits that have appeared exactly 2 times (mod 3)
            
            // Step 1: Update `ones`
            // We XOR `ones` with `num` to add the bits of `num` to `ones`.
            // However, we only want to keep bits in `ones` if they are NOT already in `twos`.
            // So we use `& ~twos` to clear any bits that have now appeared 3 times.
            ones = (ones ^ num) & ~twos;
            
            // Step 2: Update `twos`
            // We XOR `twos` with `num` to add the bits of `num` to `twos`.
            // However, we only want to keep bits in `twos` if they are NOT already in `ones`.
            // Because if a bit is in `ones`, it means it just appeared for the 1st time, not the 2nd.
            twos = (twos ^ num) & ~ones;
        }
        
        // At the end, `ones` will hold the number that appeared exactly once.
        return ones;
    }
};

int main() {
    Solution obj;

    // Test case 1
    vector<int> nums1 = {2, 2, 3, 2};
    cout << "Test 1: [2,2,3,2] -> " << obj.singleNumber(nums1) << endl; // Expected: 3

    // Test case 2
    vector<int> nums2 = {0, 1, 0, 1, 0, 1, 99};
    cout << "Test 2: [0,1,0,1,0,1,99] -> " << obj.singleNumber(nums2) << endl; // Expected: 99

    return 0;
}
