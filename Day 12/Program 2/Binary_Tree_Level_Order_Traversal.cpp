#include<iostream>
#include<vector>
#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = q.front();
                q.pop();

                currentLevel.push_back(currentNode->val);

                if (currentNode->left != nullptr) {
                    q.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    q.push(currentNode->right);
                }
            }

            result.push_back(currentLevel);
        }

        return result;
    }
};

// Helper function to print level order traversal
void printLevelOrder(const vector<vector<int>>& levels) {
    cout << "[" << endl;
    for (const auto& level : levels) {
        cout << "  [";
        for (int i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i < level.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main() {
    Solution obj;

    // Test case 1: [3,9,20,null,null,15,7]
    //    3
    //   / \
    //  9  20
    //    /  \
    //   15   7
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    
    cout << "Test 1: [3,9,20,null,null,15,7] ->" << endl;
    vector<vector<int>> ans1 = obj.levelOrder(root1);
    printLevelOrder(ans1);

    // Test case 2: [1]
    TreeNode* root2 = new TreeNode(1);
    cout << "\nTest 2: [1] ->" << endl;
    vector<vector<int>> ans2 = obj.levelOrder(root2);
    printLevelOrder(ans2);

    // Test case 3: []
    TreeNode* root3 = nullptr;
    cout << "\nTest 3: [] ->" << endl;
    vector<vector<int>> ans3 = obj.levelOrder(root3);
    printLevelOrder(ans3);

    return 0;
}
