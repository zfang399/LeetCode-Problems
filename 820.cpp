class Solution {
public:
    // If string A's postfix is string B, we do not need to get another # for B
    // e.g. "time" contains "me", so we do not need a separate # for "me"
    // So we reverse all the words and compare the postfixes.

    // Also, if string words[i+1] cannot contain words[i], no string after words[i+1] will suffice
    // e.g. "em", "en",
    // "en" cannot contain "em", and for sure no words after "en" begins with "em"
    // Therefore, we only need to compare       words[i]     and      words[i+1].substr(0, words[i].length())
    int minimumLengthEncoding(vector<string>& words) {
        // Reverse all the words. e.g. "me" --> "em", "time" --> "emit"
        // This way, we can compare the postfix easily
        for(int i = 0; i < words.size(); i++){
            reverse(words[i].begin(), words[i].end());
        }
        // Sort vector lexigraphically
        sort(words.begin(), words.end());
        // Compare strings to see which one we do not need
        vector<bool> count(words.size(), true);
        for(int i = 0; i < words.size() - 1; i++){
            if(words[i].compare(words[i + 1].substr(0,words[i].length())) == 0){
                count[i] = false;
            }
        }
        // Add the lengths and return the answer
        int ans = 0;
        for(int i = 0; i < words.size(); i++){
            if(count[i]) ans += words[i].length() + 1;
        }
        return ans;
    }
};
