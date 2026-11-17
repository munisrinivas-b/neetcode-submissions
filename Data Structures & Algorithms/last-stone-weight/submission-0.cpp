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

        if(maxHeap.size() == 0)
            return 0;
        
        return maxHeap.top();

        // cout << "Final Heap size : " << maxHeap.size() << endl;
        

        // return 1;
        
    }
};
