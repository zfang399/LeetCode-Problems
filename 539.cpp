class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        priority_queue <int> times;
        int ans=INT_MAX;
        for(int i=0;i<timePoints.size();i++){
            int hour=(timePoints[i][0]-'0')*10+(timePoints[i][1]-'0');
            int min=(timePoints[i][3]-'0')*10+(timePoints[i][4]-'0');
            int totmin=hour*60+min;
            times.push(totmin);
            times.push(totmin+1440);
        }
        while(times.size()!=1){
            int t1=times.top();
            times.pop();
            if(t1-times.top()<ans) ans=t1-times.top();
        }
        return ans;
    }
};
