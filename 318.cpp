class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bit(words.size(),0);
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++){
                bit[i]|=1<<(words[i][j]-'a');
            }
            for(int j=0;j<i;j++){
                if(!(bit[i]&bit[j])){
                    int m=words[i].length();
                    int n=words[j].length();
                    ans=max(ans,m*n);
                }
            }
        }
        return ans;
    }
};
