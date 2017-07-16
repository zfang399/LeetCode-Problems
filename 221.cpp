class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;
        if(matrix.size()==0) return 0;
        if(matrix[0].size()==0) return 0;
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> ways(m,vector<int>(n));
        if(matrix[0][0]=='1'){
            ans=1;
            ways[0][0]=1;
        }
        for(int i=1;i<m;i++){
            if(matrix[i][0]=='1'){
                ans=1;
                ways[i][0]=1;
            }else{
                ways[i][0]=0;
            }
        }
        for(int i=1;i<n;i++){
            if(matrix[0][i]=='1'){
                ans=1;
                ways[0][i]=1;
            }else{
                ways[0][i]=0;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]=='1'){
                    ways[i][j]=min(min(ways[i-1][j]+1,ways[i][j-1]+1),ways[i-1][j-1]+1);
                    if(ways[i][j]>ans) ans=ways[i][j];
                }
            }
        }
        return ans*ans;
    }
};
