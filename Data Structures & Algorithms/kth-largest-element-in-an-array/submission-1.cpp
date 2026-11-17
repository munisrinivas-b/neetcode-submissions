class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // use maxHeap
        
        std::priority_queue<int, vector<int>, std::less<int>> maxHeap;

        for(int& num : nums) {
            maxHeap.push(num);
        }

        int res;
        for(int i = 0; i < k; i++) {
            if(!maxHeap.empty()) {
                res = maxHeap.top();
                maxHeap.pop();
            }
        }

        return res;
        
    }
};
