class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<string,bool> codes;
        int ans = 0;
        for (int i = 0; i < words.size(); i++){
            string current;
            for(int j = 0; j < words[i].size(); j++){
                current += morse[words[i][j] - 'a'];
            }
            if(!codes[current]){
                codes[current] = true;
                ans++;
            }
        }
        return ans;
    }
};
