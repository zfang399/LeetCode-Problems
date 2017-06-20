class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if(nums.size()==1) return to_string(nums[0]);
        if(nums.size()==2) return to_string(nums[0])+'/'+to_string(nums[1]);
        string ans=to_string(nums[0])+"/(";
        for(int i=1;i<nums.size()-1;i++){
            ans+=to_string(nums[i])+'/';
        }
        ans+=to_string(nums[nums.size()-1])+')';
        return ans;
    }
};
