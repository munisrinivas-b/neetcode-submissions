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
        vector<vector<Pair>> result; //vector that stores the interim results

        if(pairs.empty())
            return result;


        result.push_back(pairs); //inital state

        for(int i=1; i < pairs.size(); i++) {
            // cout << pairs[i].key << " , " << pairs[i].value << endl;
            int j = i-1;

            while(j >= 0 && (pairs[j+1].key < pairs[j].key)) {
                Pair temp(pairs[j+1].key, pairs[j+1].value);
                // temp = pairs[j+1];
                pairs[j+1] = pairs[j];
                pairs[j] = temp;
                j--;
            }
            result.push_back(pairs);
        }

        return result;
    }
};
