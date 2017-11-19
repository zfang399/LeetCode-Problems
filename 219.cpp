class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map <int,int> index;
        for(int i=0;i<nums.size();i++){
            if(index[nums[i]]==0){
                index[nums[i]]=i+1;
            }else if(i-index[nums[i]]+1<=k){
                return true;
            }else{
                index[nums[i]]=i+1;
            }
        }
        return false;
    }
}; 
