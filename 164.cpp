class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int ans=INT_MIN,minn=nums[0],maxn=nums[0];
        for(int i=1;i<nums.size();i++){
            minn=min(minn,nums[i]);
            maxn=max(maxn,nums[i]);
        }
        int buc_size=max(1,(maxn-minn)/(int(nums.size())-1));
        int buc_num=(maxn-minn)/buc_size+1;
        vector<int> bucmin(buc_num,INT_MAX);
        vector<int> bucmax(buc_num,INT_MIN);
        vector<int> buccount(buc_num,0);
        for(int i=0;i<nums.size();i++){
            int bucid=(nums[i]-minn)/buc_size;
            buccount[bucid]++;
            bucmin[bucid]=min(bucmin[bucid],nums[i]);
            bucmax[bucid]=max(bucmax[bucid],nums[i]);
        }
        int pre=minn;
        for(int i=0;i<buc_num;i++){
            if(buccount[i]==0) continue;
            ans=max(ans,bucmin[i]-pre);
            pre=bucmax[i];
        }
        return ans;
    }
};
