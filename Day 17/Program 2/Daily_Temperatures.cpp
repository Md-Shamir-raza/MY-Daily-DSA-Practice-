#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0); // Initialize result with 0s
        
        // Stack stores indices of temperatures, NOT the temperatures themselves
        stack<int> st;

        for (int i = 0; i < n; i++) {
            // While stack is not empty and current temp is greater than the temp at the index on top of stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                // We found a warmer day for the index at the top of the stack!
                int prevIndex = st.top();
                st.pop();
                // Calculate the number of days difference
                result[prevIndex] = i - prevIndex;
            }
            // Push current index onto stack to wait for a warmer day
            st.push(i);
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
    vector<int> temps1 = {73, 74, 75, 71, 69, 72, 76, 73};
    cout << "Test 1: [73,74,75,71,69,72,76,73] -> ";
    printVector(obj.dailyTemperatures(temps1));

    // Test case 2
    vector<int> temps2 = {30, 40, 50, 60};
    cout << "Test 2: [30,40,50,60] -> ";
    printVector(obj.dailyTemperatures(temps2));

    // Test case 3
    vector<int> temps3 = {30, 60, 90};
    cout << "Test 3: [30,60,90] -> ";
    printVector(obj.dailyTemperatures(temps3));
    
    // Test case 4
    vector<int> temps4 = {90, 80, 70};
    cout << "Test 4: [90,80,70] -> ";
    printVector(obj.dailyTemperatures(temps4));

    return 0;
}
