class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        map<int,int> rank;
        vector<int> tmp=nums;
        vector<string> ans;
        sort(tmp.begin(),tmp.end(), greater<int>());
        for(int i=0;i<tmp.size();i++) rank[tmp[i]]=i+1;
        for(int i=0;i<nums.size();i++){
            switch(rank[nums[i]]){
                case 1: ans.push_back("Gold Medal");
                break;
                case 2: ans.push_back("Silver Medal");
                break;
                case 3: ans.push_back("Bronze Medal");
                break;
                default: ans.push_back(to_string(rank[nums[i]]));
                break;
            }
        }
        return ans;
    }
};
