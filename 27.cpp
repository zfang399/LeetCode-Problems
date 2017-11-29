class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int f = 0, r = nums.size() - 1;
        while(f <= r){
            if(nums[f] == val){
                nums[f] = nums[r];
                nums[r] = val;
                r--;
            }else{
                f++;
            }
        }
        return r + 1;
    }
};
