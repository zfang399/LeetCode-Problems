class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int w = 0;
        int lines = 1;
        for(int i = 0; i < S.length(); i++){
            w += widths[S[i] - 'a'];
            if(w > 100){
                lines++;
                w = 0;
                i--;
            }
        }
        vector<int> ans;
        ans.push_back(lines);
        ans.push_back(w);
        return ans;
    }
};
