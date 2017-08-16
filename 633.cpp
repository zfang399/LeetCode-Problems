class Solution {
public:
    bool judgeSquareSum(int c) {
        int sq=0;
        int k=0;
        while(sq<=(c/2)){
            int t=c-sq;
            int tt=sqrt(t);
            if(t==tt*tt) return true;
            k++;
            sq=k*k;
        }
        return false;
    }
};
