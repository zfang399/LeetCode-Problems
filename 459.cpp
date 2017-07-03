class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.length()==0) return false;
        string sub;
        sub+=s[0];
        for(int i=1;i<s.length();i++){
            if(s[i]==sub[0]){
                if(issub(s,sub)){
                    return true;
                }
            }
            sub+=s[i];
        }
        return false;
    }
    bool issub(string s, string sub){
        string x=sub;
        while(sub.length()<s.length()){
            sub+=x;
        }
        if(sub==s) return true;
        return false;
    }
};
