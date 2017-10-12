class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        vector<int> a(prices.size(),0);
        vector<int> b(prices.size(),0);
        vector<int> c(prices.size(),0);
        a[0]=0;
        b[0]=-prices[0];
        c[0]=INT_MIN;
        for(int i=1;i<prices.size();i++){
            a[i]=max(a[i-1],c[i-1]);
            b[i]=max(b[i-1],a[i-1]-prices[i]);
            c[i]=b[i-1]+prices[i];
        }
        return max(a[prices.size()-1],c[prices.size()-1]);
    }
};
