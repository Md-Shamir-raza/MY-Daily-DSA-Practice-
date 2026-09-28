#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();
        
        // 1. Add all intervals ending before newInterval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        
        // 2. Merge all overlapping intervals to one giant newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);
        
        // 3. Add all the remaining intervals
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};

void printIntervals(const vector<vector<int>>& intervals) {
    cout << "[";
    for (int i = 0; i < intervals.size(); i++) {
        cout << "[" << intervals[i][0] << ", " << intervals[i][1] << "]";
        if (i != intervals.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    vector<vector<int>> intervals1 = {{1, 3}, {6, 9}};
    vector<int> newInterval1 = {2, 5};
    cout << "Merged intervals: ";
    printIntervals(solution.insert(intervals1, newInterval1));
    
    vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval2 = {4, 8};
    cout << "Merged intervals: ";
    printIntervals(solution.insert(intervals2, newInterval2));
    
    return 0;
}
