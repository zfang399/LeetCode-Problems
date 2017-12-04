class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        if(!temp.size()){
            vector<int> ans;
            return ans;
        }else if(temp.size() < 2){
            vector<int> ans;
            ans.push_back(0);
            return ans;
        }

        vector<int> ans(temp.size(),0);

        stack<int> tps;
        stack<int> index;

        tps.push(temp[0]);
        index.push(0);
        for(int i = 1; i < temp.size(); i++){
            while(tps.size() && tps.top() < temp[i]){
                ans[index.top()] = i - index.top();
                index.pop();
                tps.pop();
            }
            tps.push(temp[i]);
            index.push(i);
        }
        return ans;
    }
};
