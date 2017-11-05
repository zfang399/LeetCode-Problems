class Solution {
public:
    struct cmp{
        bool operator()(string a, string b){
            if(a.length()!=b.length()) return a.length()>b.length();
            return a<b;
        }
    };

    string longestWord(vector<string>& words) {
        if(words.size()==0) return "";
        set<string,cmp> wset(words.begin(),words.end());
        for(auto s:wset){
            bool work=true;
            for(int i=1;i<s.length();i++){
                if(wset.find(s.substr(0,i))==wset.end()){
                    work=false;
                    break;
                }
            }
            if(work) return s;
        }
        return "";
    }
};
