class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        if(a[0]!=b[0]) return a[0]<b[0];
        return a.back()<b.back();
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size()==0) return 0;
        vector<int> dp(pairs.size(),1);
        int ans=1;
        sort(pairs.begin(),pairs.end(),cmp);
        for(int i=0;i<pairs.size();i++){
            //cout<<pairs[i][0]<<" "<<pairs[i][1]<<endl;
            for(int j=0;j<i;j++){
                if(pairs[i].front()>pairs[j].back()){
                    dp[i]=max(dp[i],dp[j]+1);
                    if(dp[i]>ans) ans=dp[i];
                }
            }
        }
        return ans;
    }
};
