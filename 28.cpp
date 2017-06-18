class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        if(haystack.length()<needle.length()) return -1;
        int l=needle.length(),j;
        for(int i=0;i<haystack.length()-l+1;i++){
            if(haystack[i]==needle[0]){
                for(j=1;j<l;j++){
                    if(haystack[i+j]!=needle[j]) break;
                }
                if(j==l) return i;
            }
        }
        return -1;
    }
};
