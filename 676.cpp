class MagicDictionary {
public:
    map<int,vector<string>> dic;
    /** Initialize your data structure here. */
    MagicDictionary() {
        dic.erase(dic.begin(),dic.end());
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(int i=0;i<dict.size();i++){
            dic[dict[i].length()].push_back(dict[i]);
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int l=word.length();
        if(dic[l].size()==0) return false;
        for(int i=0;i<dic[l].size();i++){
            int k=0;
            for(int j=0;j<l;j++){
                if(dic[l][i][j]!=word[j]){
                    k++;
                    if(k>1) break;
                }
            }
            if(k==1) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
