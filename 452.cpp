class Solution {
public:
    static bool cmp(pair<int,int> &p1, pair<int,int> &p2){
        if(p1.second!=p2.second) return p1.second<p2.second;
        return p1.first<p2.first;
    }
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.size()==0) return 0;
        int ans=1;
        sort(points.begin(),points.end(),cmp);
        int a=points[0].second;
        for(int i=1;i<points.size();i++){
            if(a>=points[i].first && a<=points[i].second) continue;
            ans++;
            a=points[i].second;
        }
        return ans;
    }
};
