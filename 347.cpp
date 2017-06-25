class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        if(a.second!=b.second){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> count;
        vector<pair<int,int>> form;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        for(auto e:count){
            form.push_back(make_pair(e.first,e.second));
        }
        sort(form.begin(),form.end(),cmp);
        for(int i=0;i<k;i++){
            ans.push_back(form[i].first);
        }
        return ans;
    }
};
