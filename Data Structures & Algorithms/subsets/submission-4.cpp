class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub_res;
        vector<vector<int>> res;

        int idx = 0;
        subsetHelper(nums, sub_res, res, idx);

        return res;
    }

    void subsetHelper(vector<int>& nums, vector<int> sub_res, vector<vector<int>>& res,int idx) {
        // If the idx does not reach the last idx, keep creating the tree
        // Only after reaching the last idx, save the sub_arr
        if(idx < nums.size()){
            subsetHelper(nums, sub_res, res, idx+1); // wihtout curr_idx
            sub_res.push_back(nums[idx]); // add
            subsetHelper(nums, sub_res, res, idx+1); // with curr_idx
        } else if(idx == nums.size()){
            //reached the end of the array
            res.push_back(sub_res);
        }
    }
};
