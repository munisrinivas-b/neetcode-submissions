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

        if(idx < nums.size()){
            subsetHelper(nums, sub_res, res, idx+1);
            sub_res.push_back(nums[idx]); // add
            subsetHelper(nums, sub_res, res, idx+1);
        } else if(idx == nums.size()){
            //reached the end of the array
            res.push_back(sub_res);
        }
    }
};
