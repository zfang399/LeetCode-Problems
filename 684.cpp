class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> p(2001,0);
        for(int i=0;i<p.size();i++) p[i]=i;
        for(int i=0;i<edges.size();i++){
            int fa=edges[i].front(),son=edges[i].back();
            if(find(p,fa)==find(p,son)) return edges[i];
            else p[find(p,fa)]=find(p,son);
        }
    }
    int find(vector<int> &p,int x){
        if(x!=p[x]){
            p[x]=find(p,p[x]);
        }
        return p[x];
    }
};
