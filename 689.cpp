class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        int maxa=0;
        vector<int> pre;
        vector<int> pl(n,0),pr(n,n-k);

        pre.push_back(0);
        for(int i=0;i<n;i++){
            pre.push_back(pre.back()+nums[i]);
        }

        int ml=pre[k]-pre[0];
        for(int i=k;i<n;i++){
            if(pre[i+1]-pre[i-k+1]>ml){
                ml=pre[i+1]-pre[i-k+1];
                pl[i]=i-k+1;
            }else{
                pl[i]=pl[i-1];
            }
        }

        int mr=pre[n]-pre[n-k];
        for(int i=n-k-1;i>0;i--){
            if(pre[i+k]-pre[i]>=mr){
                mr=pre[i+k]-pre[i];
                pr[i]=i;
            }else{
                pr[i]=pr[i+1];
            }
        }

        for(int i=k;i<=n-2*k;i++){
            int l=pl[i-1],r=pr[i+k];
            if(pre[i+k]-pre[i]+pre[l+k]-pre[l]+pre[r+k]-pre[r]>maxa){
                maxa=pre[i+k]-pre[i]+pre[l+k]-pre[l]+pre[r+k]-pre[r];
                ans={l,i,r};
            }
        }
        return ans;
    }
};
