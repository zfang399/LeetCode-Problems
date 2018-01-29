class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char,bool> jewel;
        for(int i = 0; i < J.size(); i++) jewel[J[i]] = true;
        int ans = 0;
        for(int i = 0; i < S.size(); i++) ans += jewel[S[i]] ? 1 : 0;
        return ans;
    }
};
