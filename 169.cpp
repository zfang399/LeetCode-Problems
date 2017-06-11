class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x=nums.size()/2;
        map <int,int> count;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
            if(count[nums[i]]>x) return nums[i];
        }
    }
};
