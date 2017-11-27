class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size() != words2.size()) return false;
        map<pair<string,string>,bool> m;
        for(int i = 0; i < pairs.size(); i++){
            m[pairs[i]] = true;
            m[make_pair(pairs[i].second,pairs[i].first)] = true;
        }
        for(int i = 0; i < words1.size(); i++){
            if(words1[i].compare(words2[i]) == 0) continue;
            if(m[make_pair(words1[i],words2[i])]) continue;
            return false;
        }
        return true;
    }
};
