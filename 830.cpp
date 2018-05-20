class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ans;
        if(S.length() < 3) return ans;
        char c = S[0];
        int start = 0;
        for(int i = 1; i < S.length(); i++){
            if(S[i] != c){
                c = S[i];
                if(i - start - 1>= 2){
                    ans.push_back({start, i - 1});
                }
                start = i;
            }
        }
        if(S.length() - start - 1 >= 2){
            ans.push_back({start, S.length() - 1});
        }
        return ans;
    }
};
