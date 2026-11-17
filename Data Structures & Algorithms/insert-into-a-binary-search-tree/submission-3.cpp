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

        root = insertHelper(root, val);
        
        return root;
    }

    TreeNode* insertHelper(TreeNode* curr_node, int val) {
        if (curr_node == nullptr) {
            // No initial tree exists
            curr_node = new TreeNode(val); // create a Node
            return curr_node; //Node created, nothing to do, return
        }

        if(val > curr_node->val) {
            curr_node->right = insertHelper(curr_node->right, val);
        } else if(val < curr_node->val) {
            curr_node->left = insertHelper(curr_node->left, val);
        }

        return curr_node;
    }
};