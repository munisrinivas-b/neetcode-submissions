class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Inplace +  valid range ==> Bucket sort
        if(nums.empty()) // corner case
            return ;

        std::map<int, int> histogram;

        // form the histogram for the given input array
        for(int& n : nums) {
            auto itr = histogram.find(n);
            if(itr != histogram.end()) {
                // key exists and update the value by 1
                histogram[n] = histogram[n] + 1;
            } else {
                // key doesnot exists, insert one and init with 0
                histogram[n] = 1;
            }
        }

        // for(auto itr = histogram.begin(); itr != histogram.end(); itr++) {
        //     cout << itr->first << " , " << itr->second << endl;
        // }
        
        // overwrite the given input array wiht the map data
        nums.clear();
        auto nums_itr = nums.begin();
        
        for(auto itr = histogram.begin(); itr != histogram.end(); itr++) {
            for(int i = 0; i < itr->second; i++) {
                nums.push_back(itr->first);
            }
        }
        
        
    }
};