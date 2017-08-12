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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        if(newInterval.start>newInterval.end){
            for(int i=0;i<intervals.size();i++) ans.push_back(intervals[i]);
            return ans;
        }
        if(intervals.size()==0){
            ans.push_back(newInterval);
            return ans;
        }
        bool inserted=false;
        for(int i=0;i<intervals.size();i++){
            if(inserted){
                ans.push_back(intervals[i]);
                continue;
            }
            if(intervals[i].end<newInterval.start){
                ans.push_back(intervals[i]);
            }else if(intervals[i].end==newInterval.start){
                newInterval.start=min(newInterval.start,intervals[i].start);
            }else{
                if(intervals[i].start>newInterval.end){
                    ans.push_back(newInterval);
                    ans.push_back(intervals[i]);
                    inserted=true;
                    continue;
                }else if(intervals[i].start==newInterval.end){
                    newInterval.end=intervals[i].end;
                    ans.push_back(newInterval);
                    inserted=true;
                    continue;
                }
                if(intervals[i].end>=newInterval.end){
                    newInterval.end=max(newInterval.end,intervals[i].end);
                    newInterval.start=min(newInterval.start,intervals[i].start);
                    ans.push_back(newInterval);
                    inserted=true;
                }else{
                    newInterval.start=min(newInterval.start,intervals[i].start);
                }
            }
        }
        if(!inserted) ans.push_back(newInterval);
        return ans;
    }
};
