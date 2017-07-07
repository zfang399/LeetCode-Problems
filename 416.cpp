class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot=0;
        for(int i=0;i<nums.size();i++) tot+=nums[i];
        if(tot%2) return false;
        tot/=2;
        vector<int> dp(tot+1, 0);
        dp[0] = 1;
        for(int i=0;i<nums.size();i++){
            for(int j =tot;j>=nums[i];j--)
                dp[j]=dp[j]||dp[j-nums[i]];
        }
        return dp[tot];
    }
};
