class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        if(nums.size()==2){
            if(nums[0]==nums[1]) return 1;
            return 2;
        }
        vector<int> v1,v2;
        v1.push_back(nums[0]);
        v2.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(v1.size()%2){
                if(nums[i]>v1.back()){
                    v1.push_back(nums[i]);
                }else{
                    v1.back()=nums[i];
                }
            }else{
                if(nums[i]<v1.back()){
                    v1.push_back(nums[i]);
                }else{
                    v1.back()=nums[i];
                }
            }

            if(v2.size()%2){
                if(nums[i]<v2.back()){
                    v2.push_back(nums[i]);
                }else{
                    v2.back()=nums[i];
                }
            }else{
                if(nums[i]>v2.back()){
                    v2.push_back(nums[i]);
                }else{
                    v2.back()=nums[i];
                }
            }
        }
        return max(v1.size(),v2.size());
    }
};
