class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ns;
        int x=0;
        for(int i=S.size()-1;i>=0;i--){
            if(S[i]=='-'){
                continue;
            }
            if(S[i]>='a' && S[i]<='z'){
                char k=S[i]-'a'+'A';
                ns=k+ns;
            }else{
                ns=S[i]+ns;
            }
            x++;
            if(x==K){
                x=0;
                ns='-'+ns;
            }
        }
        if(ns[0]=='-') return ns.substr(1);
        return ns;
    }
};
