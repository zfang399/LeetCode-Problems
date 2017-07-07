/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(Interval i1, Interval i2){
        if(i1.end!=i2.end) return i1.end<i2.end;
        return i1.start<i2.start;
    }
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int ans=0;
        for(int i=1;i<intervals.size();){
            if(intervals[i].start<intervals[i-1].end){
                ans++;
                intervals.erase(intervals.begin()+i,intervals.begin()+i+1);
            }else{
                i++;
            }
        }
        return ans;
    }
};
