class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int orimid=nums[nums.size()/2];
        nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=abs(nums[i]-nums[nums.size()/2]);
        }
        return ans;
    }
};
