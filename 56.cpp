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
    static bool cmp(Interval a, Interval b){
        if(a.start!=b.start) return a.start<b.start;
        return a.end<b.end;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if(intervals.size()==0) return ans;
        sort(intervals.begin(),intervals.end(),cmp);
        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i].end>=intervals[i+1].start){
                intervals[i+1].start=intervals[i].start;
                intervals[i+1].end=max(intervals[i+1].end,intervals[i].end);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        ans.push_back(intervals[intervals.size()-1]);
        return ans;
    }
};
