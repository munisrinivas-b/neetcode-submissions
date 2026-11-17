class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // try recursive solution
        vector<vector<int>> result;
        vector<int> subsets;

        subsetHelper(nums, result, subsets, 0);

        return result;
    }

    void subsetHelper(vector<int>& nums, vector<vector<int>>& result, vector<int>& subsets, int idx = 0) {
        
        if(idx >= nums.size()) {
            // Back-tracking should start
            result.push_back(subsets);
            return;
        }  

        if (idx < nums.size()) {
            subsets.push_back(nums[idx]);
            // result.push_back(subsets);
        }
        
        subsetHelper(nums, result, subsets, idx+1);
        subsets.pop_back();
        subsetHelper(nums, result, subsets, idx+1);
        // result.push_back(subsets);

    }
};
