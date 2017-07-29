class Solution {
public:
    struct proj{
        int cap,net;
    };
    static bool cmp(proj a,proj b){
        if(a.net!=b.net) return a.net>b.net;
        return a.cap<b.cap;
    }
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int ans=0,n=Profits.size();
        vector<proj> p(n);
        for(int i=0;i<n;i++){
            p[i].cap=Capital[i];
            p[i].net=Profits[i];
        }
        sort(p.begin(),p.begin()+n,cmp);
        int f=0,i;
        while(f<k){
            f++;
            for(i=0;i<n;i++){
                if(p[i].net<=0) break;
                if(p[i].cap<=W) break;
            }
            if(i==n) break;
            if(p[i].net<=0) break;
            W+=p[i].net;
            p.erase(p.begin()+i);
            n--;
        }
        return W;
    }
};
