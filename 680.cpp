class Solution {
public:
    bool validPalindrome(string s) {
        return test(s,0,s.length()-1,1);
    }
    bool test(string& s, int i, int j, int del){
        if(i>=j) return true;
        if(s[i]==s[j]){
            return test(s,i+1,j-1,del);
        }else{
            if(del>0){
                return test(s,i+1,j,del-1) || test(s,i,j-1,del-1);
            }
            return false;
        }
    }
};
