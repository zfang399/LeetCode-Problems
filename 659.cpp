class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int st=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]-nums[i-1]>1){
                if(!work(nums,st,i-1)) return false;
                st = i;
            }
        }
        return work(nums,st,nums.size()-1);
    }

    bool work(vector<int>& nums, int f, int r){
        vector<int> count(nums[r]-nums[f]+1,0);
        for(int i=f;i<=r;i++){
            count[nums[i]-nums[f]]++;
        }
        vector<int> one(nums[r]-nums[f]+2,0), two(nums[r]-nums[f]+2,0), tot(nums[r]-nums[f]+2,0);
        for(int i=0;i<nums[r]-nums[f]+1;i++){
            if(count[i]<one[i]+two[i]) return false;
            two[i+1]=one[i];
            one[i+1]=max(0,count[i]-tot[i]);
            tot[i+1]=count[i];
        }
        if(one[nums[r]-nums[f]+1]==0 & two[nums[r]-nums[f]+1]==0) return true;
        return false;
    }
};
