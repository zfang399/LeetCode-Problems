class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==0) return 0;
        if(obstacleGrid[0].size()==0) return 0;
        int ways[100][100]={0};
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]) break;
            ways[i][0]=1;
        }
        for(int i=0;i<n;i++){
            if(obstacleGrid[0][i]) break;
            ways[0][i]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(!obstacleGrid[i][j]) ways[i][j]=ways[i-1][j]+ways[i][j-1];
            }
        }
        return ways[m-1][n-1];
    }
};
