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
    vector<Pair> quickSort(vector<Pair>& pairs) {
        // In place sort, no memeory allocation needed, nothing to return
        if (pairs.empty()) {
            return pairs;
        }
        quickSortHelper(pairs, 0, pairs.size()-1);
        return pairs;
    }

    void quickSortHelper(vector<Pair>& pairs, int start_idx, int end_idx) {
        // cout << "Hit\n" << start_idx << "  , " << end_idx << endl;
        int piv_idx = end_idx;//pairs.size()-1;
        int piv_val = pairs[piv_idx].key;

        if( end_idx-start_idx < 1) {
            // cout << "void return\n";
            return ;
        }

        int i = start_idx;
        for(int itr=start_idx; itr <= end_idx; itr++) {
            if(pairs[itr].key < piv_val) {
                //swap
                Pair tmp = pairs[i];
                pairs[i] = pairs[itr];
                pairs[itr] = tmp;
                i++;
            }
        }

        swap(pairs[piv_idx], pairs[i]);

        // cout << "New function : \n";
        // for(int i = 0; i<pairs.size(); i++)
        // {
        //     cout << pairs[i].key << " , " << pairs[i].value << endl;
        // }

        quickSortHelper(pairs, start_idx, i-1);
        quickSortHelper(pairs,  i+1,  end_idx);

    }

};
