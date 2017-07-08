class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[101][101]={0};
        for(int i=0;i<strs.size();i++){
            int zero=0,one=0;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='0') zero++;
                else one++;
            }
            for(int j=m;j>=zero;j--){
                for(int k=n;k>=one;k--){
                    dp[j][k]=max(dp[j][k],dp[j-zero][k-one]+1);
                }
            }
        }
        return dp[m][n];
    }
};
