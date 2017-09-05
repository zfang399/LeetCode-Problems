class Solution {
public:
    int findIntegers(int num) {
        int s=0,t=num;
        string l;
        while(t>0){
            l+=to_string(t%2);
            t/=2;
            s++;
        }
        vector<vector<int>> dp(s,vector<int>(2));
        dp[0][0]=1;
        dp[0][1]=1;
        for(int i=1;i<s;i++){
            dp[i][0]=dp[i-1][1]+dp[i-1][0];
            dp[i][1]=dp[i-1][0];
        }
        int ans=dp[s-1][0]+dp[s-1][1];
        for(int i=l.size()-2;i>=0;i--){
            if(l[i]=='1'&&l[i+1]=='1') break;
            if(l[i]=='0'&&l[i+1]=='0') ans-=dp[i][1];
        }
        return ans;
    }
};
