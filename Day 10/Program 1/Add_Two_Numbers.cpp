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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead; // Free the dummy node
        return result;
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
    ListNode* l1_1 = createList({2, 4, 3});
    ListNode* l1_2 = createList({5, 6, 4});
    cout << "Test 1: l1=[2,4,3], l2=[5,6,4] -> ";
    ListNode* ans1 = obj.addTwoNumbers(l1_1, l1_2);
    printList(ans1);
    freeList(l1_1); freeList(l1_2); freeList(ans1);

    // Test case 2
    ListNode* l2_1 = createList({0});
    ListNode* l2_2 = createList({0});
    cout << "Test 2: l1=[0], l2=[0] -> ";
    ListNode* ans2 = obj.addTwoNumbers(l2_1, l2_2);
    printList(ans2);
    freeList(l2_1); freeList(l2_2); freeList(ans2);

    // Test case 3
    ListNode* l3_1 = createList({9, 9, 9, 9, 9, 9, 9});
    ListNode* l3_2 = createList({9, 9, 9, 9});
    cout << "Test 3: l1=[9,9,9,9,9,9,9], l2=[9,9,9,9] -> ";
    ListNode* ans3 = obj.addTwoNumbers(l3_1, l3_2);
    printList(ans3);
    freeList(l3_1); freeList(l3_2); freeList(ans3);

    return 0;
}
