#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode* node, long long minVal, long long maxVal) {
        // Base case: an empty tree is a valid BST
        if (node == nullptr) {
            return true;
        }

        // Current node's value must be strictly between minVal and maxVal
        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }

        // Recursively validate left and right subtrees
        // For left subtree, the max value becomes the current node's value
        // For right subtree, the min value becomes the current node's value
        return validate(node->left, minVal, node->val) && 
               validate(node->right, node->val, maxVal);
    }
};

int main() {
    Solution obj;

    // Test case 1: [2,1,3]
    //   2
    //  / \
    // 1   3
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    cout << "Test 1: [2,1,3] -> " << (obj.isValidBST(root1) ? "true" : "false") << endl;

    // Test case 2: [5,1,4,null,null,3,6]
    //   5
    //  / \
    // 1   4
    //    / \
    //   3   6
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);
    cout << "Test 2: [5,1,4,null,null,3,6] -> " << (obj.isValidBST(root2) ? "true" : "false") << endl;

    // Test case 3: [2,2,2]
    //   2
    //  / \
    // 2   2
    TreeNode* root3 = new TreeNode(2);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(2);
    cout << "Test 3: [2,2,2] -> " << (obj.isValidBST(root3) ? "true" : "false") << endl;

    return 0;
}
