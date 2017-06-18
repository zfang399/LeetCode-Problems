class Solution {
public:
    bool isPalindrome(string s) {
        if(s=="") return true;
        int f=0,r=s.length()-1;
        while(f<r){
            while (!((s[f]>=65 && s[f]<=90) || (s[f]>=97 && s[f]<=122) || (s[f]>=48 && s[f]<=57)) && f<s.length()){
                f++;
            }
            while (!((s[r]>=65 && s[r]<=90) || (s[r]>=97 && s[r]<=122) || (s[r]>=48 && s[r]<=57)) && r>=0){
                r--;
            }
            if(r<=f) return true;
            if(tolower(s[f])!=tolower(s[r])) return false;
            f++,r--;
        }
        return true;
    }
};
