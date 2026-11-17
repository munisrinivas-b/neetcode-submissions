class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;

        dfs(nums, ans, 0, subset);

        return ans;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& subset) {
        if (idx >= nums.size()) {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        dfs(nums, ans, idx+1, subset);
        subset.pop_back();
        dfs(nums, ans, idx+1, subset);
    }
};
