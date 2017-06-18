class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int ans=0;
        int left=0,right=nums.size()-1;
        while(left<nums.size()-1 && nums[left]<=nums[left+1]) left++;
        while(right>0 && nums[right]>=nums[right-1]) right--;
        if(left<right){
            int mmin=INT_MAX,mmax=INT_MIN;
            for(int i=left;i<=right;i++){
                if(nums[i]>mmax) mmax=nums[i];
                if(nums[i]<mmin) mmin=nums[i];
            }
            while(left>=0 && nums[left]>mmin) left--;
            while(right<nums.size() && nums[right]<mmax) right++;
            ans=right-left-1;
        }
        return ans;
    }
};
