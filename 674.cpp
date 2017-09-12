class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        int ans=1,t=1;
        for(int i=1;i<nums.size();i++){
            while(nums[i]>nums[i-1] && i<nums.size()){
                t++;
                i++;
            }
            if(t>ans) ans=t;
            t=1;
        }
        return ans;
    }
};
