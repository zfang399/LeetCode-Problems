class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();

        // No gas station
        if(n == 0){
            if (startFuel >= target) return 0;
            return -1;
        }

        // Initialize DP
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            dp[i][0] = startFuel - stations[i][0];
        }
        if(dp[0][0] < 0) return -1;

        // DP
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= i; j++){
                dp[i][j] = -1;
                if(dp[i - 1][j - 1] >= 0){
                    int tmp =  dp[i - 1][j - 1] + stations[i - 1][1] - stations[i][0] + stations[i - 1][0];
                    if(tmp >= 0) dp[i][j] = tmp;
                }
                if(dp[i - 1][j] >= 0 && j != i){
                    int tmp = dp[i - 1][j] - stations[i][0] + stations[i - 1][0];
                    if(tmp > dp[i][j]) dp[i][j] = tmp;
                }
            }
        }

        // Get answer
        for(int i = 0; i < n; i++){
            if(dp[n - 1][i] < 0) continue;
            if(dp[n - 1][i] + stations[n - 1][0] >= target) return i;
            if(dp[n - 1][i] + stations[n - 1][0] + stations[n - 1][1] >= target) return i + 1;
        }
        return -1;
    }
};
