class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        bool can=false;
        for(int i=0;i<cost.size();i++){
            cost[i]=gas[i]-cost[i];
            if(cost[i]>=0) can=true;
        }
        if(!can) return -1;
        for(int i=0;i<cost.size();i++){
            if(cost[i]<0) continue;
            int x=0;
            for(int j=0;j<cost.size();j++){
                x+=cost[(i+j+cost.size())%cost.size()];
                if(x<0){
                    i=max(i,j-2);
                    break;
                }
            }
            if(x>=0) return i;
        }
        return -1;
    }
};
