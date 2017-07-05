class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        int count[26]={0};
        for(int i=0;i<s1.length();i++) count[s1[i]-'a']++;
        int f=0,r=s1.length()-1;
        for(int i=0;i<=r;i++) count[s2[i]-'a']--;
        while(r<s2.length()){
            bool found=true;
            for(int i=0;i<26;i++){
                if(count[i]!=0) found=false;
            }
            if(found) return true;
            if(r==s2.length()-1) return false;
            count[s2[f]-'a']++;
            r++;
            count[s2[r]-'a']--;
            f++;
        }
        return false;
    }
};
