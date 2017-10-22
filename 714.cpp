class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.empty()) return 0;
        int buy=-prices[0], sell=0;
        for(int i=1; i<prices.size(); i++) {
            int prev_buy=buy, prev_sell=sell;
            buy=max(prev_buy, prev_sell-prices[i]);
            sell=max(prev_sell, prev_buy+prices[i]-fee);
        }
        return sell;
    }
};
