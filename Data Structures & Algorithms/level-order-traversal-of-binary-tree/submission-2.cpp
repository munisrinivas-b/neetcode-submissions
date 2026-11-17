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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res_vec;

        if(!root) //Empty tree
            return res_vec;

        vector<int> interim_vec;
        
        std::deque<TreeNode> node_lst;

        node_lst.push_back(*root);
        // interim_vec.push_back(root->val);
        // res_vec.push_back(interim_vec);

        

        while(!node_lst.empty()) {
            interim_vec.clear();
            int q_size = node_lst.size();

            for(int i=0; i<q_size; i++) {
                TreeNode curr_node = node_lst.front();
                node_lst.pop_front();
                interim_vec.push_back(curr_node.val);

                if(curr_node.left != nullptr) {
                    node_lst.push_back(*curr_node.left);
                }

                if(curr_node.right != nullptr) {
                    node_lst.push_back(*curr_node.right);
                }
            }
            res_vec.push_back(interim_vec);
        }

        return res_vec;
    }
};
