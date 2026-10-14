#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        
        // Find the maximum frequency
        int maxFreq = *max_element(freq.begin(), freq.end());
        
        // Count how many tasks have the maximum frequency
        int maxCount = 0;
        for (int f : freq) {
            if (f == maxFreq) maxCount++;
        }
        
        // The minimum intervals needed is:
        // (maxFreq - 1) * (n + 1) + maxCount
        // But it can't be less than the total number of tasks
        int result = max((int)tasks.size(), (maxFreq - 1) * (n + 1) + maxCount);
        
        return result;
    }
};

int main() {
    Solution solution;
    
    vector<char> tasks1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << "Least interval for [A,A,A,B,B,B] with n=2: " 
         << solution.leastInterval(tasks1, 2) << endl;
    
    vector<char> tasks2 = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << "Least interval for [A,A,A,B,B,B] with n=0: " 
         << solution.leastInterval(tasks2, 0) << endl;
    
    vector<char> tasks3 = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    cout << "Least interval for [A,A,A,A,A,A,B,C,D,E,F,G] with n=2: " 
         << solution.leastInterval(tasks3, 2) << endl;
    
    return 0;
}
