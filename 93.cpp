class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if(s.length()<4 || s.length()>12) return ans;
        vector<string> x;
        dfs(ans,s,x,0,4);
        return ans;
    }
    void dfs(vector<string>& ans,string &s, vector<string>&x, int f,int rem){
        if(rem==0){
            if(f==s.length()){
                string p=x[0];
                for(int i=1;i<x.size();i++){
                    p+="."+x[i];
                }
                ans.push_back(p);
            }
            return;
        }
        for(int i=1;i<4;i++){
            if(f+i>s.length()){
                break;
            }
            string t=s.substr(f,i);
            if(((t[0]=='0') && t.length()>1) || (i==3 && stoi(t) >= 256)) continue;
            x.push_back(t);
            dfs(ans,s,x,f+i,rem-1);
            x.pop_back();
        }
    }
};
