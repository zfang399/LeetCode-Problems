class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans;
        double cursum=0;
        for(int i=0;i<k;i++) cursum+=nums[i];
        ans=cursum/k;
        for(int i=k;i<nums.size();i++){
            cursum+=nums[i]-nums[i-k];
            ans=max(ans,cursum/k);
        }
        return ans;
    }
};
