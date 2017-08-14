class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> a(n);
        for(int i=0;i<edges.size();i++){
            a[edges[i].first].push_back(edges[i].second);
            a[edges[i].second].push_back(edges[i].first);
        }
        if(edges.size()==0){
            vector<int> ans;
            if(n==1) ans.push_back(0);
            return ans;
        }
        vector<int> cur;
        vector<bool> visited(n);
        for(int i=0;i<n;i++) if(a[i].size()==1) cur.push_back(i);
        int rem=n;
        while(rem>2){
            for(int i=0;i<cur.size();i++){
                visited[cur[i]]=true;x
                a[a[cur[i]][0]].erase(find(a[a[cur[i]][0]].begin(),a[a[cur[i]][0]].end(),cur[i]));
                a[cur[i]].erase(a[cur[i]].begin());
            }
            rem-=cur.size();
            cur.erase(cur.begin(),cur.end());
            for(int i=0;i<n;i++){
                if(a[i].size()<=1 && !visited[i]) cur.push_back(i);
            }
        }
        return cur;
    }
};
