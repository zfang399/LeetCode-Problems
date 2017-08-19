class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> c;
        for(int i=0;i<nums.size();i++) c[nums[i]]++;
        for(auto e:c){
            if(e.second==1) return e.first;
        }
    }
};
