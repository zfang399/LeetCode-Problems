class Solution {
public:
    bool canJump(vector<int>& nums) {
        int now_max=0;
        for(int i=0;i<nums.size();i++){
            if(i>now_max) return false;
            now_max=max(now_max,i+nums[i]);
        }
        return true;
    }
};
