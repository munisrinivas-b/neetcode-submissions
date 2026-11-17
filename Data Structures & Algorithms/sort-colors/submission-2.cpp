class Solution {
public:
    void sortColors(vector<int>& nums) {
        std::map<int, int> histo;

        // create frequency table
        for(int i : nums) {
            if(histo.find(i) != histo.end()) {
                histo[i]++;
            } else {
                histo[i] = 1;
            }
        }

        int i = 0; // pointer to the nums array
        for(auto itr = histo.begin(); itr != histo.end(); itr++) {
            // cout << itr->first << " : " <<  itr->second << endl;
            int key_count = itr->second;
            
            while(key_count > 0) {
                nums[i] = itr->first;
                i++;
                key_count--;
            }
        }

        // return nums;
    }
};