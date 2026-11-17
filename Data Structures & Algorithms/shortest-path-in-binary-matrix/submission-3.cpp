class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // can visit - 0
        // Traversal - 8 directions
        int n_rows = grid.size();
        int n_cols = grid[0].size();

        // If the goal node has the value 1, return -1 as it not reachable
        if((grid[n_rows-1][n_cols-1] == 1) || (grid[0][0] == 1)) 
            return -1;

        std::vector<std::pair<int, int>> neigh_nodes = {
            {-1,-1},
            {-1,0},
            {-1,1},
            {0,-1},
            {0,1},
            {1,-1},
            {1,0},
            {1,1}
        };

        int shortest_dist = helper(grid, neigh_nodes, n_rows, n_cols);

        return shortest_dist;    
    }

    int helper(vector<vector<int>>& grid, std::vector<std::pair<int, int>>& neigh_nodes, const int& n_rows, const int& n_cols) {
        int shortest_path = -1;
        
        // Have a queue that stores the nodes and distance from the origin
        std::deque<std::tuple<int, int, int>> node_dist_q;
        node_dist_q.push_back({0,0,1});

        //Iterate through the queue and check for the goal node
        while(!node_dist_q.empty()) {
            cout << "In while\n";
            std::tuple<int, int, int> curr_node = node_dist_q.front();
            node_dist_q.pop_front();
            
            // unpack curr_node tuple to get the current node's row, col, dist
            auto [r,c,dist] = curr_node; // row, col, dist
            cout << "Curr node : " << r << " , " << c << " , " << dist << endl;
            // check the neighbors of this node
            for(int i=0; i<neigh_nodes.size(); i++) {
                std::pair<int, int> neigh_node(r+neigh_nodes[i].first ,c+neigh_nodes[i].second);
                cout << "possible neigh : " << neigh_node.first << ", " << neigh_node.second <<  " , " <<  dist <<  endl;
                // ignore the node if the deduced node is out of the map
                if((neigh_node.first < 0) || (neigh_node.second < 0) || (neigh_node.first >= n_rows) || (neigh_node.second >= n_cols)) {
                    continue;
                }
                
                // Ignore the node if it is non-traversable
                if(grid[neigh_node.first][neigh_node.second] == 1)  {
                    continue;
                }

                // If reached to goal node, return
                if((neigh_node.first == n_rows-1) && (neigh_node.second == n_cols-1))  {
                    return dist+1;
                }

                cout << "Added to q : " << neigh_node.first << ", " << neigh_node.second <<  " , " <<  dist <<  endl;
                // add it to the queue
                node_dist_q.push_back(std::make_tuple(neigh_node.first, neigh_node.second, dist+1));
            }
            // Mark the node visited
            grid[r][c] = 1;
        }

        return shortest_path;
    }

};