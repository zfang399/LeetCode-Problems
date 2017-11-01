class Solution {
public:
    bool isValid(string s) {
        if(s=="") return true;
        if(s[0]==')' || s[0]=='}' || s[0]==']') return false; 
        stack<char> para;
        unordered_map <char,char> match;
        match['(']=')',match['{']='}',match['[']=']';
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                para.push(s[i]);
            }else{
                if(para.empty()) return false;
                char c=para.top();
                para.pop();
                if(match[c]!=s[i]) return false;
            }
        }
        if(!para.empty()) return false;
        return true;
    }
};
