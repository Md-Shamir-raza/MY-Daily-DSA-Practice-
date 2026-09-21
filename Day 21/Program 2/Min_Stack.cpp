#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> min_s;

public:
    MinStack() {}
    
    void push(int val) {
        s.push(val);
        if (min_s.empty() || val <= min_s.top()) {
            min_s.push(val);
        }
    }
    
    void pop() {
        if (s.top() == min_s.top()) {
            min_s.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Minimum element: " << minStack.getMin() << endl; // return -3
    minStack.pop();
    cout << "Top element: " << minStack.top() << endl;    // return 0
    cout << "Minimum element: " << minStack.getMin() << endl; // return -2
    return 0;
}
