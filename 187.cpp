class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.length()<11) return ans;
        unordered_map<string,int> count;
        for(int i=0;i<=s.length()-10;i++){
            count[s.substr(i,10)]++;
        }
        for(auto e:count){
            if(e.second>1) ans.push_back(e.first);
        }
        return ans;
    }
};
