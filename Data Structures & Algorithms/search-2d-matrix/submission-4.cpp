class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int num_rows = matrix.size();
        int num_cols = matrix[0].size();

        bool search_hit = false;

        // Iterate through each row and check if the taget exists in
        // that row, If yes perofrm the search
        for(int i = 0; i < num_rows; i++) {
            if((target >= matrix[i][0]) && (target <= matrix[i][num_cols-1])) {
                // cout << "Found in row : " <<  i << endl;
                search_hit = bin_search(matrix[i], target);
            }
        }
        
        return search_hit;
    }

    bool bin_search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while(left <= right) {
            int mid = (left+right)/2;

            if(target == nums[mid]) {
                return true;
            } else if(target > nums[mid]) {
                left = mid+1;
            } else if(target < nums[mid]) {
                right = mid-1;
            }
        }

        return false;
    }
};
