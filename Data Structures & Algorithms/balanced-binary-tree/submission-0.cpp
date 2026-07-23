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
    // NEW: helper to measure a subtree's height
    int height(TreeNode* node) {
        if (node == nullptr) return 0;
        return max(height(node->left), height(node->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }

        bool left_balanced  = isBalanced(root->left);   // are children balanced?
        bool right_balanced = isBalanced(root->right);

        int left_height  = height(root->left);           // NEW: how tall is each side?
        int right_height = height(root->right);

        // balanced = both children balanced AND heights differ by ≤ 1
        if(left_balanced && right_balanced && abs(left_height - right_height) <= 1) {
            return true;
        } else {
            return false;
        }
    }
};
