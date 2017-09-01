class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1=0,n2=0,cnt1,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==n1){
                cnt1+=1;
            }else if(nums[i]==n2){
                cnt2+=1;
            }else if(cnt1==0){
                n1=nums[i];
                cnt1=1;
            }else if(cnt2==0){
                n2=nums[i];
                cnt2=1;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        int t=int(nums.size())/3;
        int x=0,y=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==n1) x++;
            if(nums[i]==n2) y++;
        }
        if(x>t) ans.push_back(n1);
        if(y>t) ans.push_back(n2);
        return ans;
    }
};
