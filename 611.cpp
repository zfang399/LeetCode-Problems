class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int ans=0;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                int k=nums.size()-1;
                while(j<k && nums[j]+nums[k]<=nums[i]) k--;
                ans+=k-j;
            }
        }
        return ans;
    }
};
