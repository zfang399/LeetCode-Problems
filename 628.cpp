class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int last=nums.size()-1;
        return max(max(nums[last]*nums[last-1]*nums[last-2],nums[0]*nums[1]*nums[last]),nums[0]*nums[1]*nums[2]);
    }
};
