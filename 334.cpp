class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3) return false;
        int ai=INT_MAX,aj=INT_MAX;
        for(int x=0;x<nums.size();x++){
            if(nums[x]<=ai){
                ai=nums[x];
            }else if(nums[x]<=aj){
                aj=nums[x];
            }else return true;
        }
        return false;
    }
};
