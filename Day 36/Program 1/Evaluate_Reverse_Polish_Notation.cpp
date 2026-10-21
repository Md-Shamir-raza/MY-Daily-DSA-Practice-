#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else st.push(a / b); // Integer division truncates toward zero
            } else {
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }
};

int main() {
    Solution solution;
    
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << "evalRPN({\"2\",\"1\",\"+\",\"3\",\"*\"}): " 
         << solution.evalRPN(tokens1) << endl;
    
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << "evalRPN({\"4\",\"13\",\"5\",\"/\",\"+\"}): " 
         << solution.evalRPN(tokens2) << endl;
    
    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << "evalRPN({\"10\",\"6\",\"9\",\"3\",\"+\",\"-11\",\"*\",\"/\",\"*\",\"17\",\"+\",\"5\",\"+\"}): " 
         << solution.evalRPN(tokens3) << endl;
    
    return 0;
}
