class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int N = quiet.size();
        vector<vector<int>> richerlist(N);
        vector<int> vis(N, -1);
        vector<int> ans;
        for(int i = 0; i < richer.size(); i++){
            richerlist[richer[i][1]].push_back(richer[i][0]);
        }

        for(int i = 0; i < N; i++){
            if(vis[i] == -1){
                dfs(richerlist, vis, quiet, i);
            }
            ans.push_back(vis[i]);
        }

        return ans;
    }

    int dfs(vector<vector<int>>& richerlist, vector<int>& vis, vector<int>& quiet, int p){
        vis[p] = p;
        for(int i = 0; i < richerlist[p].size(); i++){
            if(vis[richerlist[p][i]] == -1){
                dfs(richerlist, vis, quiet, richerlist[p][i]);
            }
            vis[p] = quiet[vis[p]] > quiet[vis[richerlist[p][i]]] ? vis[richerlist[p][i]] : vis[p];
        }

        return vis[p];
    }
};
