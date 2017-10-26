class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> need;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            need[target-nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            if(need.count(nums[i])>0){
                if(need[nums[i]]!=i){
                    ans.push_back(i);
                    ans.push_back(need[nums[i]]);
                    break;
                }
            }
        }
        return ans;
    }
}; 
