class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int l=s.length();
        vector<vector<int>> dp(l,vector<int>(l));
        for(int i=0;i<l;i++){
            dp[i][i]=1;
            for(int j=i-1;j>=0;j--){
                if(s[i]==s[j]){
                    dp[i][j]=dp[i-1][j+1]+2;
                }else{
                    dp[i][j]=max(dp[i][j+1],dp[i-1][j]);
                }
                //cout<<dp[i][j]<<endl;
            }
        }
        return dp[l-1][0];
    }
};
