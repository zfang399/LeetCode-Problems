class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3) return nums.size();
        int f=0,r=1;
        while(r<nums.size()){
            if(nums[f]==nums[r]){
                if(r-f>1) nums.erase(nums.begin()+r,nums.begin()+r+1);
                else r++;
            }else{
                f=r;
                r++;
            }
        }
        return nums.size();
    }
};
