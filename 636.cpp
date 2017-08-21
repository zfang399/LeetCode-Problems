class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n,0);
        stack <int> ids,ts;
        for(int i=0;i<logs.size();i++){
            int f=0,r=logs[i].size()-1;
            while(logs[i][f]!=':'){
                f++;
            }
            while(logs[i][r]!=':'){
                r--;
            }
            int id=stoi(logs[i].substr(0,f));
            int t=stoi(logs[i].substr(r+1));
            string s=logs[i].substr(f+1,r-1-f);
            if(s.compare("start")==0){
                ids.push(id);
                ts.push(t);
            }else{
                //cout<<t<<" "<<ts.top()<<endl;
                int tmp=t-ts.top()+1;
                ans[id]+=tmp;
                ts.pop();
                ids.pop();
                if(ids.size()){
                    ans[ids.top()]-=tmp;
                }
            }
        }
        return ans;
    }
};
