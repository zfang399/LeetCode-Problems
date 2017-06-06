class Solution {
public:
    string reverseString(string s) {
        string ans;
        for(int i=s.length()-1;i>=0;i--) ans+=s[i];
        return ans;
    }
};
