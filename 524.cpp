class Solution {
public:
    static bool cmp(string a, string b){
        if(a.length()!=b.length()) return a.length()>b.length();
        if(a.compare(b)<0) return true;
        return false;
    }
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(),d.end(),cmp);
        map<char,vector<int>> ind;
        for(int i=0;i<s.length();i++){
            ind[s[i]].push_back(i);
        }
        for(int i=0;i<d.size();i++){
            if(ind[d[i][0]].size()==0) continue;
            int prev=ind[d[i][0]].front();
            bool work=true;
            for(int j=1;j<d[i].length();j++){
                if(ind[d[i][j]].size()==0){
                    work=false;
                    break;
                }
                bool found=false;
                for(int k=0;k<ind[d[i][j]].size();k++){
                    if(ind[d[i][j]][k]>prev){
                        prev=ind[d[i][j]][k];
                        found=true;
                        break;
                    }
                }
                if(!found){
                    work=false;
                    break;
                }
            }
            if(work) return d[i];
        }
        return "";
    }
};
