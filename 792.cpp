class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        unordered_map<string,bool> possible;
        int ans = 0;
        for(int i = 0; i < words.size(); i++){
            if(possible[words[i]]){
                ans++;
                continue;
            }
            bool exist = true;
            int cur = 0;
            for(int j = 0; j < words[i].length(); j++){
                cur = S.find(words[i][j], cur);
                if(cur == string::npos) break;
                else cur++;
            }
            if(cur != string::npos) {
                possible[words[i]] = true;
                ans++;
            }
        }
        return ans;
    }
};
