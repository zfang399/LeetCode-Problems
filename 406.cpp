class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        if(a.first!=b.first) return a.first>b.first;
        return a.second<b.second;
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> ans;
        if(people.size()==0) return ans;
        sort(people.begin(),people.end(),cmp);
        for(int i=0;i<people.size();i++){
            ans.insert(ans.begin()+people[i].second,people[i]);
        }
        return ans;
    }
};
