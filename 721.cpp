class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<bool> vis(accounts.size(),false);
        unordered_map<string,vector<int>> m;
        vector<vector<string>> ans;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                string email = accounts[i][j];
                m[email].push_back(i);
            }
        }
        for(int i=0;i<accounts.size();i++){
            if(!vis[i]){
                set<string> es;
                set<string>::iterator it;
                dfs(accounts,m,vis,i,es);
                vector<string> ret;
                ret.push_back(accounts[i][0]);
                for(it=es.begin(); it!=es.end(); ++it){
                    ret.push_back(*it);
                }
                ans.push_back(ret);
            }
        }
        return ans;
    }
    void dfs(vector<vector<string>>& accounts,unordered_map<string,vector<int>>& m,vector<bool>& vis,int i,set<string> & es){
        if(vis[i]) return;
        vis[i]=true;
        for(int j=1;j<accounts[i].size();j++){
            string email = accounts[i][j];
            es.insert(email);
            for(int k=0;k<m[email].size();k++){
                dfs(accounts,m,vis,m[email][k],es);
            }
        }
    }
};
