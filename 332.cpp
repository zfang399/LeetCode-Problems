class Solution {
public:
    map<string,vector<string>> m;
    static bool cmp(string a,string b){
        return a.compare(b)<0;
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for(int i=0;i<tickets.size();i++) m[tickets[i].first].push_back(tickets[i].second);
        for(int i=0;i<tickets.size();i++)
            sort(m[tickets[i].first].begin(),m[tickets[i].first].end(),cmp);
        vector<string> ans;
        int tot=tickets.size();
        ans.push_back("JFK");
        dfs("JFK",ans,0,tot);
        return ans;
    }
    bool dfs(string from,vector<string>& ans,int step,int tot){
        if(m.count(from)==0){
            if(step!=tot) return false;
            return true;
        }
        else if(m[from].size()==0){
            if(step!=tot) return false;
            return true;
        }
        for(int i=0;i<m[from].size();i++){
            ans.push_back(m[from][i]);
            string t=m[from][i];
            m[from].erase(m[from].begin()+i);
            if(dfs(t,ans,step+1,tot)){
                return true;
            }
            m[from].insert(m[from].begin()+i,t);
            ans.pop_back();
        }
        return false;
    }
};
