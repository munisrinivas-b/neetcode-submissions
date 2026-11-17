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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res_arr;

        inorderHelper(root, res_arr);

        return res_arr;
    }

    void inorderHelper(TreeNode* root, vector<int>& res_arr) {
        if(root == nullptr)
            return;

        inorderHelper(root->left, res_arr);
        res_arr.push_back(root->val);
        inorderHelper(root->right, res_arr);
    }
};