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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int,int> left;
        vector<int> ans;
        for(int i=0;i<intervals.size();i++) left[intervals[i].start]=i;
        for(int i=0;i<intervals.size();i++){
            auto ctr=left.lower_bound(intervals[i].end);
            if(ctr==left.end()) ans.push_back(-1);
            else ans.push_back(ctr->second);
        }
        return ans;
    }
};
