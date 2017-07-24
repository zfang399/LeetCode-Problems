class Solution {
public:
    void reverseWords(string &s) {
        if(!s.size()) return;
        stack<string> st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                int j=i+1;
                while(s[j]!=' ' && j<s.length()) j++;
                st.push(s.substr(i,j-i));
                i=j;
            }
        }
        if(!st.size()){
            s="";
            return;
        }
        s=st.top();
        st.pop();
        while(st.size()){
            s+=" "+st.top();
            st.pop();
        }
    }
};
