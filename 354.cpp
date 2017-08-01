class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.first<b.first;
    }
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.size()==0) return 0;
        sort(envelopes.begin(),envelopes.end());
        vector<int> dp(envelopes.size());
        int ans=0;
        for(int i=0;i<envelopes.size();i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(envelopes[j].first<envelopes[i].first && envelopes[j].second<envelopes[i].second){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(dp[i],ans);
        }
        return ans;
    }
};
