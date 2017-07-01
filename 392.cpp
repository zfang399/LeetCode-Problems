class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s=="") return true;
        if(s.length()>t.length()) return false;
        int pt=0,ps=0;
        while(pt<t.length() && ps<s.length()){
            if(t[pt]==s[ps]){
                ps++;
                if(ps==s.length()) return true;
            }
            pt++;
        }
        return false;
    }
};
