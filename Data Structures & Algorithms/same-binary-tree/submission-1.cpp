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
    vector<string> getTreeAsArray(TreeNode* root)
    {
        if (root == nullptr)
        {
            return vector<string>();
        }

        vector<string> left_array;
        vector<string> right_array;
        if(root->left == nullptr)
        {
            left_array = {"L" + to_string(-1)};
        }
        else
        {
            left_array = getTreeAsArray(root->left);
        }

        if(root->right != nullptr)
        {
            right_array = getTreeAsArray(root->right);
        }
        else
        {
            right_array = {"R" + to_string(-1)};
        }

        left_array.push_back(to_string(root->val));
        left_array.insert(left_array.end(), right_array.begin(), right_array.end());

        return left_array;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<string> p_tree;
        vector<string> q_tree;
        if(p != nullptr)
        {
            p_tree = getTreeAsArray(p);
        }
        if(q != nullptr)
        {
            q_tree = getTreeAsArray(q);
        }

        for(string a : p_tree)
        {
            cout<<a<< " ";
        }
        cout<<"end"<<endl;

        for(string a : q_tree)
        {
            cout<<a<< " ";
        }
        cout<<"end"<<endl;


        return p_tree == q_tree;
    }
};
