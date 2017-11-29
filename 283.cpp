class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int now = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]){
                nums[now] = nums[i];
                now++;
            }
        }
        for(int i = now; i < nums.size(); i++) nums[i] = 0;
    }
};
