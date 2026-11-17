class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hmap; // key = arr_val, val = frequency

        for(int i = 0; i < nums.size(); i++) {
            if(hmap.count(nums[i]) != 0) {
                // appeated more than once
                return true;
            } else {
                hmap[nums[i]] += 1;
            }
        }

        return false;
        
    }
};