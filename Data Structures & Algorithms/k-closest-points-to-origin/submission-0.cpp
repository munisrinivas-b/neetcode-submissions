class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // can be done using the basic sort operation, but need to maintain a correspodence
        

        std::sort(points.begin(), points.end(), [](const vector<int>& ptA, const vector<int>& ptB) { 
                                                    return ((ptA[0]*ptA[0] + ptA[1]*ptA[1]) < (ptB[0]*ptB[0] + ptB[1]*ptB[1]));
        });

        vector<vector<int>> res(points.begin(), points.begin()+k);

        return res;
    
    }
};
