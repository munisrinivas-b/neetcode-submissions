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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;

        // Iterate through the tree in level-wise and store only the last number in the row
        std::deque<TreeNode*> level_lst;
        level_lst.push_back(root);

        while(!level_lst.empty()) {
            int q_size = level_lst.size();
            cout << "Q Size Before: " << q_size <<  endl;
            for(int i=0; i<q_size; i++) {
                TreeNode* curr_node = level_lst.front();
                level_lst.pop_front();

                if(curr_node->left != nullptr)
                    level_lst.push_back(curr_node->left);

                if(curr_node->right != nullptr)
                    level_lst.push_back(curr_node->right);

                cout << "Q Size within: " << level_lst.size() <<  endl;
                if(i==q_size-1)
                    res.push_back(curr_node->val);
            }
        }
        return res;      
    }
};
