class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max_pos=0,min_neg=0,two_pos=0,two_neg=0,ans=0;
        ans=nums[0]*nums[1]*nums[2];
        two_pos=nums[0]*nums[1];
        two_neg=nums[0]*nums[1];
        max_pos=max(nums[0],nums[1]);
        min_neg=min(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            ans=max(ans,max(nums[i]*two_pos,nums[i]*two_neg));
            two_neg=min(two_neg,min(nums[i]*max_pos,nums[i]*min_neg));
            two_pos=max(two_pos,max(nums[i]*max_pos,nums[i]*min_neg));
            max_pos=max(max_pos,nums[i]);
            min_neg=min(min_neg,nums[i]);
        }
        return ans;
    }
};
