class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int maxl=0;
        unordered_map<int,int> count;
        vector<int> mx;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
            if(count[nums[i]]>maxl){
                maxl=count[nums[i]];
                mx.erase(mx.begin(),mx.end());
                mx.push_back(nums[i]);
            }else if(count[nums[i]]==maxl){
                mx.push_back(nums[i]);
            }
        }

        int ans=INT_MAX;
        for(int i=0;i<mx.size();i++){
            int f=0,r=nums.size()-1;
            while(f<nums.size()){
                if(nums[f]==mx[i]) break;
                f++;
            }
            while(r>0){
                if(nums[r]==mx[i]) break;
                r--;
            }
            ans=min(ans,r-f+1);
        }
        return ans;
    }
};
