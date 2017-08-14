class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> ans;
        priority_queue<pair<int,int>> q;
        int p=0,pro;
        while(p<buildings.size() || q.size()){
            if(q.size()){
                pro=q.top().second;
            }else{
                pro=buildings[p][0];
            }
            if(p>=buildings.size() || buildings[p][0]>pro){
                while(q.size()&&q.top().second<=pro) q.pop();
            }else{
                pro=buildings[p][0];
                while(p<buildings.size() && buildings[p][0]==pro){
                    q.push(make_pair(buildings[p][2],buildings[p][1]));
                    p++;
                }
            }
            int x=0;
            if(q.size()){
                x=q.top().first;
            }
            if(ans.empty()||(ans.back().second!=x) ) ans.push_back(make_pair(pro,x));
        }
        return ans;
    }
};
