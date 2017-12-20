class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> pay(cost.size()+1,0);
        for(int i = 2; i < pay.size(); i++){
            pay[i] = min(pay[i-1]+cost[i-1], pay[i-2]+cost[i-2]);
        }
        return pay.back();
    }
};
