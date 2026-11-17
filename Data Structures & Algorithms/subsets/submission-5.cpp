class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // use back-tracking

        vector<int> sub_arr;
        vector<vector<int>> res;

        int idx = 0;
        subsetsHelper(nums, idx, sub_arr, res);

        return res;
    }

    void subsetsHelper(vector<int>& nums, int idx, vector<int>& sub_arr, vector<vector<int>>& res) {
        // Base case
        if(idx == nums.size()) {
            //add it to the result arr and exit
            res.push_back(sub_arr);
            return;
        }

        // Keep adding the element to the sub_arr
        sub_arr.push_back(nums[idx]);
        subsetsHelper(nums, idx+1, sub_arr, res);
        sub_arr.pop_back(); // return to the previous state
        subsetsHelper(nums, idx+1, sub_arr, res);


    }
};
