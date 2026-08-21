#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap to store the top k largest elements
        // priority_queue<Type, Container, Compare>
        // greater<int> makes it a min-heap (smallest element at the top)
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            
            // If the heap size exceeds k, pop the smallest element
            // This ensures the heap only keeps the k largest elements seen so far
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // The top of the min-heap is the kth largest element
        return minHeap.top();
    }
};

int main() {
    Solution obj;

    // Test case 1
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    cout << "Test 1: nums=[3,2,1,5,6,4], k=2 -> " << obj.findKthLargest(nums1, k1) << endl;

    // Test case 2
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    cout << "Test 2: nums=[3,2,3,1,2,4,5,5,6], k=4 -> " << obj.findKthLargest(nums2, k2) << endl;

    // Test case 3
    vector<int> nums3 = {1};
    int k3 = 1;
    cout << "Test 3: nums=[1], k=1 -> " << obj.findKthLargest(nums3, k3) << endl;

    // Test case 4
    vector<int> nums4 = {-1, -1};
    int k4 = 2;
    cout << "Test 4: nums=[-1,-1], k=2 -> " << obj.findKthLargest(nums4, k4) << endl;

    return 0;
}
