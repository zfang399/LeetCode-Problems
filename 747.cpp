class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size() < 2){
            return 0;
        }
        int fm = nums[0], sm = 0;
        int ans = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > fm){
                ans = i;
                sm = fm;
                fm = nums[i];
            }else if(nums[i] > sm){
                sm = nums[i];
            }
        }
        return fm >= 2*sm ? ans: -1;
    }
};
