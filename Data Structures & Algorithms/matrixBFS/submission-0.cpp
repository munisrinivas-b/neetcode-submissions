class Solution {
public:
    int shortestPath(vector<vector<int>>& grid) {
        
        int n_rows = grid.size();
        int n_cols = grid[0].size();

        if (grid[n_rows-1][n_cols-1] == 1) {
            // Goal location has a rock, cannot be reached
            return -1;
        }

        int max_path_len = helper(grid, n_rows, n_cols);

        return max_path_len;
    }

    // Iterative BFS
    int helper(vector<vector<int>>& grid, const int& n_rows, const int& n_cols) {
        vector<int> path_length;
        int max_path_len = -1; // set to Null initially

        // Queue stores the list of visited nodes and distance associated
        std::deque<std::tuple<int, int, int>> node_q;

        std::vector<std::pair<int, int>> neigh_node = {{0,1}, {0,-1}, {1,0}, {-1,0}}; // right, left, down, up

        node_q.push_back(std::tuple<int, int, int>(0, 0, 0)); //OR
        // node_q.push_back({0, 0, 0}); //OR
        // node_q.emplace_back(0, 0, 0);

        while(!node_q.empty()) {
            // Pop unitl there exists a node to expand
            std::tuple<int, int, int> curr_node = node_q.front();
            node_q.pop_front();

            // Mark the visited node as travelled ==> """unmarking this step lead to Seg fault"""
            grid[get<0>(curr_node)][get<1>(curr_node)] = 1;

            // cout << "Curr node : " << curr_node.first << " , " << curr_node.second << endl;
            // calcualte the possible neighbours of this node and store it in queue
            for(int i=0; i<neigh_node.size(); i++) {
                std::pair<int, int> possible_node(get<0>(curr_node)+neigh_node[i].first, get<1>(curr_node)+neigh_node[i].second);
                // if the possible node is not rock/ not out of the bounds ==> save it to the queue
                // cout << possible_node.first << " , " << possible_node.second << endl;
                
                if((possible_node.first < 0) || (possible_node.second < 0) || (possible_node.first >= n_rows) || (possible_node.second >= n_cols)) {
                    // Ignore out of bounds
                    continue;
                }

                if(grid[possible_node.first][possible_node.second] == 1) {
                    // encountered rock, Ignore
                    continue;
                }

                node_q.push_back(make_tuple(possible_node.first, possible_node.second, get<2>(curr_node)+1));
            }

            if((get<0>(curr_node) == n_rows-1) && (get<1>(curr_node) == n_cols-1)) {
                // goal_reached
                cout << "Goal reched\n";
                return get<2>(curr_node);
            }

        }

        return max_path_len;
    }
};
