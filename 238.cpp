class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        if(nums.size()==0) return ans;
        int fb=1,fe=1;
        for(int i=0;i<nums.size();i++){
            ans[i]*=fb;
            fb*=nums[i];
            ans[nums.size()-i-1]*=fe;
            fe*=nums[nums.size()-i-1];
        }
        return ans;
    }
};
