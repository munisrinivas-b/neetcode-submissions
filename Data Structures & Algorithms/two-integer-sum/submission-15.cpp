class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res_arr;
        // key : (diff, position)
        // std::unordered_map<int, std::pair<int, int>> diff_map;
        std::unordered_map<int, int> diff_map;

        for(int i = 0; i < nums.size(); i++) {
            int curr_diff = target - nums[i];

            if(diff_map.contains(curr_diff)) {

                if (diff_map[curr_diff] != i) {
                    // res_arr.push_back(diff_map[curr_diff]); // checked this condition in the outer if loop
                    // res_arr.push_back(i);

                    // return res_arr;
                    // simpler version
                    return {diff_map[curr_diff], i};
                }
            }

            // diff_map[nums[i]] = std::make_pair(curr_diff, i);
            diff_map[nums[i]] = i;

        }

        return res_arr;
    }
};
