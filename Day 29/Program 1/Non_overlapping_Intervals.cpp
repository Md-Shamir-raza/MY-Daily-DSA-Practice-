#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        // Sort intervals based on their end times
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int count = 0;
        int current_end = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < current_end) {
                // Interval overlaps, we must remove it (increment count)
                count++;
            } else {
                // No overlap, update the current end to this interval's end
                current_end = intervals[i][1];
            }
        }
        
        return count;
    }
};

int main() {
    Solution solution;
    
    vector<vector<int>> intervals1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << "Minimum intervals to remove: " << solution.eraseOverlapIntervals(intervals1) << endl;
    
    vector<vector<int>> intervals2 = {{1, 2}, {1, 2}, {1, 2}};
    cout << "Minimum intervals to remove: " << solution.eraseOverlapIntervals(intervals2) << endl;
    
    vector<vector<int>> intervals3 = {{1, 2}, {2, 3}};
    cout << "Minimum intervals to remove: " << solution.eraseOverlapIntervals(intervals3) << endl;
    
    return 0;
}
