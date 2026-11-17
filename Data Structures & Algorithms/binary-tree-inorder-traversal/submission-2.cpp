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

        vector<int> res;

        if(!root)
            return res;

        inOrderHelper(root, res);

        return res;
        
    }

    void inOrderHelper(TreeNode* root, vector<int>& res) {
        if(root->left != nullptr) {
            inOrderHelper(root->left, res);
        }
        res.push_back(root->val);

        if(root->right != nullptr) {
            inOrderHelper(root->right, res);
        }
    }
};