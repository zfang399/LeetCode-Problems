class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.size()==0) return ans;
        priority_queue<int> q;
        unordered_map<int,int> inque;
        for(int i=0;i<k;i++){
            q.push(nums[i]);
            inque[nums[i]]++;
        }
        int x=k;
        ans.push_back(q.top());
        while(x<nums.size()){
            inque[nums[x-k]]--;
            inque[nums[x]]++;
            q.push(nums[x]);
            int t;
            while(q.size()){
                t=q.top();
                if(inque[t]) break;
                q.pop();
            }
            ans.push_back(t);
            x++;
        }
        return ans;
    }
};
