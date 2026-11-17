class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> res_arr;

        for(int num : nums) {
            int res_size = res_arr.size();
            
            if(res_size == 0) {
                res_arr.push_back(num);
                continue;
            }
                
            if((res_size > 0) && (res_arr.back() != num)) {
                res_arr.push_back(num);
            }

        }
        nums = res_arr;
        return res_arr.size();
    }
};