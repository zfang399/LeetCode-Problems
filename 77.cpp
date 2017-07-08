class Solution {
public:
    vector<vector<int>> ans;
    unordered_map <int,bool> visited;
    vector<vector<int>> combine(int n, int k) {
        if(n<k) return ans;
        vector<int> x;
        dfs(k,n,1,x);
        return ans;
    }
    void dfs(int r,int n, int f,vector<int> x){
        if(r==0){
            ans.push_back(x);
            return;
        }
        if(n-f+1<r) return;
        for(int i=f;i<=n;i++){
            x.push_back(i);
            dfs(r-1,n,i+1,x);
            x.erase(x.begin()+x.size()-1);
        }
    }
};
