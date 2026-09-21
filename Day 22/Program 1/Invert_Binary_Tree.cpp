#include <iostream>

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};

void printPreorder(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->val << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    root->right = new TreeNode(7, new TreeNode(6), new TreeNode(9));
    
    cout << "Original Tree Preorder: ";
    printPreorder(root);
    cout << endl;
    
    root = solution.invertTree(root);
    
    cout << "Inverted Tree Preorder: ";
    printPreorder(root);
    cout << endl;
    
    return 0;
}
