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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }

        int left_length = 0;
        int right_length = 0;

        if(root->left != nullptr)
        {
            left_length = maxDepth(root->left);
        }
        if(root->right != nullptr)
        {
            right_length = maxDepth(root->right);
        }

        if(left_length > right_length)
        {
            return left_length + 1;
        }
        else
        {
            return right_length + 1;
        }
    }
};
