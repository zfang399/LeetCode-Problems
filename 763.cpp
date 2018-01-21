class Solution {
public:
    vector<int> partitionLabels(string S) {
      vector<int> ans;
      vector<int> last(26, 0);
      for(int i = 0; i < S.size(); i++){
          last[S[i] - 'a'] = i;
      }
      for(int i = 0, idx = INT_MIN, last_i = 0; i < S.size(); ++i) {
        idx = max(idx, last[S[i] - 'a']);
        if (idx == i){
            ans.push_back(i - last_i + 1);
            last_i = i + 1;
        }
      }
      return ans;
    }
};
