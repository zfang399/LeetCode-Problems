class Solution {
public:
    string toGoatLatin(string S) {
        unordered_map<char,bool> vowel;
        vowel['a'] = true;
        vowel['e'] = true;
        vowel['i'] = true;
        vowel['o'] = true;
        vowel['u'] = true;
        vowel['A'] = true;
        vowel['E'] = true;
        vowel['I'] = true;
        vowel['O'] = true;
        vowel['U'] = true;

        string ans = "";
        string cur = "";
        int count = 0;

        for(int i = 0; i < S.size(); i++){
            if(S[i] == ' '){
                if(cur.length() == 0){
                    continue;
                }
                if (count != 0) ans = ans + " ";
                count++;
                if(vowel[cur[0]]) {
                    cur = cur + "ma";
                    for(int j = 0; j < count; j++){
                        cur = cur + "a";
                    }
                }else{
                    cur = cur.substr(1) + cur.substr(0,1);
                    cur = cur + "ma";
                    for(int j = 0; j < count; j++){
                        cur = cur + "a";
                    }
                }
                ans = ans + cur;
                cur = "";
            }else{
                cur = cur + S[i];
            }
        }

        if(cur.length() != 0){
            if (count != 0) ans = ans + " ";
            count++;
            if(vowel[cur[0]]) {
                cur = cur + "ma";
                for(int j = 0; j < count; j++){
                    cur = cur + "a";
                }
            }else{
                cur = cur.substr(1) + cur.substr(0,1);
                cur = cur + "ma";
                for(int j = 0; j < count; j++){
                    cur = cur + "a";
                }
            }
            ans = ans + cur;
        }

        return ans;
    }
};
