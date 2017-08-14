class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> ans;
        map<string,map<string,double>> m;
        for(int i=0;i<equations.size();i++){
            m[equations[i].first][equations[i].second]=values[i];
            m[equations[i].second][equations[i].first]=1/values[i];
        }
        for(auto e:m){
            for(auto i:e.second){
                for(auto j:e.second){
                    m[i.first][j.first]=m[i.first][e.first]*m[e.first][j.first];
                }
            }
        }
        for(int i=0;i<queries.size();i++){
            if(m[queries[i].first][queries[i].second]==0) ans.push_back(-1);
            else ans.push_back(m[queries[i].first][queries[i].second]);
        }
        return ans;
    }
};
