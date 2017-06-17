class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        sort(strs.begin(),strs.end());
        string ans=strs[0];
        int l=ans.length();
        for(int i=1;i<strs.size();i++){
            while(ans!=strs[i].substr(0,l)){
                l--;
                ans=ans.substr(0,l);
            }
        }
        return ans;
    }
};
