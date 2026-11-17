class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hash Map
        std::unordered_map<int, int> hmap;
        vector<int> res;

        for(int i = 0; i<nums.size(); i++) {
            if(hmap.count(target - nums[i]) != 0) {
                // element exists in the map
                res.push_back(hmap[target - nums[i]]);
                res.push_back(i);
                break;
            } else {
                hmap[nums[i]] = i;
            }
        }

        return res;
    }
};
