class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int p=0,cr=nums[0],ans=0;
        while(cr<nums.size()-1){
            int maxn=INT_MIN,maxp=0;
            for(int i=p+1;i<=p+nums[p];i++){
                if(i+nums[i]>maxn){
                    maxn=i+nums[i];
                    maxp=i;
                }
            }
            p=maxp;
            cr=p+nums[p];
            ans++;
        }
        return ans+1;
    }
};
