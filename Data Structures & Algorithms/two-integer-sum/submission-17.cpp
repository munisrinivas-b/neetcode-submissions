class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Two sum using two pointers
        vector<std::pair<int, int>> temp_arr; //store the elements along with the indices, since sort will affect it

        for(int i = 0; i < nums.size(); i++) {
            temp_arr.emplace_back(nums[i], i); // emplace calls the constructor too
        }

        // sort the array and start the pointer process
        std::sort(temp_arr.begin(), temp_arr.end(), 
                [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                    return a.first < b.first;
                }
            );
        
        int ptrA, ptrB;
        ptrA = 0;
        ptrB = temp_arr.size() - 1;

        while (ptrA < ptrB) { 
            
            if (target < temp_arr[ptrA].first + temp_arr[ptrB].first) {
                ptrB = ptrB - 1;
            } else if (target > temp_arr[ptrA].first + temp_arr[ptrB].first) {
                ptrA = ptrA + 1;
            } else if (target == temp_arr[ptrA].first + temp_arr[ptrB].first) {
                return {min(temp_arr[ptrA].second, temp_arr[ptrB].second),
                max(temp_arr[ptrA].second, temp_arr[ptrB].second)};
            }

        };
            
        return {};
    }
};
