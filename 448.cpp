class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        map<int,bool> ap;
        vector <int> ans;
        for(int i=0;i<nums.size();i++) ap[nums[i]]=true;
        for(int i=1;i<=nums.size();i++) if(ap.count(i)==0) ans.push_back(i);
        return ans;
    }
};
