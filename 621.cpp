class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> count;
        priority_queue<int> q;
        for(int i=0;i<tasks.size();i++){
            count[tasks[i]]++;
        }
        for(auto c:count){
            q.push(c.second);
        }
        int ans=0;
        n++;
        while(q.size()){
            int onc=0;
            vector<int> temp;
            for(int i=0;i<n;i++){
                if(q.size()){
                    temp.push_back(q.top());
                    q.pop();
                    onc++;
                    continue;
                }
                break;
            }
            for(int i=0;i<temp.size();i++){
                temp[i]--;
                if(temp[i]){
                    q.push(temp[i]);
                }
            }
            if(q.size()){
                ans+=n;
            }else{
                ans+=onc;
            }
        }
        return ans;
    }
};
