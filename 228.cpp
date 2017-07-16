class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int f=0,r=0;
        while(r<nums.size()){
            while(nums[r]+1==nums[r+1] && r+1<nums.size()){
                r++;
            }
            if(f==r){
                ans.push_back(to_string(nums[f]));
            }else{
                ans.push_back(to_string(nums[f])+"->"+to_string(nums[r]));
            }
            r++;
            f=r;
        }
        return ans;
    }
};
