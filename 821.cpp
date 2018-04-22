class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> cpos;
        for(int i = 0; i < S.length(); i++){
            if(S[i] == C){
                cpos.push_back(i);
            }
        }
        int cur = 0;
        vector<int> ans;
        for(int i = 0; i < S.length(); i++){
            if(cur == cpos.size()){
                ans.push_back(i - cpos[cur - 1]);
                continue;
            }
            if(i == cpos[cur]){
                cur++;
                ans.push_back(0);
            }else{
                if(cur == 0){
                    ans.push_back(cpos[cur] - i);
                }else{
                    ans.push_back(min(i - cpos[cur - 1], cpos[cur] - i));
                }
            }
        }
        return ans;
    }
};
