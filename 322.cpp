class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        sort(coins.begin(),coins.end());
        if(amount<coins[0]) return -1;
        vector<int> count(amount+1,-1);
        count[0]=0;
        for(int i=coins[0];i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]<0) break;
                if(count[i-coins[j]]>=0){
                    if(count[i]==-1) count[i]=count[i-coins[j]]+1;
                    else count[i]=min(count[i-coins[j]]+1,count[i]);
                }
            }
        }
        return count[amount];
    }
};
