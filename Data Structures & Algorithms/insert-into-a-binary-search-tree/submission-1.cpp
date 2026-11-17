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
        //itertaion appraoch
        if (root == nullptr)
            return new TreeNode(val);

        TreeNode* curr_ptr = root;
        TreeNode* prev_ptr = curr_ptr;
        // traverse down the tree and add the value to the possible leaf node
        while(curr_ptr != nullptr) {
            prev_ptr = curr_ptr;
            if(val > curr_ptr->val) {
                curr_ptr = curr_ptr->right;
            } else if(val < curr_ptr->val) {
                curr_ptr = curr_ptr->left;
            }
        }
        // reached the leaf node
        if(val > prev_ptr->val) {
            prev_ptr->right = new TreeNode(val);
        } else if (val < prev_ptr->val) {
            prev_ptr->left= new TreeNode(val);
        }
        
        return root;
    }
};