class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.length()<p.length()) return ans;
        vector<int> pc(26),sc(26);
        for(int i=0; i<p.length(); i++) pc[p[i]-'a']++;
        for(int i=0; i<p.length(); i++) sc[s[i]-'a']++;
        if(pc == sc) ans.push_back(0);
        int pl = p.length();
        for(int i = pl; i < s.length(); i++){
            sc[s[i]-'a']++;
            sc[s[i-pl]-'a']--;
            if(pc == sc) ans.push_back(i-pl+1);
        }
        return ans;
    }
};
