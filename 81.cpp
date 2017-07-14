class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        if(target==nums[0]) return true;
        if (target>nums[0]){
            for(int i=1;i<nums.size();i++){
                if(nums[i]==target) return true;
                else if(nums[i]<nums[i-1]) return false;
                else if(nums[i]>target) return false;
            }
            return false;
        }else{
            for(int i=nums.size()-1;i>0;i--){
                if(nums[i]==target) return true;
                else if(nums[i]<nums[i-1]) return false;
                else if(nums[i]<target) return false;
            }
            return false;
        }
    }
};
