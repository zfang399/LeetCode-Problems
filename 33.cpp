class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        if(target==nums[0]) return 0;
        if (target>nums[0]){
            for(int i=1;i<nums.size();i++){
                if(nums[i]==target) return i;
                else if(nums[i]<nums[i-1]) return -1;
                else if(nums[i]>target) return -1;
            }
            return -1;
        }else{
            for(int i=nums.size()-1;i>0;i--){
                if(nums[i]==target) return i;
                else if(nums[i]<nums[i-1]) return -1;
                else if(nums[i]<target) return -1;
            }
            return -1;
        }
    }
};
