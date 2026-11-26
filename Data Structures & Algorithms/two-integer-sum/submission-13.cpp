class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res_arr;
        // key : (diff, position)
        std::unordered_map<int, std::pair<int, int>> diff_map;
        // std::unordered_map<int, int> diff_map;

        for(int i = 0; i < nums.size(); i++) {
            int curr_diff = target - nums[i];

           

            if(diff_map.contains(curr_diff)) {

                if (diff_map[curr_diff].second != i) {
                    res_arr.push_back(diff_map[curr_diff].second);
                    res_arr.push_back(i);

                    return res_arr;
                }
            }

            diff_map[nums[i]] = std::make_pair(curr_diff, i);

        }

        return res_arr;
    }
};
