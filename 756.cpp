class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<string, vector<char>> poss;
        map<string, bool> vis;
        // Put the allowed combinations into map
        for(int i = 0; i < allowed.size(); i++) poss[allowed[i].substr(0,2)].push_back(allowed[i][2]);
        return dfs(bottom, poss, vis);
    }

    bool dfs(string bottom, map<string, vector<char>>& poss, map<string, bool>& vis){
        if(vis[bottom]) return false;
        if(bottom.length() == 1) return true;
        vis[bottom] = true;
        vector<string> nextl;
        string s = "";
        nextl.push_back(s);
        // construct all the possible strings for the next level
        for(int i = 0; i < bottom.length() - 1; i++){
            int ncur_size = nextl.size();
            string cur_comb = bottom.substr(i,2);
            for(int j = 0; j < poss[cur_comb].size(); j++){
                for(int k = 0; k < ncur_size; k++){
                    nextl.push_back(nextl[k] + poss[cur_comb][j]);
                }
            }
            nextl.erase(nextl.begin(), nextl.begin() + ncur_size);
        }

        // try all the possible strings
        for(int i = 0; i < nextl.size(); i++){
            if(dfs(nextl[i],poss,vis)) return true;
        }
        return false;
    }
};
