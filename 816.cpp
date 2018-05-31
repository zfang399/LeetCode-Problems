class Solution {
public:
    // Get all the possible combinations of a single string s
    // e.g. getComb("123") will return {"123", "1.23", "12.3}
    vector<string> getComb(string s){
        vector<string> res;

        // Case1: S starts with 0
        // if s is purely consisted of 0s, only "0" is possible
        if(stoi(s) == 0){
            if(s.length() == 1) res.push_back(s);
            return res;
        }
        // if the string is "0xxxx", the only possible one is "0.xxxx"
        if(s[0] == '0'){
            if(s[s.length() - 1] == '0') return res;        // "0xxx0" does not work
            string tmp = s.substr(0,1) + "." + s.substr(1);
            res.push_back(tmp);
            return res;
        }

        // Case2: S starts with a nonzero number
        res.push_back(s);   // add original string
        // if length is one, nowhere to add "."
        // if last digit is 0, cannot add "." as well
        if(s.length() == 1 || s[s.length() - 1] == '0') return res;
        // Try all combinations
        for(int i = 1; i < s.length(); i++){
            string x1 = s.substr(0, i);
            string x2 = s.substr(i);
            if(stoi(x2) == 0) continue; // cannot add "xxx.0"
            string tmp = x1 + "." + x2;
            res.push_back(tmp);
        }
        return res;
    }
    vector<string> ambiguousCoordinates(string S) {
        vector<string> ans;
        // Get rid of the "()"
        S = S.substr(1, S.length() - 2);
        // Loop through all possible segmentations s1 + s2
        for(int i = 1; i < S.length(); i++){
            string s1 = S.substr(0, i);
            string s2 = S.substr(i);
            // Get the possible combinations
            vector<string> c1 = getComb(s1);
            vector<string> c2 = getComb(s2);
            // Add answers through a loop
            for(int j = 0; j < c1.size(); j++){
                for(int k = 0; k < c2.size(); k++){
                    string tmp = "(" + c1[j] + ", " + c2[k] + ")";
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};
