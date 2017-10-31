class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int ans=0;
        int alen=A.size(),blen=B.size();
        vector<vector<int>> dp(alen,vector<int>(blen,0));
        for(int i=0;i<alen;i++){
            for(int j=0;j<blen;j++){
                if(A[i]==B[j]){
                    if(i==0 || j==0){
                        dp[i][j]=1;
                        if(dp[i][j]>ans) ans=dp[i][j];
                        continue;
                    }
                    dp[i][j]=dp[i-1][j-1]+1;
                    if(dp[i][j]>ans) ans=dp[i][j];
                }
            }
        }
        return ans;
    }
};
