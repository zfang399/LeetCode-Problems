class Solution {
public:
    static bool cmp(int a, int b){
        return a>b;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if(sum%k) return false;
        sort(nums.begin(),nums.end(),cmp);
        vector<int> sums(k,0);
        return dfs(nums,sums,0,sum/k);
    }
    bool dfs(vector<int>& nums,vector<int>& sums,int index,int sum){
        if(index==nums.size()) return true;
        if(nums[index]>sum) return false;
        for(int i=0;i<sums.size();i++){
            if(sums[i]+nums[index]<=sum){
                sums[i]+=nums[index];
                if(dfs(nums,sums,index+1,sum)) return true;
                sums[i]-=nums[index];
            }
        }
        return false;
    }
};
