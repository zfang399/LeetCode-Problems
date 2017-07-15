class Solution {
public:
    unordered_map<string,bool> v;
    bool wordBreak(string s, vector<string>& wordDict) {
        if(v[s]) return false;
        v[s]=true;
        if(s=="") return true;
        bool ret=false;
        for(int i=0;i<wordDict.size();i++){
            if(s.substr(0,wordDict[i].size()).compare(wordDict[i])==0){
                ret=ret||wordBreak(s.substr(wordDict[i].size()),wordDict);
                if(ret) return ret;
            }
        }
        return ret;
    }
};
