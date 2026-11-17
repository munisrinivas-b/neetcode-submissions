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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // No tree is present, add the new node and return that
        if(!root)
            return new TreeNode(val);
        
        // Follow the BST logic and reach the leaf node
        if(val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else if(val > root->val) {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};