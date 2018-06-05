class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>> connect(N);
        vector<int> count(N, 0);
        vector<int> dist(N,0);
        vector<bool> vis(N,false);
        vector<bool> visited(N,false);

        for(int i = 0; i < edges.size(); i++){
            connect[edges[i][0]].push_back(edges[i][1]);
            connect[edges[i][1]].push_back(edges[i][0]);
        }

        postorder(0, vis, connect, count, dist);
        preorder(0, visited, connect, count, dist, N);
        return dist;
    }

    void postorder(int root, vector<bool>& vis, vector<vector<int>>& connect, vector<int>& count, vector<int>& dist){
        vis[root] = true;
        for(int i = 0; i < connect[root].size(); i++){
            if(!vis[connect[root][i]]){
                postorder(connect[root][i], vis, connect, count, dist);
                count[root] += count[connect[root][i]];
                dist[root] += count[connect[root][i]] + dist[connect[root][i]];
            }
        }
        count[root] += 1;
    }

    void preorder(int root, vector<bool>& vis, vector<vector<int>>& connect, vector<int>& count, vector<int>& dist, int N){
        vis[root] = true;
        for(int i = 0; i < connect[root].size(); i++){
            if(!vis[connect[root][i]]){
                dist[connect[root][i]] = dist[root] - 2 * count[connect[root][i]] + N;
                preorder(connect[root][i], vis, connect, count, dist, N);
            }
        }
    }
};
