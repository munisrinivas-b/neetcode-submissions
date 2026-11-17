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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Base case
        if (inorder.size() == 1) {
            return new TreeNode(inorder[0]);
        }

        int p_idx = 0;
        // Construct left subtree => root => right subtree
        TreeNode* root = createTree(preorder, inorder, p_idx);

        return root;
    }

    TreeNode* createTree(vector<int>& preorder, vector<int> inorder, int& p_idx) {
        if(inorder.size() == 0) {
            // Base case, only one node is present in the bifurcated inorder lst
            p_idx--;
            return nullptr;
        }
        // find the preorder[p_idx] in inorder and 
        // bifurcate the inroder to left and right subtree lists
        std::vector<int>::iterator itr = std::find(inorder.begin(), inorder.end(), preorder[p_idx]);
        
        // create root
        TreeNode* root = new TreeNode(*itr);
        if(inorder.size() == 1) {
            // Base case, only one node is present in the bifurcated inorder lst
            return root;
        }

        std::vector<int> inorder_left(inorder.begin(), itr);
        p_idx = p_idx+1;
        root->left = createTree(preorder, inorder_left, p_idx);

        std::vector<int> inorder_right(itr+1, inorder.end()); 
        p_idx = p_idx+1;
        root->right = createTree(preorder, inorder_right, p_idx);
        
        return root;
    }
};