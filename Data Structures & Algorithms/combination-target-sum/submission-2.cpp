class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> sub_arr;
        int idx = 0;

        Helper(nums, target, idx, sub_arr, res);

        return res;
    }

    void Helper(vector<int>& nums, int target, int idx, vector<int>& sub_arr, vector<vector<int>>& res) {
        // Base case - If the elements present in the vector 
        // add up to the target add it in the resultant arr
        if(std::accumulate(sub_arr.begin(), sub_arr.end(), 0) == target) {
            res.push_back(sub_arr);
            return;
        }

        // Base case - 2 : if acuumulated value > target, simply return
        if(std::accumulate(sub_arr.begin(), sub_arr.end(), 0) > target) {

            return;
        }

        if (idx >= nums.size()) {
            return;
        }

        sub_arr.push_back(nums[idx]);
        Helper(nums, target, idx, sub_arr, res);
        sub_arr.pop_back();
        Helper(nums, target, idx+1, sub_arr, res);

    }
};
