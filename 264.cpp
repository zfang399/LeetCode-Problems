class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long,vector<long long>, greater<long long>> q;
        q.push(1);
        long long i=0;
        while(i<n){
            i++;
            long long x=q.top();
            while(q.top()==x && q.size()) q.pop();
            if(i==n) return x;
            q.push(2*x);
            q.push(3*x);
            q.push(5*x);
        }
    }
};
