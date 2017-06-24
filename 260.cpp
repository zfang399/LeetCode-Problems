class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map <int,bool> exist;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(exist[nums[i]]) exist[nums[i]]=false;
            else exist[nums[i]]=true;
        }
        for(auto e:exist){
            if(e.second){
                ans.push_back(e.first);
            }
        }
        return ans;
    }
};
