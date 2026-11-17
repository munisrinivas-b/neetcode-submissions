class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Mathematical equation technique
        // x1 + x2 = target
        // search for target-x2 in the vector, If it exists add it to
        // the result array

        vector<int> res;

        int i = 0;
        for(int& num : nums) {
            // search for the x-target from the next idx of the current idx
            auto itr = std::find(nums.begin()+i+1, nums.end(), target-num);
            if(itr != nums.end()) {
                // elemnt found, add it to the result
                long dist_from_idx_i = std::distance(nums.begin()+i, itr);
                int j = (dist_from_idx_i + i);
                cout << i << " , " << j <<  endl;
                if(i==j){
                    i++;
                    continue;
                } 

                res.push_back(i);
                res.push_back(j);
                break;
            }
            i++;
        }

        return res;
        
    }
};
