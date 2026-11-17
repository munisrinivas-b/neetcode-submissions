class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Take each row and check if the target exists in that range using the row limits
        // Once a row is finalized then run a binary search on the row to check for the element

        int ret_val = false;
        for(int i = 0; i < matrix.size(); i++) {
            vector<int> row_vec = matrix[i];
            int first_ele = row_vec[0];
            int last_ele = row_vec[row_vec.size() - 1];

            if((target == first_ele) || (target == last_ele)) {
                return true;
            } else if ((target > first_ele) && (target < last_ele)) {
                // perform bin_search
                int s = 0; // start idx
                int e = row_vec.size() - 1; // end idx
                ret_val = bin_search(row_vec, s, e, target);
                cout << "Row hit : " << i << endl;
            } 
        }

        return ret_val;
    }

    bool bin_search(vector<int>& vec, int s, int e, int target) {
        bool ret_val = false;
        if (s > e) { // exit condition
            return ret_val;
        }

        int m = s + (e-s)/2; // stable way to compute the mid idx

        if (target == vec[m]) {
            // cout << "Traget matched " << target <<  endl;
            ret_val = true;
        } else if(target < vec[m]) {
            // pass left sub array
            ret_val = bin_search(vec, s, m-1, target);
        } else if(target > vec[m]) {
            // pass rigjt sub array
            ret_val = bin_search(vec, m+1, e, target);
        }

        return ret_val;
    }
};
