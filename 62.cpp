class Solution {
public:
    int uniquePaths(int m, int n) {
        int ways[100][100]={0};
        for(int i=0;i<m;i++) ways[i][0]=1;
        for(int i=1;i<n;i++) ways[0][i]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                ways[i][j]=ways[i-1][j]+ways[i][j-1];
            }
        }
        return ways[m-1][n-1];
    }
};
