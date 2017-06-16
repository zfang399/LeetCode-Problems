class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map <char,string> match;
        unordered_map <string,char> matchback;
        int p=0;
        for(int i=0;i<str.length();){
            string ins;
            while(str[i]!=' ' && i<str.length()){
                ins+=str[i];
                i++;
            }
            i++;
            if(match[pattern[p]]=="" && matchback[ins]==0){
                match[pattern[p]]=ins;
                matchback[ins]=pattern[p];
            }else if(match[pattern[p]]!=ins || matchback[ins]!=pattern[p]) return false;
            p++;
        }
        if(p!=pattern.length()) return false;
        return true;
    }
};
