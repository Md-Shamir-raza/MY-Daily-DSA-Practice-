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
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        inorder(root, k, result);
        return result;
    }
    
private:
    void inorder(TreeNode* node, int& k, int& result) {
        if (!node) return;
        
        inorder(node->left, k, result);
        
        k--;
        if (k == 0) {
            result = node->val;
            return;
        }
        
        inorder(node->right, k, result);
    }
};

int main() {
    Solution solution;
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    
    cout << "1st smallest element: " << solution.kthSmallest(root, 1) << endl;
    
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(6);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(4);
    root2->left->left->left = new TreeNode(1);
    
    cout << "3rd smallest element: " << solution.kthSmallest(root2, 3) << endl;
    
    return 0;
}
