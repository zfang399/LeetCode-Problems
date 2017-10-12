class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low=1,high=m*n+1;
        while(low<high){
            int mid=low+(high-low)/2;
            int c=count(mid,m,n);
            if(c>=k) high=mid;
            else low=mid+1;
        }
        return high;
    }
    int count(int x, int m, int n){
        int ret=0;
        for(int i=1;i<=m;i++){
            int t=min(x/i,n);
            ret+=t;
        }
        return ret;
    }
};
