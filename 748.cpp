class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char,int> plate;
        for(int i = 0; i < licensePlate.size(); i++){
            if(isalpha(licensePlate[i])) plate[tolower(licensePlate[i])]++;
        }
        int stst = INT_MAX;
        string ans = "";
        for(int i = 0; i < words.size();i++){
            if(words[i].length() >= stst){
                continue;
            }
            unordered_map<char,int> tmp = plate;
            bool work = true;
            for(int j = 0; j < words[i].length(); j++){
                tmp[words[i][j]]--;
            }
            for(auto e:tmp){
                if(e.second > 0){
                    work = false;
                    break;
                }
            }
            if(work){
                stst = words[i].length();
                ans = words[i];
            }
        }
        return ans;
    }
};
