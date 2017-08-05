class Solution {
public:
    int numDistinct(string s, string t) {
        int ans=0;
        int m=s.length(),n=t.length();
        if(m<n) return ans;
        vector<int> dp(n);
        for(int i=0;i<m;i++){
            for(int j=n;j>=0;j--){
                if(t[j]==s[i]){
                    if(j>0) dp[j]+=dp[j-1];
                    else dp[j]+=1;
                }
            }
        }
        return dp[n-1];
    }
};
