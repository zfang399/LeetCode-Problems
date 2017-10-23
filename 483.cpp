class Solution {
public:
    string smallestGoodBase(string n) {
        unsigned long long num=(unsigned long long)stoll(n);
        unsigned long long x=1;
        for(int i=62;i>=1;i--){
            if( (x<<i) <num){
                unsigned long long tmp=helper(num,i);
                if(tmp!=0) return to_string(tmp);
            }
        }
        return to_string(num-1);
    }
    unsigned long long helper(unsigned long long n, int ex){
        double num=(double) n;
        unsigned long long l=1;
        unsigned long long r=(unsigned long long)(pow(num,1.0/ex)+1);
        while(l<=r){
            unsigned long long mid=l+(r-l)/2;
            unsigned long long now=1,tot=1;
            for(int i=1;i<=ex;i++){
                now*=mid;
                tot+=now;
            }
            if(tot==n) return mid;
            if(tot>num){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return 0;
    }
};
