class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        //dp[i][j]: largest advantage over your opponent for piles from i to j
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), 0));
        for(int i = 0; i < piles.size(); i++) dp[i][i] = piles[i];
        for(int l = 1; l < piles.size(); l++){
            for(int st = 0; st < piles.size() - l; st++){
                // take first, or take last
                dp[st][st + l] = max(piles[st] - dp[st + 1][st + l], piles[st + l] - dp[st][st + l - 1]);
            }
        }

        return dp[0][piles.size() - 1] > 0;
    }
};
