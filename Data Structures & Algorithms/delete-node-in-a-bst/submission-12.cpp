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

        // Empty tree
        if(root == nullptr)
            return root;

        // Search for the key in the Tree
        if (key < root->val) {
            // search left side of the Tree
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key == root->val) {
            // Keyfound
            
            // a. No children to the node
            if((root->right== nullptr) && (root->left == nullptr)) {
                return nullptr;
            }

            // b. One child
            // b.(i) Left child present
            if((root->right == nullptr) && (root->left != nullptr)) {
                return root->left;
            }
            // b.(ii) right child present
            if((root->left == nullptr) && (root->right != nullptr)) {
                return root->right;
            }

            //c. Two children are present
            // Delete the least element from the right side tree of the node
            // step-1: find the inroder successor / inorder predecessor
            TreeNode* succ = findMinEle(root->right);
            // copy the value to this node
            root->val = succ->val;
            // delete the successor node
            root->right = deleteNode(root->right, succ->val);
        }
        

        // InOrder sequence : [left, root, right]
        // inorder(root);
        // while(curr_node != nullptr) {
        //     curr_node = curr_node->left;
        // }
        // cout << curr_node->val <<  endl;

        return root;
        
    }

    TreeNode* findMinEle(TreeNode* root) {
        // successor = left
        if(root->left != nullptr) {
            root = root->left;
        }

        return root;
    }

    void inorder(TreeNode* root) {
        TreeNode* curr_node = root;

        // left
        if(curr_node->left != nullptr) {
            inorder(curr_node->left);
        }
        // reached left most node
        cout << curr_node->val <<  endl;

        if(curr_node->right != nullptr) {
            inorder(curr_node->right);
        }

    }
};