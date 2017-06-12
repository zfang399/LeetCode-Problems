class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> count;
        typedef map<int,int>::iterator it_type;
        int ans=0;
        for(int i=0;i<nums.size();i++) count[nums[i]]++;
        for(int i=0;i<nums.size();i++){
            if(count[nums[i]]+count[nums[i]+1]>ans && count[nums[i]+1]!=0) ans=count[nums[i]]+count[nums[i]+1];
        }
        return ans;
    }
};
