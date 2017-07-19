class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0) return "";
        int ml=1,l=s.length();
        string ans;
        ans+=s[0];
        for(int i=0;i<l-ml;i++){
            for(int j=l-i;j>ml;j--){
                if(isp(s.substr(i,j))){
                    ans=s.substr(i,j);
                    ml=j;
                    break;
                }
            }
        }
        return ans;
    }
    bool isp(string s){
        int l=s.length()-1;
        for(int i=0;i<s.length()/2;i++){
            if(s[i]!=s[l-i]) return false;
        }
        return true;
    }
};
