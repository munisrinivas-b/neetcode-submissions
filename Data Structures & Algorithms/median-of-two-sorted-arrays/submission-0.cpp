class Solution {
public:
    // bool sort_asc(int i, int j) { return i < j; }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // std::vector<int> res_arr(nums1.begin(), nums1.end());
        std::vector<int> res_arr(nums1);

        for(int &i : nums2) {
            res_arr.push_back(i);
        }

        std::sort(res_arr.begin(), res_arr.end(), [](int i , int j){return  i<j;});

        // if the sorted array is odd, then return the middle element
        // else
        // return the avg of the middle elements
        int res_arr_size = res_arr.size();
        int mid_idx = res_arr_size/2;

        if(res_arr_size % 2 != 0) {
            return res_arr[mid_idx];
        } else {
            return (float)(res_arr[mid_idx-1] + res_arr[mid_idx])/2;
        }
    }

    
};
