class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        bool finish = false;
        vector<bool> outed(graph.size(), false);
        while(!finish){
            finish = true;
            map<int,bool> zeroout;
            for(int i = 0; i < graph.size(); i++){
                if(graph[i].size() == 0 && !outed[i]){
                    outed[i] = true;
                    finish = false;
                    zeroout[i] = true;
                }
            }

            for(int i = 0; i < graph.size(); i++){
                for(int j = 0; j < graph[i].size(); j++){
                    if(zeroout[graph[i][j]]){
                        graph[i].erase(graph[i].begin() + j);
                        j--;
                    }
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i < graph.size(); i++){
            if(graph[i].size() == 0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
