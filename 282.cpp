class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if(num.size()==0) return ans;
        for(int i=1;i<=num.size();i++){
            string x=num.substr(0,i);
            long now=stol(x);
            if(to_string(now).size() != x.size()) continue;
            dfs(ans,num,x,target,i,now,now,'!');
        }
        return ans;
    }
    void dfs(vector<string>& ans,string& num,string x,int target,int p,long cur,long prev,char op){
        if(p==num.size() && cur==target){
            ans.push_back(x);
        }else{
            for(int i=p+1;i<=num.size();i++){
                string t=num.substr(p,i-p);
                long now=stol(t);
                if(to_string(now).size()!=t.size()) continue;
                dfs(ans,num,x+"+"+t,target,i,cur+now,now,'+');
                dfs(ans,num,x+"-"+t,target,i,cur-now,now,'-');
                if(op=='-'){
                    dfs(ans,num,x+"*"+t,target,i,cur+prev-prev*now,prev*now,'-');
                }else{
                    if(op=='+'){
                        dfs(ans,num,x+"*"+t,target,i,cur-prev+prev*now,prev*now,'+');
                    }else{
                        dfs(ans,num,x+"*"+t,target,i,prev*now,prev*now,op);
                    }
                }
            }
        }
    }
};
