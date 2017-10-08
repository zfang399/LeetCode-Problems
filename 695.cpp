class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        if(!row) return 0;
        int col=grid[0].size();
        if(!col) return 0;
        int ans=0;
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j] && grid[i][j]){
                    ans=max(ans,dfs(grid,vis,i,j,row,col));
                }
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j, int row, int col){
        int ret=1;
        vis[i][j]=true;
        if(i-1>=0){
            if(grid[i-1][j] && !vis[i-1][j]){
                ret+=dfs(grid,vis,i-1,j,row,col);
            }
        }
        if(i+1<row){
            if(grid[i+1][j] && !vis[i+1][j]){
                ret+=dfs(grid,vis,i+1,j,row,col);
            }
        }
        if(j-1>=0){
            if(grid[i][j-1] && !vis[i][j-1]){
                ret+=dfs(grid,vis,i,j-1,row,col);
            }
        }
        if(j+1<col){
            if(grid[i][j+1] && !vis[i][j+1]){
                ret+=dfs(grid,vis,i,j+1,row,col);
            }
        }
        return ret;
    }
};
