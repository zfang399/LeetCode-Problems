class Solution {
public:
    string reverseWords(string s) {
        stack <char> ins;
        string ans="";
        int mark=0;
        while(mark<s.length()){
            if(s[mark]==' '){
                while(!ins.empty()){
                    ans+=ins.top();
                    ins.pop();
                }
                ans+=s[mark];
            }
            else{
                ins.push(s[mark]);
            }
            mark++;
        }
        while(!ins.empty()){
                    ans+=ins.top();
                    ins.pop();
        }
        return ans;
    }
};
