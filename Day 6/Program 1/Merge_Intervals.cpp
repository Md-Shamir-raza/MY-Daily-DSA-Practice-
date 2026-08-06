#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        for (auto& interval : intervals) {
            // If merged is empty OR current interval doesn't overlap with last
            if (merged.empty() || merged.back()[1] < interval[0]) {
                // No overlap — add as a new interval
                merged.push_back(interval);
            } else {
                // Overlap — merge by extending the end of last interval
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};

// Helper function to print intervals
void printIntervals(vector<vector<int>>& intervals) {
    cout << "[";
    for (int i = 0; i < intervals.size(); i++) {
        cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]";
        if (i < intervals.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution obj;

    // Test case 1
    vector<vector<int>> intervals1 = {{1,3},{2,6},{8,10},{15,18}};
    cout << "Test 1 Input:  "; printIntervals(intervals1);
    vector<vector<int>> ans1 = obj.merge(intervals1);
    cout << "Test 1 Output: "; printIntervals(ans1);

    // Test case 2
    vector<vector<int>> intervals2 = {{1,4},{4,5}};
    cout << "\nTest 2 Input:  "; printIntervals(intervals2);
    vector<vector<int>> ans2 = obj.merge(intervals2);
    cout << "Test 2 Output: "; printIntervals(ans2);

    // Test case 3
    vector<vector<int>> intervals3 = {{1,4},{0,4}};
    cout << "\nTest 3 Input:  "; printIntervals(intervals3);
    vector<vector<int>> ans3 = obj.merge(intervals3);
    cout << "Test 3 Output: "; printIntervals(ans3);

    // Test case 4
    vector<vector<int>> intervals4 = {{1,4},{2,3}};
    cout << "\nTest 4 Input:  "; printIntervals(intervals4);
    vector<vector<int>> ans4 = obj.merge(intervals4);
    cout << "Test 4 Output: "; printIntervals(ans4);

    // Test case 5
    vector<vector<int>> intervals5 = {{6,8},{1,9},{2,4},{4,7}};
    cout << "\nTest 5 Input:  "; printIntervals(intervals5);
    vector<vector<int>> ans5 = obj.merge(intervals5);
    cout << "Test 5 Output: "; printIntervals(ans5);

    return 0;
}
