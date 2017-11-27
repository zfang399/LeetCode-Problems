class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        map<string, string> m;
        for (int i = 0; i < pairs.size(); i++){
            string parent1 = find(m, pairs[i].first);
            string parent2 = find(m, pairs[i].second);
            if (parent1 != parent2) m[parent1] = parent2;
        }

        for (int i = 0; i < words1.size(); i++){
            if(words1[i].compare(words2[i]) == 0) continue;
            if(find(m,words1[i]).compare(find(m,words2[i])) == 0) continue;
            return false;
        }
        return true;
    }

    string find(map<string, string>& m, string s){
        if(m.count(s)){
            if(m[s] == s){
                return s;
            }
            return find(m, m[s]);
        }else{
            m[s] = s;
            return s;
        }
    }
};
