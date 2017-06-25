class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> k;
        for(int i=0;i<nums.size();i++){
            k.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            k.push_back(nums[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int count=i+1;
            bool found=false;
            while(count<nums.size()+i){
                if(k[count]>nums[i]){
                    ans.push_back(k[count]);
                    found=true;
                    break;
                }
                count++;
            }
            if(!found) ans.push_back(-1);
        }
        return ans;
    }
};
