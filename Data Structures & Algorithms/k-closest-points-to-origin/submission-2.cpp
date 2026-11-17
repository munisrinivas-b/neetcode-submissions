class Solution {



    

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // use Heap


        // custom comparators
        auto greater_pair = [](const vector<int>& pairA, const vector<int>& pairB) {
            // The below elements of the root node must be grater than root node
            return (pairA[0]*pairA[0] + pairA[1]*pairA[1]) > (pairB[0]*pairB[0] + pairB[1]*pairB[1]) ;
        };

        std::priority_queue<vector<int>, vector<vector<int>>, decltype(greater_pair)> minHeap{greater_pair};

        for(auto& pt : points) {
            minHeap.push(pt);
        }

        // while(!minHeap.empty()) {
        //     vector<int> ele = ;
        //     cout << "(" << ele[0] << " , " << ele[1] << ")" << " , " ;
        //     minHeap.pop();
        // }

        vector<vector<int>> res;
        for(int i = 0; i < k ; i++) {
            if(!minHeap.empty()) {
                res.push_back(minHeap.top());
                minHeap.pop();
            }
        }

        return res;

    }
};
