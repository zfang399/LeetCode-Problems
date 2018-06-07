class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = nums[0];
        for(int i = 1; i < n; i++){
            dp[0][i] = dp[0][i - 1] + nums[i];
        }

        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                int minij = 2147483647;
                for(int k = 0; k < j; k++){
                    int maxsub = max(dp[i - 1][k], dp[0][j] - dp[0][k]);
                    minij = min(minij, maxsub);
                }
                dp[i][j] = minij;
            }
        }

        return dp[m - 1][n - 1];
    }
};
