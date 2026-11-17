class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int n_rows = grid.size();
        int n_cols = grid[0].size();

        // Target is that when we reach grid[n_rows-1][n_cols-1]
        // save all the paths and return its size
        
        vector<vector<int>> map_hist = grid; // store the traversed locations, unique to each call
        int count = 0; // Counts number of traversable paths, pass by ref
        int row_idx = 0;
        int col_idx = 0;

        helper(grid, map_hist, count, row_idx, col_idx, n_rows, n_cols);

        return count;
    }

    void helper(vector<vector<int>>& grid, vector<vector<int>> map_hist, int& count, int row_idx, int col_idx, const int& n_rows, const int& n_cols) {
        // cout << "row_idx : " << row_idx << "\t col_idx : " << col_idx << endl;
        // for(int i = 0 ; i < map_hist.size(); i++) {
        //     for(int j = 0; j < map_hist[0].size(); j++) {
        //         cout << map_hist[i][j] << " , " ;
        //     }
        //     cout << "\n";
        // }
        // Base cases
        // 1. If the row_idx and col_idx goes out of the bounds, simply return(Do nothing)
        if((row_idx >= n_rows) || (col_idx >= n_cols) || (row_idx < 0) || (col_idx < 0)) {
            // out of the map
            return;
        }

        // 2. If we are in the goal state currently, increment the counter and return
        if((row_idx == n_rows-1) && (col_idx == n_cols-1)) {
            if(map_hist[row_idx][col_idx] != 1)
                count+=1;
            return;
        }

        // 3. If we are on the rock or already visited node, simply return
        if(map_hist[row_idx][col_idx] == 1) {
            return;
        }

        // update the current idx = 1
        map_hist[row_idx][col_idx] = 1; // Mark the current node visited

        helper(grid, map_hist, count, row_idx, col_idx+1, n_rows, n_cols);
        helper(grid, map_hist, count, row_idx+1, col_idx, n_rows, n_cols);
        helper(grid, map_hist, count, row_idx, col_idx-1, n_rows, n_cols);
        helper(grid, map_hist, count, row_idx-1, col_idx, n_rows, n_cols);

        // map_hist[row_idx][col_idx] = 0;

    }
};
