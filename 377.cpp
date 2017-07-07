class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> combi(target+1);
        combi[0]=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<=target;i++){
            for(auto num:nums){
                if(i<num) break;
                combi[i]+=combi[i-num];
            }
        }
        return combi[target];
    }
};
