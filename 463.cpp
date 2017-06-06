class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int is[105][105]={0};
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                is[i+1][j+1]=grid[i][j];
            }
        }
        for(int i=1;i<=grid.size();i++){
            for(int j=1;j<=grid[0].size();j++){
                if(is[i][j]) ans+=4*is[i][j]-is[i-1][j]-is[i+1][j]-is[i][j+1]-is[i][j-1];
            }
        }
        return ans;
    }
};
