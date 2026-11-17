class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n_size = nums.size();
        vector<int> result(2 * n_size);

        for(int i = 0; i < n_size; i++) {
            result[i] = nums[i];
            result[n_size + i] = nums[i];
        }

        return result;
        
    }
};