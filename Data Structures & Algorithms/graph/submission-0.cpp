class Graph {
    std::unordered_map<int, unordered_set<int>> graph;
public:
    Graph() {
        // If any intiialisation parameters given
        // this->graph = graph;
    }

    // key = src, value = list of dst
    void addEdge(int src, int dst) {
        if(graph.count(src) == 0) {
            // source does not exits add the source
            graph[src].insert(dst);
            // cout << "Added : " << *graph[src].begin() << endl;
        } else if(src != dst) { // A vertex will not have edge to itself
            // source exists
            unordered_set<int>::iterator itr = graph[src].find(dst);
            if(itr == graph[src].end()) {
                graph[src].insert(dst);
                // cout << "Added : " << *graph[src].begin() << endl;
            }
        }
    }

    bool removeEdge(int src, int dst) {
        bool ret_val = false;
        if(graph.count(src) == 0) {
            // source does not exits
           ret_val = false;
        }

        auto itr = graph[src].find(dst); 
        if(itr == graph[src].end()) {
            // dst doesnot exists
            ret_val = false;
        } else if(itr != graph[src].end()) {
            // dst exists remove that edge
            graph[src].erase(itr);
            ret_val = true;
        }
        return ret_val;
    }

    bool hasPath(int src, int dst) {
        bool path_exists = false;


        cout<<"Graph : \n";
        for(auto key_itr = graph.begin(); key_itr != graph.end(); key_itr++) {
            cout << "Node : " << key_itr->first << endl;
            for(auto set_itr = key_itr->second.begin(); set_itr != key_itr->second.end(); set_itr++) {
                cout << "child : " << *set_itr << endl;
            }
        } 

        // If source node doesnot exists in the graph return false
        if ((graph.count(src) == 0)) {
            cout << "Src DNE!!\n";
            return false;
        }
            

        // DFS to check for the nodes
        dfsHelper(graph, src, dst, path_exists);

        return path_exists;
    }   

    void dfsHelper(std::unordered_map<int, unordered_set<int>>& graph, 
    const int& src,
    int& dst,
    bool& path_exists) {

        cout << "Node : " << src << endl;
        auto itr = graph.find(src);
        if(itr != graph.end()) {
            for(auto set_itr = itr->second.begin(); set_itr != itr->second.end(); set_itr++) {
                cout << "Child : " << *set_itr << endl;
                if(*set_itr == dst) {
                    path_exists = true;
                    cout << "Path exists\n";
                    return ;
                }
                dfsHelper(graph, *set_itr, dst, path_exists);
            }
        }

        return;
    }

};
