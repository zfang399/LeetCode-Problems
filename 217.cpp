class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map <int,bool> dis;
        for(int i=0;i<nums.size();i++){
            if(dis[nums[i]]) return true;
            dis[nums[i]]=true;
        }
        return false;
    }
};
 
