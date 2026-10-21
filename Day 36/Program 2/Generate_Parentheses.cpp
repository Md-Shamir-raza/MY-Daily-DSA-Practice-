#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
    
private:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        // Base case: if the current string has 2*n characters, it's a valid combination
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        // We can add an open parenthesis if we haven't used all n
        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }
        
        // We can add a close parenthesis only if it won't exceed open count
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }
};

int main() {
    Solution solution;
    
    vector<string> result1 = solution.generateParenthesis(3);
    cout << "generateParenthesis(3): ";
    for (const string& s : result1) cout << s << " ";
    cout << endl;
    
    vector<string> result2 = solution.generateParenthesis(1);
    cout << "generateParenthesis(1): ";
    for (const string& s : result2) cout << s << " ";
    cout << endl;
    
    vector<string> result3 = solution.generateParenthesis(4);
    cout << "generateParenthesis(4): ";
    for (const string& s : result3) cout << s << " ";
    cout << endl;
    
    return 0;
}
