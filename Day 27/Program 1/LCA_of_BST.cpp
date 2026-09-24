#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        
        // If both p and q are greater than root, LCA must be in the right subtree
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        // If both p and q are less than root, LCA must be in the left subtree
        else if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        // If one is less and one is greater, or one is equal to root, we found the LCA
        else {
            return root;
        }
    }
};

int main() {
    Solution solution;
    
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    
    TreeNode* p = root->left; // Node 2
    TreeNode* q = root->right; // Node 8
    
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);
    cout << "LCA of 2 and 8 is: " << lca->val << endl;
    
    p = root->left; // Node 2
    q = root->left->right; // Node 4
    
    lca = solution.lowestCommonAncestor(root, p, q);
    cout << "LCA of 2 and 4 is: " << lca->val << endl;
    
    return 0;
}
