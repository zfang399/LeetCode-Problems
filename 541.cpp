class Solution {
public:
    string reverseStr(string s, int k) {
        string ans;
        int i,p,q;
        for(i=0;i<s.length();){
            p=i+k-1;
            q=i+2*k-1;
            if(p>s.length()-1) p=s.length()-1;
            if(q>s.length()-1) q=s.length()-1;
            for(int j=p;j>=i;j--) ans+=s[j];
            for(int j=p+1;j<=q;j++) ans+=s[j];
            i=q+1;
        }
        return ans;
    }
};
