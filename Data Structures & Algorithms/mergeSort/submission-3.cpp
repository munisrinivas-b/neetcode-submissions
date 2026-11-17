// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        vector<Pair> res;

        if(pairs.empty())
            return res;

        // step-1 : Reach base case such that we get into individual element
        int len = pairs.size();

        int mid_idx = len/2;
        int end_idx = len-1;

        mergeSortHelper(pairs, 0, end_idx);
        // mergeSortHelper(pairs, mid_idx+1, end_idx);

        return pairs;
    }

    void mergeSortHelper(vector<Pair>& pairs, int start_idx, int end_idx) {
        
        // base case
        if(start_idx == end_idx) {
            // cout << "base casse: " << pairs[start_idx].key << endl;
            return ;
        }
        
        int mid_idx = (start_idx+end_idx)/2;

        // sort left half
        mergeSortHelper(pairs, start_idx, mid_idx);

        // sort right half
        mergeSortHelper(pairs, mid_idx+1, end_idx);

        // merge by treating the left and right sub arrays seperately
        merge(pairs, start_idx, mid_idx, end_idx);

        // cout << "\n";
    }

    void merge(vector<Pair>& pairs, int s, int m, int e) {
        // bifurcate the pairs into the left and right sub arrays
        vector<Pair> L_arr(pairs.begin()+s, pairs.begin()+m+1);
        vector<Pair> R_arr(pairs.begin()+m+1, pairs.begin()+e+1);

        int i = 0; // poiner for Left array
        int j = 0; // pointer for right array
        int k;

        for(k=s; k<=e; k++) {
            if(i < L_arr.size() && j < R_arr.size()) {
                if(L_arr[i].key <= R_arr[j].key) {
                    pairs[k] = L_arr[i];
                    i++;
                } else {
                    pairs[k] = R_arr[j];
                    j++;
                }
            }
            else {
                // one of them reached the limit
                if (i == L_arr.size()) {
                    pairs[k] = R_arr[j];
                    j++;
                }
                else if (j == R_arr.size()) {
                    pairs[k] = L_arr[i];
                    i++;
                }
                // break;
            }
        }

        
    }
};
