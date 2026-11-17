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
        std::deque<TreeNode> level_store;
        vector<vector<int>> level_list;

        // If no elements are present, return the empty tree itself
        if(root == nullptr)
            return level_list;

        // push the root to the level_store
        level_store.push_back(*root);

        // while there exists an element in the queue process the
        // element and check if there exists a children to it.
        // if there are childeren to the element, add it to the queue

        while( !level_store.empty() ) {
            // iterate throught the queue
            std::vector<int> sub_level_list;
            int n_ele = level_store.size();
            for(int i = 0; i < n_ele; i++) {
                TreeNode element = level_store.front(); // get the front element
                level_store.pop_front(); // delete the front element from queue

                sub_level_list.push_back(element.val); // store the level wise element

                if(element.left != nullptr) {
                    level_store.push_back(*element.left);
                }

                if(element.right != nullptr) {
                    level_store.push_back(*element.right);
                }
            }
            level_list.push_back(sub_level_list);
        }
        return level_list;
    }
};
