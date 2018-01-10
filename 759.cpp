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
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        map<int,int> working;
        int t_max = 0;
        for(int i = 0; i < schedule.size(); i++){
            for(int j = 0; j < schedule[i].size(); j++){
                working[schedule[i][j].start]++;
                working[schedule[i][j].end]--;
                if(schedule[i][j].end > t_max) t_max = schedule[i][j].end;
            }
        }
        vector<Interval> ans;
        int num_working = 0;
        for(auto e:working){
            num_working += e.second;
            if(num_working == 0 && e.first!=t_max) ans.push_back(Interval(e.first,0));
            else if(ans.size() && ans.back().end == 0) ans.back().end = e.first;
        }
        return ans;
    }
};
