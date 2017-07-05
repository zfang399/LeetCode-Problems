class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0) return 0;
        int f=0,r=0,nowsum=nums[0],nowstep=1;
        int ans=INT_MAX;
        while(r<nums.size()){
            if(nowsum>=s){
                if(nowstep<ans) ans=nowstep;
                nowsum-=nums[f];
                f++;
                nowstep--;
            }else{
                r++;
                nowstep++;
                nowsum+=nums[r];
            }
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};
