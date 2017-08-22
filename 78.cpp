class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> now;
        getsub(ans,now,0,nums);
        return ans;
    }
    void getsub(vector<vector<int>>& ans, vector<int>& now,int f,vector<int>& nums){
        ans.push_back(now);
        for(int i=f;i<nums.size();i++){
            now.push_back(nums[i]);
            getsub(ans,now,i+1,nums);
            now.pop_back();
        }
    }
};
