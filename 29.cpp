class Solution {
public:
    int divide(int divid, int divis) {
        long long dividend=divid;
        long long divisor=divis;
        bool neg=false;
        if(!divisor || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        if(dividend==0) return 0;
        if(dividend<0){
            dividend=-dividend;
            if(divisor<0){
                neg=false;
                divisor=-divisor;
            }else{
                neg=true;
            }
        }else if(divisor<0){
            neg=true;
            divisor=-divisor;
        }
        int ans=0;
        int k=divisor;
        while(divisor<=dividend){
            long long temp=divisor,m=1;
            while (dividend>=(temp<<1)) {
                temp <<= 1;
                m<<= 1;
            }
            dividend -= temp;
            ans += m;
        }
        if(neg) return -ans;
        return ans;
    }
};
