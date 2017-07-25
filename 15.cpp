class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;){
            int f=i+1,r=nums.size()-1;
            while(f<r){
                if(nums[i]+nums[f]+nums[r]==0) ans.push_back({nums[i],nums[f],nums[r]});
                if(nums[i]+nums[f]+nums[r]<0){
                    while(nums[f]==nums[f+1]) f++;
                    f++;
                }else{
                    while(nums[r]==nums[r-1]) r--;
                    r--;
                }
            }
            while(nums[i+1]==nums[i]) i++;
            i++;
        }
        return ans;
    }
};
