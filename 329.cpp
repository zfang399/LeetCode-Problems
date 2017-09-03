class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& m) {
        if(!m.size()) return 0;
        int r=m.size();
        if(!m[0].size()) return 0;
        int c=m[0].size();
        int ans=0;
        vector<vector<int>> p(r,vector<int>(c,0));
        vector<vector<bool>> v(r,vector<bool>(c,false));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!v[i][j]){
                    dfs(m,p,v,i,j);
                    ans=max(ans,p[i][j]);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& m,vector<vector<int>>& p,vector<vector<bool>>& v,int x, int y){
        v[x][y]=true;
        p[x][y]=1;
        if(x-1>=0){
            if(m[x][y]<m[x-1][y]){
                if(v[x-1][y]){
                    p[x][y]=max(p[x][y],p[x-1][y]+1);
                }else{
                    dfs(m,p,v,x-1,y);
                    p[x][y]=max(p[x][y],p[x-1][y]+1);
                }
            }
        }
        if(x+1<m.size()){
            if(m[x][y]<m[x+1][y]){
                if(v[x+1][y]){
                    p[x][y]=max(p[x][y],p[x+1][y]+1);
                }else{
                    dfs(m,p,v,x+1,y);
                    p[x][y]=max(p[x][y],p[x+1][y]+1);
                }
            }
        }
        if(y-1>=0){
            if(m[x][y]<m[x][y-1]){
                if(v[x][y-1]){
                    p[x][y]=max(p[x][y],p[x][y-1]+1);
                }else{
                    dfs(m,p,v,x,y-1);
                    p[x][y]=max(p[x][y],p[x][y-1]+1);
                }
            }
        }
        if(y+1<m[0].size()){
            if(m[x][y]<m[x][y+1]){
                if(v[x][y+1]){
                    p[x][y]=max(p[x][y],p[x][y+1]+1);
                }else{
                    dfs(m,p,v,x,y+1);
                    p[x][y]=max(p[x][y],p[x][y+1]+1);
                }
            }
        }
    }
};
