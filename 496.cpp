class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        map<int,int> big;
        for(int i=0;i<nums.size();i++){
            while(s.size() && s.top()<nums[i]){
                big[s.top()]=nums[i];
                s.pop();
            }
            s.push(nums[i]);
        }
        vector<int> ans;
        for(int i=0;i<findNums.size();i++){
            ans.push_back(big.count(findNums[i]) ? big[findNums[i]] : -1);
        }
        return ans;
    }
};
