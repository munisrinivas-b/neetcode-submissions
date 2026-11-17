class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        // store a list of rotten fruits, perform BFS on them parallely
        std::deque<std::pair<int, int>> rot_q;
        int n_rows = grid.size();
        int n_cols = grid[0].size();

        // store the number of good fruits, 
        // If the time taken to rot the fruit exceeds the number of good fruits then
        // it is not possible to rot the good fruits (and queue is non-empty)
        // return -1
        int good_fruits_no = 0;
        int time = 0;

        for(int r=0; r<n_rows; r++) {
            for(int c=0; c<n_cols; c++) {
                // store the rotten fruits
                if (grid[r][c] == 2){
                    rot_q.push_back(std::make_pair(r, c));
                }

                if (grid[r][c] == 1){
                    good_fruits_no++;
                }
            }
        }
        
        std::vector<std::pair<int, int>> neigh_nodes = {
            {-1, 0},
            {0, -1},
            {0, 1},
            {1, 0}
        };

        
        int nodes_added_in_time_step = 1;

        while(!rot_q.empty() && good_fruits_no > 0) {
            time++;

            int nodes_to_explore = nodes_added_in_time_step;
            nodes_added_in_time_step = 0;

            cout << "Nodes to explore : " <<  nodes_to_explore << endl;

            while(nodes_to_explore > 0) {
                std::pair<int, int> curr_node = rot_q.front();
                rot_q.pop_front();

                for(int i=0; i<neigh_nodes.size(); i++) {
                    int r = neigh_nodes[i].first;
                    int c = neigh_nodes[i].second;
                    std::pair<int, int> neigh_node(curr_node.first+r, curr_node.second+c);

                    // If the node goes out of the grid - skip
                    if((neigh_node.first < 0) || (neigh_node.second < 0) || (neigh_node.first >= n_rows) || (neigh_node.second >= n_cols)) {
                        continue;
                    }

                    // If the node value is 0 - empty cell - skip
                    // If the node value is 2 - already persent in the queue - skip
                    if((grid[neigh_node.first][neigh_node.second] == 0) || (grid[neigh_node.first][neigh_node.second] == 2)) {
                        continue;
                    }

                    nodes_added_in_time_step++; // nodes to explore in next minute
                
                    // Mark the node rotten and reduce the good fruits count
                    grid[neigh_node.first][neigh_node.second] = 2; good_fruits_no--;
                    rot_q.push_back(std::make_pair(neigh_node.first, neigh_node.second));
                }
                nodes_to_explore--;

            }
            
        }

        // If we the good fruits still remain then return -1
        if(good_fruits_no != 0) {
            return -1;
        }

        return time;
    }
};
