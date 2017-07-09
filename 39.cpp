class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> t;
        dfs(ans,candidates,t,candidates.size()-1,target);
        return ans;
    }
    void dfs(vector<vector<int>> &ans, vector<int>& candidates,vector<int> x,int f,int n){
        if(n==0){
            ans.push_back(x);
            return;
        }
        if(f<0) return;
        dfs(ans,candidates,x,f-1,n);
        while(n>=candidates[f]){
            n-=candidates[f];
            x.push_back(candidates[f]);
            dfs(ans,candidates,x,f-1,n);
        }
    }
};
