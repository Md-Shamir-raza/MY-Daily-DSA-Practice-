#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        // Sort by end coordinate
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int arrows = 1;
        int currentEnd = points[0][1];
        
        for (int i = 1; i < points.size(); i++) {
            // If the next balloon starts after the current arrow's reach,
            // we need a new arrow
            if (points[i][0] > currentEnd) {
                arrows++;
                currentEnd = points[i][1];
            }
            // Otherwise, this balloon is already burst by the current arrow
        }
        
        return arrows;
    }
};

int main() {
    Solution solution;
    
    vector<vector<int>> points1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << "Minimum arrows for [[10,16],[2,8],[1,6],[7,12]]: " 
         << solution.findMinArrowShots(points1) << endl;
    
    vector<vector<int>> points2 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    cout << "Minimum arrows for [[1,2],[3,4],[5,6],[7,8]]: " 
         << solution.findMinArrowShots(points2) << endl;
    
    vector<vector<int>> points3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << "Minimum arrows for [[1,2],[2,3],[3,4],[4,5]]: " 
         << solution.findMinArrowShots(points3) << endl;
    
    return 0;
}
