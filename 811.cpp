class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> vis;
        for(int i = 0; i < cpdomains.size(); i++){
            int sp = cpdomains[i].find(" ");
            int num = stoi(cpdomains[i].substr(0,sp));
            string tmp = cpdomains[i].substr(sp+1);
            vis[tmp] += num;
            size_t found = tmp.find(".");
            while(found!=string::npos){
                tmp = tmp.substr(int(found)+1);
                vis[tmp] += num;
                found = tmp.find(".");
            }
        }

        vector<string> ans;

        for(auto e:vis){
            string now = to_string(e.second);
            now += " ";
            now += e.first;
            ans.push_back(now);
        }

        return ans;
    }
};
