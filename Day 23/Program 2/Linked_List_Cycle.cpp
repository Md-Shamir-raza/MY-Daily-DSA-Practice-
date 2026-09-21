#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};

int main() {
    Solution solution;
    
    // Create a list with a cycle: 3 -> 2 -> 0 -> -4 -> 2...
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);
    
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Cycle back to node2
    
    cout << "Has Cycle: " << (solution.hasCycle(head) ? "Yes" : "No") << endl;
    
    // Create a list without a cycle: 1 -> 2
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    
    cout << "Has Cycle: " << (solution.hasCycle(head2) ? "Yes" : "No") << endl;
    
    return 0;
}
