class Solution {
public:
    int integerBreak(int n) {
        int m[60]={0},ans=INT_MIN;
        m[1]=1;
        for(int i=2;i<n;i++){
            int x=INT_MIN;
            for(int j=1;j<i;j++){
                if(x<m[j]*m[i-j]) x=m[j]*m[i-j];
            }
            m[i]=max(x,i);
        }
        for(int i=1;i<n;i++){
            if(m[i]*m[n-i]>ans) ans=m[i]*m[n-i];
        }
        return ans;
    }
};
