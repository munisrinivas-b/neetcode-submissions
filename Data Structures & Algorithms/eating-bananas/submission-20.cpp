class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int k=0;
        int s = 1;
        int e = *std::max_element(piles.begin(), piles.end()); 
        
        int final_k = k;

        while(s <= e){
            k = s + (e-s)/2;

            vector<int> piles_copy(piles);
            int h_copy = h;

            for(int i :  piles_copy) {
                h_copy = h_copy - (i + k - 1) / k; // this is the trick here
                if (h_copy < 0) {
                    s = k+1;
                    // insufficient hours, increaese eating_bans/hr i.e, k
                    break;
                }
            }

            if (h_copy >= 0) {
                // sufficient hours, return k
                // return k;
                final_k = k;
                e = k-1;
            }
        }

        return final_k;
    }
};
