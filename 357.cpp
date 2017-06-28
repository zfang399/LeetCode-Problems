class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n>10) n=10;
        int ans=0;
        for(int i=0;i<=n;i++){
            ans+=combi(i);
        }
        return ans;
    }
private:
    int combi(int x){
        if(x==0) return 1;
        if(x==1) return 9;
        int ret=9,st=9;
        for(int i=1;i<=x-1;i++){
            ret*=st;
            st--;
        }
        return ret;
    }
};
