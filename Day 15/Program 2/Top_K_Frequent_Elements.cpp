#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count the frequency of each element using a hash map
        unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }

        // Step 2: Use a Min-Heap to keep the top k frequent elements
        // The priority_queue will store pairs of (frequency, element)
        // By default, pairs are compared by their first element (frequency)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto& pair : countMap) {
            int element = pair.first;
            int frequency = pair.second;
            
            // Push the pair into the heap
            minHeap.push({frequency, element});
            
            // If the heap size exceeds k, pop the element with the smallest frequency
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Step 3: Extract the k elements from the heap
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};

// Helper function to print a vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution obj;

    // Test case 1
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    cout << "Test 1: nums=[1,1,1,2,2,3], k=2 -> ";
    printVector(obj.topKFrequent(nums1, k1));

    // Test case 2
    vector<int> nums2 = {1};
    int k2 = 1;
    cout << "Test 2: nums=[1], k=1 -> ";
    printVector(obj.topKFrequent(nums2, k2));
    
    // Test case 3
    vector<int> nums3 = {4, 1, -1, 2, -1, 2, 3};
    int k3 = 2;
    cout << "Test 3: nums=[4,1,-1,2,-1,2,3], k=2 -> ";
    printVector(obj.topKFrequent(nums3, k3));

    return 0;
}
