class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix_sum(1,0);
        for(int i = 0; i < nums.size(); i++){
            prefix_sum.push_back(prefix_sum[i]+nums[i]);
        }
        for(int i = 1; i <= nums.size(); i++){
            if(prefix_sum[i-1] == prefix_sum.back() - prefix_sum[i]){
                return i-1;
            }
        }
        return -1;
    }
};
