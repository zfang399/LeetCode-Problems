class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        if(grid[0][0] == m*m-1 || grid.back().back() == m*m-1) return m*m-1;
        vector<vector<bool>> vis(m,vector<bool>(m,false));
        int f = max(grid[0][0], grid.back().back());
        int r = m*m-1;
        int mid;
        while(f < r){
            mid = (f+r)/2;
            for(int i = 0; i < vis.size(); i++){
                for(int j = 0; j < vis.size(); j++){
                    vis[i][j] = false;
                }
            }
            if(dfs(grid,vis,0,0,mid)){
                r = mid;
            }else{
                f = mid + 1;
            }
        }
        return r;
    }
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int x, int y, int limit){
        if(x == grid.size()-1 && y == grid.size()-1) return true;
        vis[x][y] = true;
        if(x - 1 >= 0){
            if(!vis[x-1][y] && grid[x-1][y] <= limit){
                if(dfs(grid,vis,x-1,y,limit)){
                    return true;
                }
            }
        }
        if(x + 1 < grid.size()){
            if(!vis[x+1][y] && grid[x+1][y] <= limit){
                if(dfs(grid,vis,x+1,y,limit)){
                    return true;
                }
            }
        }
        if(y - 1 >= 0){
            if(!vis[x][y-1] && grid[x][y-1] <= limit){
                if(dfs(grid,vis,x,y-1,limit)){
                    return true;
                }
            }
        }
        if(y + 1 < grid[0].size()){
            if(!vis[x][y+1] && grid[x][y+1] <= limit){
                if(dfs(grid,vis,x,y+1,limit)){
                    return true;
                }
            }
        }
        return false;
    }
};
