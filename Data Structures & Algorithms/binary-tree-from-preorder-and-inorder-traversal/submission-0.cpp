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
        
        if ((preorder.size() == 0) || (inorder.size() == 0))
            return nullptr;
        
        // pick the first element in the preorder list, that is the root node
        TreeNode* root = new TreeNode(preorder[0]);

        // segment the inorder to the left and right sub arrays using the root
        auto root_itr_inorder =  std::find(inorder.begin(), inorder.end(), root->val);
        int root_idx_in_inorder = std::distance(inorder.begin(), root_itr_inorder); // returns the index. starting from 0
        cout << "First root : " << *root_itr_inorder << endl;
        // segment inorder to left and right subarrrys
        std::vector<int> left_inorder(inorder.begin(), root_itr_inorder);
        // cout << "Elements of left inorder array : " << endl;
        // for(auto i : left_inorder)
        //     cout << i << " , ";

        // Constructs a container with as many elements as the range [first,last)
        std::vector<int> right_inorder(root_itr_inorder + 1, inorder.end());

        // cout << "Elements of right inorder array : " << endl;
        // for(auto i : right_inorder)
        //     cout << i << " , ";

        int left_inorder_arr_size = left_inorder.size();
        int right_inorder_arr_size = right_inorder.size();

        // using this size, partition the preorder into right and left subtrees
        std::vector<int> left_preorder(preorder.begin()+1, preorder.begin()+1+left_inorder_arr_size);
        std::vector<int> right_preorder(preorder.begin()+left_inorder_arr_size+1, preorder.begin()+left_inorder_arr_size+right_inorder_arr_size+1);
    
        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);
        
        return root;
    }
};
