class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        
        dfs(ans, subset, 0, nums, target);

        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& subset, int idx, vector<int>& nums, int target) {
        if(idx >= nums.size() || (std::accumulate(subset.begin(), subset.end(), 0) > target)) {
            return;
        }

        if( std::accumulate(subset.begin(), subset.end(), 0) == target) {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        dfs(ans, subset, idx, nums, target);
        subset.pop_back();
        dfs(ans, subset, idx+1, nums, target);

    }
};
