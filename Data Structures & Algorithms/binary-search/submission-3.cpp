class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        int m = (s+e)/2;
        int ret_val = bin_search(nums, s, e, target);
        return ret_val;
    }

    int bin_search(vector<int>& nums, int s, int e, int target) {
        int m = (s+e)/2;
        int ret_val = -1;

        if (e < s) { // when the element is not found
            return -1;
        }

        if(nums[m] == target) {
            return m;
        }

        if(target > nums[m]) {
            // process right sub array
            ret_val = bin_search(nums, m+1, e, target);
        } else if(target < nums[m]) {
            // process left sub array
            ret_val = bin_search(nums, s, m-1, target);
        }

        return ret_val;
    }
};
