class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        for(int i = 0; i < S.length(); i++){
            if(!(S[i] >= '0' && S[i] <= '9')){
                vector<string> tail = letterCasePermutation(S.substr(i+1));
                string front1 = S.substr(0,i) + char(toupper(S[i]));
                string front2 = S.substr(0,i) + char(tolower(S[i]));
                for(int i = 0; i < tail.size(); i++){
                    ans.push_back(front1 + tail[i]);
                    ans.push_back(front2 + tail[i]);
                }
                break;
            }
        }
        if(ans.size() == 0){
            ans.push_back(S);
        }
        return ans;
    }
};
