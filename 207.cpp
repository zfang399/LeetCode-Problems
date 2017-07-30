class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int n=prerequisites.size();
        if(n==0) return true;
        vector<vector<int>> pres(numCourses);
        vector<vector<int>> af(numCourses);
        vector<bool> visited(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            pres[prerequisites[i].first].push_back(prerequisites[i].second);
            af[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        bool done=false;
        while(!done){
            bool change=false;
            for(int i=0;i<numCourses;i++){
                if(pres[i].size()==0 && !visited[i]){
                    visited[i]=true;
                    change=true;
                    for(int j=0;j<af[i].size();j++){
                        auto e=find(pres[af[i][j]].begin(),pres[af[i][j]].end(),i);
                        pres[af[i][j]].erase(e);
                    }
                }
            }
            done=!change;
        }
        for(int i=0;i<numCourses;i++){
            if(pres[i].size()!=0) return false;
        }
        return true;
    }
};
