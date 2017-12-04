class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int f = s.size();
        for(int i = s.size()-1; i > 0; i--) {
            if(s[i] < s[i-1]) {
                f = i;
                s[i-1] = s[i-1]-1;
            }
        }
        for(int i = f; i < s.size(); i ++) s[i] = '9';
        return stoi(s);
    }
};
