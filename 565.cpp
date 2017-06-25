class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans=INT_MIN;
        bool visited[20005]={false};
        unordered_map <int,int> maxc;
        for(int i=0;i<nums.size();i++){
            if(visited[i]) continue;
            visited[i]=true;
            maxc[i]=1;
            if(nums[i]!=i){
                int j=nums[i];
                while(nums[j]!=i && maxc[j]==0){
                    visited[j]=true;
                    maxc[i]++;
                    j=nums[j];
                }
                maxc[i]+=maxc[j];
            }
            if(ans<maxc[i]) ans=maxc[i];
        }
        return ans;
    }
};
