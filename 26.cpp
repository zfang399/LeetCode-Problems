class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        for(int i=0;i<nums.size()-1;i++){
            int j=i+1;
            while(nums[j]==nums[i] && j<nums.size()){
                j++;
            }
            nums.erase(nums.begin()+i+1,nums.begin()+j);
        }
        return nums.size();
    }
};
