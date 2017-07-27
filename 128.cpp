class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> c(nums.begin(),nums.end());
        int ans=0;
        for(int n:nums){
            if(c.find(n)==c.end()) continue;
            c.erase(n);
            int l= n-1,r= n+1;
            while(c.find(l)!=c.end()) c.erase(l--);
            while(c.find(r)!=c.end()) c.erase(r++);
            ans= max(ans,r-l-1);
        }
        return ans;
    }
};
