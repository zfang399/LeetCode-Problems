class Solution {
public:
    int countSubstrings(string s) {
        int ans=s.size();
        if(ans==0) return ans;
        for(int i=0;i<s.size()-1;i++){
            for(int j=i+2;j<=s.size();j++){
                if(ispalin(s.substr(i,j-i))) ans++;
            }
        }
        return ans;
    }
    bool ispalin(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
