class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       // can use std::map, but it has O(log N) complexity for Search, insertion, and deletion
       // Will use std::unordered_map, which take O(1) for lookup, insertion, and deletion ) time
       std::unordered_map<int, int> num_count;

       for(int &num : nums) {
            if (num_count[num] == 0)
                num_count[num] = 1;  //element is not there, insert it and increase the value
            else    // if the element already exists, then return true
                return true;
       }
       return false;
    }
};