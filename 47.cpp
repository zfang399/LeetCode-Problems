class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()==0) return ans;
        unordered_map<int,int> count;
        for(int i=0;i<nums.size();i++) count[nums[i]]++;
        vector<int> x;
        dfs(ans,count,x);
        return ans;
    }
    void dfs(vector<vector<int>>& ans, unordered_map<int,int>& count,vector<int>&x){
        bool done=true;
        for(auto &e:count){
            if(e.second>0){
                done=false;
                x.push_back(e.first);
                e.second-=1;
                dfs(ans,count,x);
                x.pop_back();
                e.second+=1;
            }
        }
        if(done) ans.push_back(x);
    }
};
