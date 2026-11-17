class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // a. construct maxHeap using given array
        std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;

        for(int& stone_wt : stones) {
            maxHeap.push(stone_wt);
        }


        // b. Get the weight of the top two heavy stones
        while(maxHeap.size() >= 2) {
            int wt_s1 = maxHeap.top();
            maxHeap.pop();

            int wt_s2 = maxHeap.top();
            maxHeap.pop();

            int wt_diff = std::abs(wt_s1 - wt_s2);

            if(wt_s1 == wt_s2) {
                // stones are equal weight, destroy them.
                // Do nothing
            } else {
                // add the new weight to the maxHeap
                maxHeap.push(wt_diff);
            }
        }

        // If no stones left then return 0
        if(maxHeap.size() == 0)
            return 0;
        

        // Only one stone left, return the weight of that stone
        return maxHeap.top();
        
    }
};
