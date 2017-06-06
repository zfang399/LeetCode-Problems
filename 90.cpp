class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans={{}};
        for(int i=0; i<nums.size();){
            int count=0;
            while(count+i<nums.size() && nums[count+i]==nums[i]) count++;
            int prev=ans.size();
            for(int j=0;j<prev;j++){
                vector<int> tmp=ans[j];
                for(int k=0;k<count;k++){
                    tmp.push_back(nums[i]);
                    ans.push_back(tmp);
                }
            }
            i+=count;
        }
        return ans;
    }
};
