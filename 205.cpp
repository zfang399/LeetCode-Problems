class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map <char,char> refs,reft;
        for(int i=0;i<s.length();i++){
            if(!refs[s[i]] && !reft[t[i]]){
                refs[s[i]]=t[i];
                reft[t[i]]=s[i];
            }else if (refs[s[i]]!=t[i] || reft[t[i]]!=s[i]){
                return false;
            }
        }
        return true;
    }
}; 
