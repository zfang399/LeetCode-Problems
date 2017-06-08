class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap=0;
        for(int i=0;i<word.length();i++){
            if(word[i]-'A'>=0 && word[i]-'A'<=25) cap++;
        }
        return (cap==0 || cap==word.length() || (cap==1 && word[0]-'A'>=0 && word[0]-'A'<=25));
    }
};
