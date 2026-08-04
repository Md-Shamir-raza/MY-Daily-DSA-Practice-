#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix (swap rows and columns)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// Helper function to print matrix
void printMatrix(vector<vector<int>>& matrix) {
    cout << "[" << endl;
    for (auto& row : matrix) {
        cout << "  [";
        for (int j = 0; j < row.size(); j++) {
            if (row[j] < 10) cout << " ";
            cout << row[j];
            if (j < row.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main() {
    Solution obj;

    // Test case 1: 3x3 matrix
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "Test 1 Before:" << endl;
    printMatrix(matrix1);
    obj.rotate(matrix1);
    cout << "Test 1 After (90° clockwise):" << endl;
    printMatrix(matrix1);

    // Test case 2: 4x4 matrix
    vector<vector<int>> matrix2 = {
        { 5,  1,  9, 11},
        { 2,  4,  8, 10},
        {13,  3,  6,  7},
        {15, 14, 12, 16}
    };
    cout << "\nTest 2 Before:" << endl;
    printMatrix(matrix2);
    obj.rotate(matrix2);
    cout << "Test 2 After (90° clockwise):" << endl;
    printMatrix(matrix2);

    // Test case 3: 2x2 matrix
    vector<vector<int>> matrix3 = {
        {1, 2},
        {3, 4}
    };
    cout << "\nTest 3 Before:" << endl;
    printMatrix(matrix3);
    obj.rotate(matrix3);
    cout << "Test 3 After (90° clockwise):" << endl;
    printMatrix(matrix3);

    return 0;
}
