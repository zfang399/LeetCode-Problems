class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums,0,ans);
        return ans;
    }
    void helper(vector<int> &nums, int f, vector<vector<int> > &ans){
        if(f>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=f;i<nums.size();i++){
            swap(nums[f],nums[i]);
            helper(nums,f+1,ans);
            swap(nums[f],nums[i]);
        }
    }
};
