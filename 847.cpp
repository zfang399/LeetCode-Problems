class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size() == 1) return 0;
        int ans = 0;
        queue<int> n; // queue for current nodes
        queue<vector<bool>> vis; // queue for the current visit status
        map<pair<vector<bool>, int>, bool> mem; // memory map, trade space for time
        vector<bool> v(graph.size(), false); // vector to make saving easier
        int counter = graph.size(); // variable to keep track of steps
        // Initialize queues
        for(int i = 0; i < graph.size(); i++){
            n.push(i);
            vector<bool> tmp = v;
            tmp[i] = true;
            vis.push(tmp);
            mem[make_pair(tmp, i)] = true;
        }
        // BFS
        while(n.size()){
            counter--;
            int cur_node = n.front();
            vector<bool> cur_vis = vis.front();
            n.pop();
            vis.pop();
            for(int i = 0; i < graph[cur_node].size(); i++){
                int togo = graph[cur_node][i];
                vector<bool> tmp = cur_vis;
                tmp[togo] = true;
                if(mem[make_pair(tmp, togo)]) continue; // continue if this combination has already been tried
                bool finished = true;
                for(int j = 0; j < tmp.size(); j++){
                    if(!tmp[j]){
                        finished = false;
                        break;
                    }
                }
                if(finished) return ans + 1;
                // push to queues and save to memory
                n.push(togo);
                vis.push(tmp);
                mem[make_pair(tmp, togo)] = true;
            }
            if(counter == 0){
                ans++;
                counter = n.size();
            }
        }
        return ans;
    }
};
