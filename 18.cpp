class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        map<vector<int>,bool> e;
        int n=nums.size();
        if(n<4) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int f=j+1,r=n-1;
                int sum=nums[i]+nums[j]+nums[f]+nums[r];
                while(f<r){
                    sum=nums[i]+nums[j]+nums[f]+nums[r];
                    if(sum==target){
                        if(!e[{nums[i],nums[j],nums[f],nums[r]}])
                            ans.push_back({nums[i],nums[j],nums[f],nums[r]});
                        e[{nums[i],nums[j],nums[f],nums[r]}]=true;
                        f++;
                        r--;
                    }else if(sum>target){
                        r--;
                    }else{
                        f++;
                    }
                }
            }
        }
        return ans;
    }
};
