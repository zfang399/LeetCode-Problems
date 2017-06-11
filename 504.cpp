class Solution {
public:
    string convertToBase7(int num) {
        string ans;
        int rem;
        while(abs(num)>=7){
            rem=abs(num%7);
            num/=7;
            ans=to_string(rem)+ans;
        }
        ans=to_string(num)+ans;
        return ans;
    }
};
