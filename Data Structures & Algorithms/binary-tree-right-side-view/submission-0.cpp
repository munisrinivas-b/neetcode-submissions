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
        vector<int> result;

        if (root == nullptr)
            return result;

        // in any given level, store the final value in the level

        std::deque<TreeNode> level_store;

        level_store.push_back(*root);

        while(!level_store.empty()) {
            // store each of the element in level in the queue
            int q_len = level_store.size();

            for(int i = 0; i < q_len; i++) {
                TreeNode ele = level_store.front();
                level_store.pop_front();

                if (i == q_len-1)
                    result.push_back(ele.val);

                if(ele.left != nullptr) {
                    level_store.push_back(*ele.left);
                }

                if(ele.right != nullptr) {
                    level_store.push_back(*ele.right);
                }
            }

        }

        return result;
        
    }
};
