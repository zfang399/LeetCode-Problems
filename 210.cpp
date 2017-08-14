class Solution {
public:
    vector<int> findOrder(int n, vector<pair<int, int>>& pre) {
        vector<int> ans;
        vector<vector<int>> pres(n),cores(n);
        vector<int> cur;
        vector<bool> visited(n,false);
        int taken=0;
        for(int i=0;i<pre.size();i++){
            pres[pre[i].first].push_back(pre[i].second);
            cores[pre[i].second].push_back(pre[i].first);
        }
        for(int i=0;i<n;i++) if(pres[i].size()==0) cur.push_back(i);
        while(taken<n && cur.size()){
            taken+=cur.size();
            for(int i=0;i<cur.size();i++){
                visited[cur[i]]=true;
                ans.push_back(cur[i]);
                for(int j=0;j<cores[cur[i]].size();j++){
                    pres[cores[cur[i]][j]].erase(find(pres[cores[cur[i]][j]].begin(),pres[cores[cur[i]][j]].end(),cur[i]));
                }
            }
            cur.erase(cur.begin(),cur.end());
            for(int i=0;i<n;i++){
                if(pres[i].size()==0 && !visited[i]) cur.push_back(i);
            }
        }
        if(taken==n) return ans;
        else{
            vector<int> e;
            return e;
        }
    }
};
