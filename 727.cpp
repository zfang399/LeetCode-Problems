class Solution {
public:
    string minWindow(string S, string T) {
        int s_len = S.length();
        int t_len = T.length();
        vector<vector<int>> L(s_len, vector<int>(t_len, -1));
        if(S[0] == T[0]) L[0][0] = 0;
        for(int i = 1; i < s_len; i++){
            if(S[i] == T[0]) L[i][0] = i;
            else L[i][0] = L[i - 1][0];
            for(int j = 1; j < t_len; j++){
                if(S[i] == T[j]){
                    L[i][j] = L[i - 1][j - 1];
                }else{
                    L[i][j] = L[i - 1][j];
                }
            }
        }
        int front = 0;
        int min_len = s_len + 1;
        bool found = false;
        for(int i = 0; i < s_len; i++){
            //cout<<L[i][t_len - 1] << endl;
            if(L[i][t_len - 1] != -1){
                if(i - L[i][t_len - 1] + 1 < min_len){
                    found = true;
                    front = L[i][t_len - 1];
                    min_len = i - L[i][t_len - 1] + 1;
                }
            }
        }
        if (found) return S.substr(front, min_len);
        return "";
    }
};
