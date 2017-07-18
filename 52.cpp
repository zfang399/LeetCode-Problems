class Solution {
public:
    int totalNQueens(int n) {
        int ans=0;
        vector<pair<int,int>> queen;
        vector<bool> col(n);
        unordered_map<int,bool> sum,diff;
        dfs(ans,queen,1,sum,diff,col,n);
        return ans;
    }
    void dfs(int &ans, vector<pair<int,int>>& queen,int r,unordered_map<int,bool> & sum, unordered_map<int,bool>& diff, vector<bool>& col,int n){
        if(r==n+1){
            ans++;
            return;
        }
        for(int i=1;i<=n;i++){
            if(!col[i] && !sum[r+i] &&!diff[r-i]){
                col[i]=true;
                sum[r+i]=true;
                diff[r-i]=true;
                queen.push_back(make_pair(r,i));
                dfs(ans,queen,r+1,sum,diff,col,n);
                col[i]=false;
                sum[r+i]=false;
                diff[r-i]=false;
                queen.pop_back();
            }
        }
    }
};
