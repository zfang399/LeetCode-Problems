class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()<=2) return true;
        bool used=false;
        vector<int> mins(nums.size(),INT_MAX);
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                if(!used){
                    used=true;
                    if(i-2<0 || nums[i]>=nums[i-2]) nums[i-1]=nums[i];
                    else nums[i]=nums[i-1];
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
