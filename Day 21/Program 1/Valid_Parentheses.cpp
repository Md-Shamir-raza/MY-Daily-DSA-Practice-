#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                if (c == ')' && st.top() != '(') return false;
                if (c == '}' && st.top() != '{') return false;
                if (c == ']' && st.top() != '[') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    Solution solution;
    cout << "Is '()' valid? " << (solution.isValid("()") ? "Yes" : "No") << endl;
    cout << "Is '()[]{}' valid? " << (solution.isValid("()[]{}") ? "Yes" : "No") << endl;
    cout << "Is '(]' valid? " << (solution.isValid("(]") ? "Yes" : "No") << endl;
    return 0;
}
