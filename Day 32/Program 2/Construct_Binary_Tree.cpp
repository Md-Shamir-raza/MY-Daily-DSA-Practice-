#include <iostream>
#include <vector>
#include <unordered_map>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Build a hashmap for quick lookup of root position in inorder traversal
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        int preIdx = 0;
        return build(preorder, inorderMap, preIdx, 0, inorder.size() - 1);
    }
    
private:
    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inorderMap,
                    int& preIdx, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;
        
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        
        int inIdx = inorderMap[rootVal];
        
        // Build left subtree first (because preorder is Root -> Left -> Right)
        root->left = build(preorder, inorderMap, preIdx, inStart, inIdx - 1);
        root->right = build(preorder, inorderMap, preIdx, inIdx + 1, inEnd);
        
        return root;
    }
};

// Helper function to print tree in level order for verification
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    Solution solution;
    
    vector<int> preorder1 = {3, 9, 20, 15, 7};
    vector<int> inorder1 = {9, 3, 15, 20, 7};
    
    TreeNode* tree1 = solution.buildTree(preorder1, inorder1);
    cout << "Reconstructed tree (inorder):  ";
    printInorder(tree1);
    cout << endl;
    cout << "Reconstructed tree (preorder): ";
    printPreorder(tree1);
    cout << endl;
    
    vector<int> preorder2 = {-1};
    vector<int> inorder2 = {-1};
    
    TreeNode* tree2 = solution.buildTree(preorder2, inorder2);
    cout << "Reconstructed tree (inorder):  ";
    printInorder(tree2);
    cout << endl;
    
    return 0;
}
