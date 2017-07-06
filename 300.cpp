class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> l(nums.size());
        l[0]=1;
        int ans=1;
        for(int i=1;i<nums.size();i++){
            l[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]) l[i]=max(l[i],l[j]+1);
            }
            if(l[i]>ans) ans=l[i];
        }
        return ans;
    }
};
