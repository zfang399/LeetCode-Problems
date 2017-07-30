class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_map<string,bool> visited;
        vector<string> ans;
        int lm=0,rm=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                lm++;
            }else if(s[i]==')'){
                if(lm>0) lm--;
                else rm++;
            }
        }
        if(lm+rm==0){
            ans.push_back(s);
            return ans;
        }
        queue<string> q;
        queue<int> rdl,rdr;
        q.push(s);
        rdl.push(0);
        rdr.push(0);
        while(q.size()){
            string now=q.front();
            q.pop();
            int nowl=rdl.front();
            rdl.pop();
            int nowr=rdr.front();
            rdr.pop();
            int ll=0;
            if(nowl==lm && nowr==rm){
                int c=0;
                for(int i=0;i<now.size();i++){
                    if(now[i]=='('){
                        c++;
                    }else if(now[i]==')'){
                        c--;
                        if(c<0) break;
                    }
                }
                if(c==0) ans.push_back(now);
            }
            for(int i=0;i<now.length();i++){
                if(now[i]!='(' && now[i]!=')'){
                    continue;
                }else if(now[i]=='('){
                    ll++;
                    if(nowl==lm) continue;
                    string t=now.substr(0,i)+now.substr(i+1);
                    if(!visited[t]){
                        q.push(t);
                        rdl.push(nowl+1);
                        rdr.push(nowr);
                        visited[t]=true;
                    }
                    while(now[i+1]==now[i]){
                        ll++;
                        i++;
                    }
                }else{
                    ll--;
                    //cout<<now<<" "<<i<<" "<<ll<<endl;
                    if(nowr==rm) continue;
                    string t=now.substr(0,i)+now.substr(i+1);
                    if(!visited[t]){
                        q.push(t);
                        rdl.push(nowl);
                        rdr.push(nowr+1);
                        visited[t]=true;
                    }
                    if(ll<0) break;
                }
            }
        }
        return ans;
    }
};
