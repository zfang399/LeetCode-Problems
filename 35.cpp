class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans=0;
        bool found=false;
        for(int i=0;i<nums.size();i++){
            if(target<nums[i] && target>nums[i-1]){
                found=true;
                ans=i;
            }else if(target==nums[i]){
                ans=i;
                break;
            }else if(target>nums[i]&&!found){
                ans=i+1;
            }
        }
        return ans;
    }
};
 
