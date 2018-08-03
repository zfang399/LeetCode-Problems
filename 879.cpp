class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        int m = 0;
        for(int i = 0; i < profit.size(); i++) m += profit[i];
        // dp gang member needed and profit made
        vector<vector<long>> dp(G + 1,vector<long>(m + 1, 0));
        dp[0][0] = 1;
        for(int i = 0; i < group.size(); i++){
            for(int j = G; j >= group[i]; j--){
                for(int k = m; k >= profit[i]; k--){
                    dp[j][k] += dp[j - group[i]][k - profit[i]];
                    dp[j][k] %= 1000000007;
                }
            }
        }

        // add up answers
        long ans = 0;
        for(int j = 0; j < G + 1; j++){
            for(int k = P; k < m + 1; k++){
                ans += dp[j][k];
                ans %= 1000000007;
            }
        }
        return ans;
    }
};
