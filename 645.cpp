class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<bool> v(nums.size(),false);
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(v[nums[i]-1]) ans.push_back(nums[i]);
            v[nums[i]-1]=true;
        }
        for(int i=0;i<v.size();i++){
            if(!v[i]){
                ans.push_back(i+1);
                break;
            }
        }
        return ans;
    }
};
