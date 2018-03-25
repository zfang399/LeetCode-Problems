class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> n;
        dfs(0,graph.size()-1,n,graph,ans);
        return ans;
    }
    void dfs(int current, int target, vector<int> path, vector<vector<int>>& graph, vector<vector<int>> &ans){
        path.push_back(current);
        if(current == target){
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < graph[current].size(); i++){
            dfs(graph[current][i],target,path,graph,ans);
        }
        return;
    }
};
