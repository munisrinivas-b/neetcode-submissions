class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n_rows = grid.size();
        int n_cols = grid[0].size();

        int land_count = 0; // count the islands

        for(int i = 0; i < n_rows; i++){
            for(int j = 0; j < n_cols; j++){
                if(grid[i][j] == '1') {
                    // incement land counter if we find a land
                    land_count++;
                    //Run DFS from  it
                    dfs(grid, i, j, n_rows, n_cols);
                }
            }
        }

        return land_count;
    }

    void dfs(vector<vector<char>>& grid, int row_idx, int col_idx, const int& n_rows, const int& n_cols) {
        // Base cases
        // 1. If the current row_idx and col_idx go out of bound, return
        if((row_idx >= n_rows) || (col_idx >= n_cols) || (row_idx < 0) || (col_idx < 0)) {
            return;
        }

        //2. If we reach a water tile, return
        if(grid[row_idx][col_idx] == '0') {
            // Reached boundary
            return;
        }

        // set the current node visited, so that it will not be visited again
        grid[row_idx][col_idx] = '0';

        dfs(grid, row_idx, col_idx+1, n_rows, n_cols);
        dfs(grid, row_idx-1, col_idx, n_rows, n_cols);
        dfs(grid, row_idx, col_idx-1, n_rows, n_cols);
        dfs(grid, row_idx+1, col_idx, n_rows, n_cols);
    }
};
