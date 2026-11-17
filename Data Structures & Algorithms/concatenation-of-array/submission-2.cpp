class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res_arr(2*nums.size(), 0); // (size, value)
        // cout << res_arr.size() << endl;
        for(int i = 0; i < nums.size(); i++) {
            res_arr[i] = nums[i];
            res_arr[i+nums.size()] = nums[i];
        }

        return res_arr;
    }
};