class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ans=0;
        for(int i=0;i<points.size();i++){
            map<long,int> same;
            for(int j=0;j<points.size();j++){
                if(i==j) continue;
                int dx=points[i].first-points[j].first;
                int dy=points[i].second-points[j].second;
                long dis=dx*dx;
                dis+=dy*dy;
                same[dis]++;
            }
            for(auto e:same){
                ans+=e.second*(e.second-1);
            }
        }
        return ans;
    }
};
