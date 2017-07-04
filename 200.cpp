class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        if(grid.size()==0) return ans;
        if(grid[0].size()==0) return ans;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    ans++;
                    findland(grid,i,j);
                }
            }
        }
        return ans;
    }
    void findland(vector<vector<char>>& grid, int x, int y){
        if(grid[x][y]=='0') return;
        grid[x][y]='0';
        if(x-1>=0) findland(grid,x-1,y);
        if(x+1<grid.size()) findland(grid,x+1,y);
        if(y-1>=0) findland(grid,x,y-1);
        if(y+1<grid[0].size()) findland(grid,x,y+1);
    }
};
