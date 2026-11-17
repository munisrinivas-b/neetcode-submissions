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
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> final_res;

        if (pairs.size() == 0)
        {
            return final_res;
        }

        // assuming first term to be sorted already
        final_res.push_back(pairs);

        for(int i=1; i<pairs.size(); i++)
        {
            // iterate through each element (except first)
            for(int j = i; j > 0 ; j--)
            {
                // if current value is less than previous
                // swap
                if(pairs[j].key < pairs[j-1].key)
                {
                    Pair tmp(pairs[j]);
                    pairs[j] = pairs[j-1];
                    pairs[j-1] = tmp;
                }
            }
            final_res.push_back(pairs);
        }

        return final_res;
    }
};
