#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // Traverse RIGHT across the top row
            for (int col = left; col <= right; col++) {
                result.push_back(matrix[top][col]);
            }
            top++;

            // Traverse DOWN along the right column
            for (int row = top; row <= bottom; row++) {
                result.push_back(matrix[row][right]);
            }
            right--;

            // Traverse LEFT across the bottom row (if still valid)
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    result.push_back(matrix[bottom][col]);
                }
                bottom--;
            }

            // Traverse UP along the left column (if still valid)
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    result.push_back(matrix[row][left]);
                }
                left++;
            }
        }

        return result;
    }
};

// Helper function to print array
void printArray(vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Helper function to print matrix
void printMatrix(vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        cout << "  [";
        for (int j = 0; j < row.size(); j++) {
            if (row[j] < 10) cout << " ";
            cout << row[j];
            if (j < row.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
}

int main() {
    Solution obj;

    // Test case 1: 3x3 matrix
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "Test 1 Matrix:" << endl;
    printMatrix(matrix1);
    vector<int> ans1 = obj.spiralOrder(matrix1);
    cout << "Spiral: "; printArray(ans1);

    // Test case 2: 3x4 matrix
    vector<vector<int>> matrix2 = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };
    cout << "\nTest 2 Matrix:" << endl;
    printMatrix(matrix2);
    vector<int> ans2 = obj.spiralOrder(matrix2);
    cout << "Spiral: "; printArray(ans2);

    // Test case 3: 4x4 matrix
    vector<vector<int>> matrix3 = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    cout << "\nTest 3 Matrix:" << endl;
    printMatrix(matrix3);
    vector<int> ans3 = obj.spiralOrder(matrix3);
    cout << "Spiral: "; printArray(ans3);

    // Test case 4: Single row
    vector<vector<int>> matrix4 = {{1, 2, 3, 4}};
    cout << "\nTest 4 Matrix:" << endl;
    printMatrix(matrix4);
    vector<int> ans4 = obj.spiralOrder(matrix4);
    cout << "Spiral: "; printArray(ans4);

    // Test case 5: Single column
    vector<vector<int>> matrix5 = {{1},{2},{3}};
    cout << "\nTest 5 Matrix:" << endl;
    printMatrix(matrix5);
    vector<int> ans5 = obj.spiralOrder(matrix5);
    cout << "Spiral: "; printArray(ans5);

    return 0;
}
