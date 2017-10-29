class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int ans=0,minbuy=prices[0];
        for(int i=0;i<prices.size();i++){
            if(prices[i]-minbuy>ans) ans=prices[i]-minbuy;
            if(prices[i]<minbuy) minbuy=prices[i];
        }
        return ans;
    } 
};
