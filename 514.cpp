class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<char, vector<int>> m;
        for(int i=0;i<ring.length();i++){
            m[ring[i]].push_back(i);
        }
        vector<vector<int>> dp(key.length()+1,vector<int>(ring.length(),INT_MAX));
        for(int i=0;i<dp[0].size();i++) dp[0][i]=0;
        vector<int> ind(1,0);
        int ans = INT_MAX;
        for(int i=1;i<=key.length();i++){
            for(int j=0;j<m[key[i-1]].size();j++){
                for(int k=0;k<ind.size();k++){
                    int mind=min( (ind[k]+ring.length()-m[key[i-1]][j])%ring.length(), (m[key[i-1]][j]+ring.length()-ind[k])%ring.length() )+dp[i-1][ind[k]];
                    dp[i][m[key[i-1]][j]]=min(dp[i][m[key[i-1]][j]],mind);
                    if(i==key.length()) ans=min(ans,dp[i][m[key[i-1]][j]]);
                }
            }
            ind = m[key[i-1]];
        }
        return ans+key.length();
    }
};
