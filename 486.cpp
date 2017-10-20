class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int l=nums.size();
        vector<vector<int>> dp(l,vector<int>(l,0));
        for(int i=0;i<l;i++) dp[i][i]=nums[i];
        for(int len=1;len<l;len++){
            for(int i=0;i<l-len;i++){
                int j=i+len;
                dp[i][j]=max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][l-1]>=0;
    }
};
