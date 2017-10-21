class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(0);
        for(int i=0;i<nums.size();i++){
            while(nums[i]!=i && nums[i]>0 && nums[i]<=n){
                if(nums[i]==nums[nums[i]]){
                    nums[i]=0;
                    break;
                }
                swap(nums[i],nums[nums[i]]);
            }
            if(nums[i]>n || nums[i]<0){
                nums[i]=0;
            }
        }
        for(int i=1;i<nums.size();i++){
            //cout<<nums[i];
            if(nums[i]==0) return i;
        }
        return n+1;
    }
};
