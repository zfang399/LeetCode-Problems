class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> len(nums.size(),0);
        vector<int> get(nums.size(),0);
        int ll=0,ans=0;
        for(int i=0;i<nums.size();i++){
            len[i]=1;
            get[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(len[j]+1>len[i]){
                        len[i]=len[j]+1;
                        get[i]=get[j];
                    }else if(len[j]+1==len[i]){
                        get[i]+=get[j];
                    }
                }
            }
            if(ll<len[i]){
                ll=len[i];
                ans=get[i];
            }else if(ll==len[i]){
                ans+=get[i];
            }
            //cout<<get[i]<<" "<<len[i]<<endl;
        }
        return ans;
    }
};
