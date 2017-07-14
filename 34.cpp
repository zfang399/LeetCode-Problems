class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        if(nums.size()==0) return ans;
        int f=0,r=nums.size()-1,mid;
        while(f<=r){
            mid=(f+r)/2;
            if(nums[mid]==target){
                break;
            }else if(nums[mid]>target){
                r=mid-1;
            }else{
                f=mid+1;
            }
        }
        if(nums[mid]!=target) return ans;
        int i=mid-1;
        while(nums[i]==target && i>=0) i--;
        ans[0]=i+1;
        i=mid+1;
        while(nums[i]==target && i<nums.size()) i++;
        ans[1]=i-1;
        return ans;
    }
};
