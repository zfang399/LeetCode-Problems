class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=s.length();
        vector<int> c(26);
        int f=0,maxc=0,ans=0;
        for (int r=0;r<l;r++) {
            c[s[r]-'A']++;
            maxc=max(maxc,c[s[r]-'A']);
            while (r-f+1-maxc>k) {
                c[s[f]-'A']--;
                f++;
            }
            ans=max(ans,r-f+1);
        }
        return ans;
    }
};
