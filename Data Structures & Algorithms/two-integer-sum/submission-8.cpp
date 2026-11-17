class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hash Map
        std::unordered_map<int, int> hmap;
        vector<int> res;

        for(int i = 0; i<nums.size(); i++) {
            if(hmap.count(target - nums[i]) != 0) {
                // element exists in the map

                // use the index of it and then the current idx
                // as the idx present in the map will be lower idx
                res.push_back(hmap[target - nums[i]]);
                res.push_back(i);
                break;
            } else {
                // If you donot find it in the existing map
                // create one with key : arr_val and  value : idx
                hmap[nums[i]] = i;
            }
        }

        return res;
    }
};
