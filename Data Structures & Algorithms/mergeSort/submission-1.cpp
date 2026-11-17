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
        if(pairs.empty())
            return pairs;
        // recurively split into two halves
        // track the indexes while splitting
        // one for left half and the other for right half
        vector<Pair> res_arr;

        int start_idx  = 0;
        int end_idx = pairs.size()-1;
        int mid_idx = end_idx/2;

        // cout << start_idx << " , " << mid_idx << "  , " << end_idx;
        res_arr = split(start_idx, mid_idx, end_idx, pairs);
        return res_arr;
    }

    // function that splits the left-right halves recursively at mid location
    vector<Pair> split(int s, int m, int e, vector<Pair>& pairs)
    {
        cout << s << " , " << m << " , " << e << endl;
        vector<Pair> res;

        //  Base case to end recursion
        if(s==e)
        {   
            res.push_back(pairs[s]);
            return res;
        }

        // e = m;
        // m = (s+e)/2;

        vector<Pair> res_lef = split( s, (s+m)/2, m, pairs);
        vector<Pair> res_rt = split( m+1, (m+1+e)/2, e, pairs);


        cout << "sizes l,r : " << res_lef.size() <<  " , " << res_rt.size() << endl;

        cout << res_lef[0].key << "  , " << res_rt[0].key <<  endl;
        
        // merge by comparing the above arrays
        // Merge step
        int lef_idx = 0, rt_idx = 0;
        while(lef_idx < res_lef.size() && rt_idx < res_rt.size()) {
            if(res_lef[lef_idx].key <= res_rt[rt_idx].key) {
                res.push_back(res_lef[lef_idx]);
                lef_idx++;
            }

            if(res_lef[lef_idx].key > res_rt[rt_idx].key) {
                res.push_back(res_rt[rt_idx]);
                rt_idx++;
            }
        }

        // merge contd.
        // Fill the remaining part present in the large array
        if(lef_idx < res_lef.size()) {
            while(lef_idx < res_lef.size()) {
                res.push_back(res_lef[lef_idx]);
                lef_idx++;
            }
        }else if(rt_idx < res_rt.size()){
            while(rt_idx < res_rt.size()) {
                res.push_back(res_rt[rt_idx]);
                rt_idx++;
            }
        }

        cout << "merge result : " << endl;
        for(int i = 0; i<res.size(); i++)
        {
            cout << res[i].key << endl;
        }
        return res;
    }
};
