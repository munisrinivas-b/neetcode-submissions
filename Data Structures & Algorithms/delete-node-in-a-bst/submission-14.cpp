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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // If no tree is present return nullptr
        if(!root)
            return root;

        // Find the key in the tree and delete it
        if(key < root->val) {           // look left
            root->left = deleteNode(root->left, key);
        } else if(key > root->val) {    // look right
            root->right = deleteNode(root->right, key);
        } else if(key == root->val) {   // key found
            cout << "Key found\n";
            if((root->right == nullptr) && (root->left == nullptr)) {         // No children
                return nullptr;
            } else if ((root->right != nullptr) && (root->left == nullptr)) { // right child alone
                return root->right;
            } else if ((root->right == nullptr) && (root->left != nullptr)) { // left child alone
                return root->left;
            } else if ((root->right != nullptr) && (root->left != nullptr)) { // Both children are present
                // Find the minimum node in the right most sub tree ==  inroder successor
                // (or) maximum node in the left most sub tree
                // a. copy the smallest value to the current node
                TreeNode* small_node_ptr = find_min_node(root->right);
                cout << "left mode root val : " <<  small_node_ptr->val << endl;
                root->val = small_node_ptr->val;
                // delete the node in the tree
                root->right = deleteNode(root->right, small_node_ptr->val);
            }
        }
        return root;
    }

    TreeNode* find_min_node(TreeNode* root) {
        // get the pointer to the smallest node
        TreeNode* small_node;
        if(root->left != nullptr) {
            small_node = find_min_node(root->left);
        } else {
            small_node = root;
        }
        return small_node;
    }
};