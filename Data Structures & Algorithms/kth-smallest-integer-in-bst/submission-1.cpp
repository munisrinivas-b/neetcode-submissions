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
    int kthSmallest(TreeNode* root, int k) {
        // run the inorder traversal, store the sorted array in vector
        // and return element present in k+1 index of the array
        vector<int> result;

        inorderHelper(root, result);

        // for(auto i : result)
        //     cout << i << endl;

        return result[k-1];
        
    }

    void inorderHelper(TreeNode* root, vector<int>& result) {
        if(root == nullptr) {
            return ;
        }

        if(root->left != nullptr) {
            inorderHelper(root->left, result);
        }

        // cout << "val :" <<  root->val << endl;

        result.push_back(root->val);

        if(root->right != nullptr) {
            inorderHelper(root->right, result);
        }

    }
};
