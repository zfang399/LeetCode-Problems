class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> sa, sb;

        // Process string A
        string tmp  = "";
        for(int i = 0; i < A.length(); i++){
            if(A[i] != ' '){
                tmp += A[i];
            }else{
                sa[tmp]++;
                tmp = "";
            }
        }
        if(tmp.length() != 0) sa[tmp]++;

        // Process string B
        tmp  = "";
        for(int i = 0; i < B.length(); i++){
            if(B[i] != ' '){
                tmp += B[i];
            }else{
                sb[tmp]++;
                tmp = "";
            }
        }
        if(tmp.length() != 0) sb[tmp]++;

        // Get answers
        vector<string> ans;
        for(auto s:sa){
            if(s.second == 1 && sb[s.first] == 0){
                ans.push_back(s.first);
            }
        }

        for(auto s:sb){
            if(s.second == 1 && sa[s.first] == 0){
                ans.push_back(s.first);
            }
        }

        return ans;
    }
};
