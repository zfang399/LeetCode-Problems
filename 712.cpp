class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int l1=s1.length(),l2=s2.length();
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
        dp[0][0]=0;
        int maxn=0;
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+s1[i-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                maxn=max(maxn,dp[i][j]);
            }
        }
        int tot=0;
        for(int i=0;i<l1;i++) tot+=s1[i];
        for(int i=0;i<l2;i++) tot+=s2[i];
        return tot-maxn*2;
    }
};
