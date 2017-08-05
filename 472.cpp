class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string,bool> e;
        vector<string> ans;
        for(int i=0;i<words.size();i++) e[words[i]]=true;
        for(int i=0;i<words.size();i++){
            int l=words[i].length();
            vector<bool> dp(l+1);
            dp[0]=1;
            for(int j=0;j<l;j++){
                if(!dp[j]) continue;
                for(int k=j+1;k<=l;k++){
                    if(k-j<l && e[words[i].substr(j,k-j)]) dp[k]=true;
                }
                if(dp[l]){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
