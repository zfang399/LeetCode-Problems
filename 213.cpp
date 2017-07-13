class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        return max(robo(nums,0,nums.size()-2),robo(nums,1,nums.size()-1));
    }
    int robo(vector<int>& nums,int f,int r){
        vector<int> rob(nums.size());
        rob[f]=nums[f],rob[f+1]=max(nums[f+1],nums[f]);
        for(int i=f+2;i<=r;i++){
            rob[i]=max(rob[i-2]+nums[i],rob[i-1]);
        }
        return rob[r];
    }
};
