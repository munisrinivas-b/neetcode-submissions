class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       for(int i = 0; i < nums.size(); i++) {
        if (std::find(std::next(nums.begin(), i+1), nums.end(), nums[i]) != nums.end())
            return true;
       } 
       return false;
    }
};