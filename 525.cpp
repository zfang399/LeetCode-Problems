class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zero=0,one=0,ans=0;
        unordered_map<int,int> zod;
        zod[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]) one++;
            else zero++;
            if(zod.count(zero-one)>0) ans=max(ans,i-zod[zero-one]);
            else zod[zero-one]=i;
        }
        return ans;
    }
};
