class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int rt = nums.size()-1;

        int target_idx = bin_search(nums, left, rt, target);

        return target_idx;
    }

    int bin_search(vector<int>& nums, int left, int right, int target) {
        cout << left << " , " << right <<  endl;

        int mid = (left+right)/2;
        int target_idx = -1;

        // base case, assuming the targer found
        if(nums[mid] == target) { 
            return mid;
        } else if(left > right) {
            return -1;
        }

        if(target > nums[mid]) {
            target_idx = bin_search(nums, mid+1, right, target); 
        } else if(target < nums[mid]) {
            target_idx = bin_search(nums, left, mid-1, target);
        }

        cout << "Returned idx : " << target_idx << endl;
        return target_idx;

    }
};
