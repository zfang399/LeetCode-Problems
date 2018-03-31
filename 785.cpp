class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> isa(graph.size(), false);
        vector<bool> marked(graph.size(), false);
        vector<bool> vis(graph.size(), false);
        marked[0] = true;
        isa[0] = true;
        for(int i = 0; i < graph.size(); i++){
            if(vis[i]) continue;
            if(!dfs(graph, isa, marked, vis, i)) return false;
        }
        return true;
    }

    bool dfs(vector<vector<int>>& graph, vector<bool>& isa, vector<bool>& marked, vector<bool>& vis, int cur){
        vis[cur] = true;
        for(int i = 0; i < graph[cur].size(); i++){
            int x = graph[cur][i];
            if(marked[x]){
                if(isa[x] == isa[cur]) return false;
            }else{
                marked[x] = true;
                isa[x] = !isa[cur];
            }
        }

        for(int i = 0; i < graph[cur].size(); i++){
            int x = graph[cur][i];
            if(vis[x]) continue;
            if(!dfs(graph,isa,marked,vis,x)) return false;
        }

        return true;
    }
};
