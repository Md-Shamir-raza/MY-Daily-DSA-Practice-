#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            // Calculate the area formed between the two lines
            int width = right - left;
            int h = min(height[left], height[right]);
            int area = width * h;

            // Update maximum area
            maxWater = max(maxWater, area);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};

int main() {
    Solution obj;

    // Test case 1
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Test 1 - Max Water: " << obj.maxArea(height1) << endl;

    // Test case 2
    vector<int> height2 = {1, 1};
    cout << "Test 2 - Max Water: " << obj.maxArea(height2) << endl;

    // Test case 3
    vector<int> height3 = {4, 3, 2, 1, 4};
    cout << "Test 3 - Max Water: " << obj.maxArea(height3) << endl;

    return 0;
}
