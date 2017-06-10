class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> rannum;
        map<char,int> maganum;
        for(int i=0;i<magazine.size();i++) maganum[magazine[i]]++;
        for(int i=0;i<ransomNote.size();i++){
            rannum[ransomNote[i]]++;
            if(rannum[ransomNote[i]]>maganum[ransomNote[i]]) return false;
        }
        return true;
    }
};
