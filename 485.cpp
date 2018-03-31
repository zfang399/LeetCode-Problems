class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxr = 0, ins = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]){
                ins++;
            }else{
                if(ins > maxr) maxr = ins;
                ins = 0;
            }
        }
        if(ins > maxr) maxr = ins;
        return maxr;
    }
};
