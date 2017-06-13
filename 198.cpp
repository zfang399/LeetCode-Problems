class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int> rob(nums.size());
        rob[0]=nums[0],rob[1]=max(nums[1],nums[0]);
        for(int i=2;i<nums.size();i++){
            rob[i]=max(rob[i-2]+nums[i],rob[i-1]);
        }
        return rob[nums.size()-1];
    }
};
