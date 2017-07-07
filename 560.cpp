class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> count;
        int tsum=0,ans=0;
        count[0]++;
        for(int i=0;i<nums.size();i++){
            tsum+=nums[i];
            ans+=count[tsum-k];
            count[tsum]++;
        }
        return ans;
    }
};
