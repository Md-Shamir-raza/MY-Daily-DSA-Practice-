#include<iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // slow is now just before the node to be deleted
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    cout << "[";
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << ", ";
        head = head->next;
    }
    cout << "]" << endl;
}

// Helper function to free the linked list
void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution obj;

    // Test case 1
    ListNode* head1 = createList({1, 2, 3, 4, 5});
    cout << "Test 1: head=[1,2,3,4,5], n=2 -> ";
    ListNode* ans1 = obj.removeNthFromEnd(head1, 2);
    printList(ans1);
    freeList(ans1);

    // Test case 2
    ListNode* head2 = createList({1});
    cout << "Test 2: head=[1], n=1 -> ";
    ListNode* ans2 = obj.removeNthFromEnd(head2, 1);
    printList(ans2);
    freeList(ans2);

    // Test case 3
    ListNode* head3 = createList({1, 2});
    cout << "Test 3: head=[1,2], n=1 -> ";
    ListNode* ans3 = obj.removeNthFromEnd(head3, 1);
    printList(ans3);
    freeList(ans3);

    return 0;
}
