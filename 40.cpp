class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        queue<vector<int>> q1;
        queue<int> q2,sum;
        int i=candidates.size()-1;
        while(candidates[i]>target) i--;
        while(i>=0){
            vector<int> x;
            x.push_back(candidates[i]);
            q1.push(x);
            q2.push(i-1);
            sum.push(candidates[i]);
            while(candidates[i]==candidates[i-1] && i>0) i--;
            i--;
        }
        while(q1.size()){
            vector<int> v=q1.front();
            q1.pop();
            int r=q2.front();
            q2.pop();
            int s=sum.front();
            sum.pop();
            if(s==target){
                ans.push_back(v);
                continue;
            }
            for(int i=r;i>=0;i--){
                if(candidates[i]>target-s) continue;
                v.push_back(candidates[i]);
                q1.push(v);
                q2.push(i-1);
                sum.push(s+candidates[i]);
                v.erase(v.end()-1,v.end());
                while(candidates[i]==candidates[i-1] && i>0) i--;
            }
        }
        return ans;
    }
};
