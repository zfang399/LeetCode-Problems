class Solution {
public:
    int hammingDistance(int x, int y) {
        int tx,ty,ans=0;
        while((x/2!=0 || x%2!=0) || (y/2!=0 || y%2!=0)){
            tx=x%2;
            ty=y%2;
            x=x/2;
            y=y/2;
            if(tx!=ty){
                ans++;
            }
        }
        return ans;
    }
};
