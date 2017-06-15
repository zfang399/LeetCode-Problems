class Solution {
public:
    int arrangeCoins(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        long long f=1,r=n,mid;
        while(f<=r){
            mid=(f+r)/2;
            if(mid*(mid+1)/2<=n){
                f=mid+1;
            }else{
                r=mid-1;
            }
        }
        return f-1;
    }
};
