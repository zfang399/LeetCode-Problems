class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if(s.length()==0) return ans;
        vector<string> p;
        dfs(ans,p,s,0);
        return ans;
    }
    void dfs(vector<vector<string>>& ans, vector<string>& p,string& s,int f){
        if(f==s.length()){
            ans.push_back(p);
            return;
        }
        for(int i=f;i<s.size();i++){
            if(ispalin(s,f,i)){
                p.push_back(s.substr(f,i-f+1));
                dfs(ans,p,s,i+1);
                p.pop_back();
            }
        }
    }
    bool ispalin(const string& s, int f, int r){
        while(f<=r){
            if(s[f]==s[r]){
                f++;
                r--;
                continue;
            }
            return false;
        }
        return true;
    }
};
