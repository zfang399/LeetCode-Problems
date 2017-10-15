class Solution {
public:
    int countBinarySubstrings(string s) {
        int l=0,i=0,prev=0,ans=0;
        while(i<s.length()){
            l=1;
            while(s[i]==s[i+1] && i+1<s.length()){
                i++;
                l++;
            }
            i++;
            ans+=min(l,prev);
            prev=l;
        }
        return ans;
    }
};
