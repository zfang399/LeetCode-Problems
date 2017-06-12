class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> presum(nums.size()+1);
        presum[0]=nums[0];
        int smallest=min(0,presum[0]),ans=nums[0];
        for(int i=1;i<nums.size();i++){
            presum[i]=presum[i-1]+nums[i];
            cout<<presum[i]<<endl;
            if(presum[i]-smallest>ans){
                ans=presum[i]-smallest;
            }
            if(presum[i]<smallest){
                smallest=presum[i];
            }
        }
        return ans;
    }
};
