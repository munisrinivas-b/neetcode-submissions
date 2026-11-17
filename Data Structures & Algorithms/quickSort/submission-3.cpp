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
        // Inplace sorting
        // int mid_idx = (pairs.size()-1)/2;
        int end_idx = (pairs.size()-1);
        quickSortHelper(pairs, 0, end_idx);

        return pairs;
        
    }

    void quickSortHelper(vector<Pair>&pairs, int s, int e) {
        if ((s == e) || (s > e)) {
            return ;
        }

        // step1: Bring the small elements to the left of the pivot
        int i = s;
        int j = s;
        int pivot = e;

        while(i < pivot) {
            if(pairs[i].key >= pairs[pivot].key) {
                i++;
            } else if(pairs[i].key < pairs[pivot].key) {
                Pair temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
                j++;
                i++; 
            }
        }
        // now i == pivot, final swap with jth index
        Pair temp = pairs[j];
        pairs[j] = pairs[pivot];
        pairs[pivot] = temp;

        // step2: redo the same to the subarrys on the left and right side of the modified pivot
        // step2a: left arr
        quickSortHelper(pairs, s, j-1);

        // step2b: right arr
        quickSortHelper(pairs, j+1, e);
    
    }
};
