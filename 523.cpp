class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2) return false;
        vector<int> pre(nums.size());
        pre[0]=nums[0];
        pre[1]=nums[0]+nums[1];
        if(k==0){
            if(pre[1]==0) return true;
            for(int i=2;i<nums.size();i++){
                pre[i]=pre[i-1]+nums[i];
                if(pre[i]==0) return true;
                for(int j=0;j<i-1;j++){
                    if(pre[i]-pre[j]==0) return true;
                }
            }
        }else{
            if(pre[1]%k==0) return true;
            for(int i=2;i<nums.size();i++){
                pre[i]=pre[i-1]+nums[i];
                if(pre[i]%k==0) return true;
                for(int j=0;j<i-1;j++){
                    if((pre[i]-pre[j])%k==0) return true;
                }
            }
        }
        return false;
    }
};
