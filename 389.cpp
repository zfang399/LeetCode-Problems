class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans;
        map<char,int> count;
        for(int i=0;i<t.length();i++){
            count[t[i]]++;
        }
        for(int i=0;i<s.length();i++){
            count[s[i]]--;
        }
        for(int i=0;i<t.length();i++){
            if(count[t[i]]!=0){
                ans=t[i];
            }
        }
        return ans;
    }
};
