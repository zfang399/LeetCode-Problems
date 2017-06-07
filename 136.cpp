class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,bool> single;
        for(int i=0;i<nums.size();i++){
            if(single.count(nums[i])>0){
                single[nums[i]]=false;
            }else{
                single[nums[i]]=true;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(single[nums[i]]) return nums[i];
        }
    }
};
