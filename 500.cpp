class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char,int> key;
        key['q']=1,key['w']=1,key['e']=1,key['r']=1,key['t']=1,key['y']=1,key['u']=1,key['i']=1,key['o']=1,key['p']=1;
        key['a']=2,key['s']=2,key['d']=2,key['f']=2,key['g']=2,key['h']=2,key['j']=2,key['k']=2,key['l']=2;
        key['z']=3,key['x']=3,key['c']=3,key['v']=3,key['b']=3,key['n']=3,key['m']=3;
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            bool oneline=true;
            for(int j=0;j<words[i].size()-1;j++){
                if(key[tolower(words[i][j])]!=key[tolower(words[i][j+1])]){
                    oneline=false;
                    break;
                }
            }
            if(oneline) ans.push_back(words[i]);
        }
        return ans;
    }
};
