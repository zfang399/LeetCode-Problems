class Solution {
public:
    int mySqrt(int x) {
        long long f=0,r=x,mid;
        while(f<=r){
            mid=(f+r)/2;
            if(mid*mid==x) return mid;
            else if(mid*mid>x) r=mid-1;
            else f=mid+1;
        }
        return r;
    }
};
