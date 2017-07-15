class Solution {
public:
    int integerReplacement(int n) {
        queue<long long> ns,ts;
        ns.push(n);
        ts.push(0);
        while(ns.size()){
            long long nx=ns.front();
            ns.pop();
            long long tx=ts.front();
            ts.pop();
            if(nx==1) return tx;
            if(nx%2){
                ns.push(nx+1);
                ns.push(nx-1);
                ts.push(tx+1);
                ts.push(tx+1);
            }else{
                ns.push(nx/2);
                ts.push(tx+1);
            }
        }
    }
};
