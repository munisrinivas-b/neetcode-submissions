class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // itertive approach
        vector<vector<int>> result;

        vector<int> sub_arr;

        result.push_back(sub_arr);

        sub_arr.push_back(nums[0]); // add the first element

        result.push_back(sub_arr);

        // cout << result.size() << endl;

        for(int i = 1; i < nums.size() ; i++) {
            int num = nums[i];

            // 2 actions => pick or not pick on each of the sublist
            // present in the result array

            int n = result.size();
            
            for(int j = 0; j < n; j++) {
                vector<int> tmp_sub_lst = result[j];

                tmp_sub_lst.push_back(num);

                result.push_back(tmp_sub_lst);
            }
        }

        return result;
    }
};
