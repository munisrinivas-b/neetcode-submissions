class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<int> area_vec; // count the number of lands in each iteration
        vector<int> final_area_vec;

        int n_rows = grid.size();
        int n_cols = grid[0].size();

        for(int i = 0 ; i < n_rows; i++) {
            for(int j = 0; j < n_cols; j++) {
                if(grid[i][j] == 1) {
                    // Start with the island that has a 1 (land)
                    area_vec.clear();
                    int area = helper(grid, i, j, n_rows, n_cols, area_vec);
                    final_area_vec.push_back(area);
                }
            }
        }

        if(final_area_vec.size() == 0) {
            return 0;
        }

        return *std::max_element(final_area_vec.begin(), final_area_vec.end());
    }

    int helper(vector<vector<int>>& grid, int row_idx, int col_idx, const int& n_rows, const int& n_cols, vector<int>& area_vec) {
        // Base cases
        // 1. If the indexes reaches outof bounds simply return
        if((row_idx >= n_rows) || (col_idx >= n_cols) || (row_idx < 0) || (col_idx < 0)) {
            return std::accumulate(area_vec.begin(), area_vec.end(), 0);
        }

        // 2. If we entered water return
        if (grid[row_idx][col_idx] == 0) {
            return std::accumulate(area_vec.begin(), area_vec.end(), 0);
        }

        // push the land vector to add it later
        area_vec.push_back(grid[row_idx][col_idx]);
        // Mark the visited island 0
        grid[row_idx][col_idx] = 0;


        helper(grid, row_idx+1, col_idx, n_rows, n_cols, area_vec);
        helper(grid, row_idx-1, col_idx, n_rows, n_cols, area_vec);
        helper(grid, row_idx, col_idx+1, n_rows, n_cols, area_vec);
        helper(grid, row_idx, col_idx-1, n_rows, n_cols, area_vec);

        return std::accumulate(area_vec.begin(), area_vec.end(), 0);
    }
};
