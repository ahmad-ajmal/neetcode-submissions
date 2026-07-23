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
    int diameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);           // fills in `diameter` as it goes
        return diameter;
    }

    // returns the HEIGHT of the subtree rooted at node
    int height(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int left_height  = height(node->left);
        int right_height = height(node->right);

        // longest path THROUGH this node = left edges + right edges
        diameter = max(diameter, left_height + right_height);

        // this subtree's height = taller child + 1
        return max(left_height, right_height) + 1;
    }
};

