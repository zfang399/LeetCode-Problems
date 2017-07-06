class Solution {
public:
    int numSquares(int n) {
        queue<int> q1,c;
        q1.push(n);
        c.push(1);
        while(q1.size()){
            int x=q1.front(),y=c.front();
            q1.pop(),c.pop();
            int k=sqrt(x);
            if(k*k==x) return y;
            for(int i=k;i>=1;i--){
                q1.push(x-i*i);
                c.push(y+1);
            }
        }
    }
};
