class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;
        vector<char> v[8];
        v[0].push_back('a'),v[0].push_back('b'),v[0].push_back('c');
        v[1].push_back('d'),v[1].push_back('e'),v[1].push_back('f');
        v[2].push_back('g'),v[2].push_back('h'),v[2].push_back('i');
        v[3].push_back('j'),v[3].push_back('k'),v[3].push_back('l');
        v[4].push_back('m'),v[4].push_back('n'),v[4].push_back('o');
        v[5].push_back('p'),v[5].push_back('q'),v[5].push_back('r'),v[5].push_back('s');
        v[6].push_back('t'),v[6].push_back('u'),v[6].push_back('v');
        v[7].push_back('w'),v[7].push_back('x'),v[7].push_back('y'),v[7].push_back('z');
        for(int i=0;i<v[digits[0]-'2'].size();i++){
            string t;
            t+=v[digits[0]-'2'][i];
            ans.push_back(t);
        }
        int k=1;
        while(k<digits.size()){
            int n=ans.size();
            int x=digits[k]-'2';
            for(int i=0;i<n;i++){
                for(int j=0;j<v[x].size();j++){
                    ans.push_back(ans[i]+v[x][j]);
                }
            }
            ans.erase(ans.begin(),ans.begin()+n);
            k++;
        }
        return ans;
    }
};
