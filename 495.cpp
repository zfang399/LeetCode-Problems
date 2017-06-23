class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(duration==0) return 0;
        int ans=0;
        for(int i=0;i<timeSeries.size();){
            int f=timeSeries[i];
            int r=timeSeries[i]+duration;
            while(timeSeries[i]<r && i<timeSeries.size()){
                r=timeSeries[i]+duration;
                i++;
            }
            ans+=(r-f);
        }
        return ans;
    }
};
