class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> result;

        for(int i = 0; i < nums.size(); i++) {
            
            // Add to the result array, if the element is new and does not exist already
            if(std::find(result.begin(), result.end(), nums[i]) == result.end()) {
                result.push_back(nums[i]);
                // cout << "Addded\n";
            }
        }

        nums = result;
        return result.size();
        
    }
};