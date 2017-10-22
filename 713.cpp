class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int j=i;
            int tmp=1;
            while(tmp*nums[j]<k && j<nums.size()){
                tmp*=nums[j];
                if(tmp>=k) break;
                j++;
                ans++;
            }
        }
        return ans;
    }
};
