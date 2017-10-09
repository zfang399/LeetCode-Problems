class Solution {
public:
    bool hasAlternatingBits(int n) {
        if(n<2) return true;
        int prev=n%2;
        n/=2;
        while(n>0){
            if(n%2==prev){
                return false;
            }
            prev=n%2;
            n/=2;
        }
        return true;
    }
};
