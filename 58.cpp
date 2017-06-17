class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s=="") return 0;
        int lastind=s.length()-1;
        while(s[lastind]==' ' && lastind>=0){
            lastind--;
        }
        if(lastind==-1) return 0;
        int firstind=lastind;
        while(s[firstind]!=' ' && firstind>=0){
            firstind--;
        }
        return lastind-firstind;
    }
};
