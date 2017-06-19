class Solution {
public:
    string convertToTitle(int n) {
        n=n-1;
        string ans;
        char c;
        while(n>0){
            c='A'+n%26;
            ans=c+ans;
            n/=26;
            n--;
        }
        if(n==0){
            ans='A'+ans;
        }
        return ans;
    }
};
