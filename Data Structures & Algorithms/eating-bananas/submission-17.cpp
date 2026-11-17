class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {
        cout << sizeof(int) << endl;
        // write a function that returns the number of banans left starting
        // wiht rate k = 1 to max(piles)
        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());
        int ret_val = right;
        
        // starting with k = 0, bug - divide by zero
        // for(int k = 1; k <= *std::max_element(piles.begin(), piles.end()); k++) {
           while(left <= right) {
            int mid = left + (right-left)/2;
            // for each of these "k", find the number of bananas remaining
            // if it is positive, break out of the loop and check for next "k"
            
            int h_tmp = h;

            if (mid > 142857000 && mid < 142857200){
                cout << "Left : " <<  left << ", RIght : " << right << endl;
            }
            
            for(int i = 0; i < piles.size(); i++) {
                int bans = piles[i];
                int bans_per_hr = mid;
                int time_req_this_pile =  (bans + bans_per_hr - 1) / bans_per_hr;//ceil(float(bans)/float(bans_per_hr));//
                // if (mid > 142857000 && mid < 142857200){
                //     cout << "Time req : " << time_req_this_pile <<endl;
                // }
                h_tmp = h_tmp - time_req_this_pile;
                // cout << "Idx : " << i << " ,h_rem " << h_tmp << endl;
                if (h_tmp < 0) {
                    // no time left, hence increment "k" and continue
                    left = mid + 1;
                    break;
                }
            }
            if (mid > 142857000 && mid < 142857200){
                cout << "K : " << mid << " Remainig hrs : " << h_tmp << endl;
            }
                
            if ( h_tmp >= 0) {
                // all the bananas are eaten and still there exists some time
                // return k;
                right = mid - 1;
                if(ret_val >= mid) {
                    ret_val = mid;
                }
            }

        }
        return ret_val;
    }
};
