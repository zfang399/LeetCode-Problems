class Solution {
public:
    bool friended[205];
    int findCircleNum(vector<vector<int>>& M) {
        int ans=0;
        for(int i=0;i<M.size();i++){
            if(friended[i]) continue;
            dfs(M,i);
            ans++;
        }
        return ans;
    }
private:
    void dfs(vector<vector<int>>& M,int x){
        friended[x]=true;
        for(int i=0;i<M[x].size();i++){
            if(M[x][i]==1 && !friended[i]){
                dfs(M,i);
            }
        }
    }
};
