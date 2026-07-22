/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->left==nullptr && root->right==nullptr)
        {
            return root;
        }
        TreeNode* new_left = nullptr;
        TreeNode* new_right = nullptr;
        if(root->left != nullptr)
        {
            new_right = invertTree(root->left);
        }
        if(root->right != nullptr)
        {
            new_left = invertTree(root->right);
        }

        root->left = new_left;
        root->right = new_right;

        return root;
    }
};
