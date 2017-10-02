class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(K+1,vector<vector<double>>(N,vector<double>(N,-1.0)));
        return dfs(dp,N,K,r,c);
    }
    double dfs(vector<vector<vector<double>>>& dp, int N, int K, int r, int c){
        if(r<0 || r>=N || c<0 || c>=N) return 0;
        if(K==0) return 1.0;
        if(dp[K][r][c]!=-1.0) return dp[K][r][c];
        double ret=0.0;
        ret+=dfs(dp,N,K-1,r-2,c+1)/8;
        ret+=dfs(dp,N,K-1,r-2,c-1)/8;
        ret+=dfs(dp,N,K-1,r+2,c+1)/8;
        ret+=dfs(dp,N,K-1,r+2,c-1)/8;
        ret+=dfs(dp,N,K-1,r-1,c+2)/8;
        ret+=dfs(dp,N,K-1,r-1,c-2)/8;
        ret+=dfs(dp,N,K-1,r+1,c+2)/8;
        ret+=dfs(dp,N,K-1,r+1,c-2)/8;
        dp[K][r][c]=ret;
        return ret;
    }
};
