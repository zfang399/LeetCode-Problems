class Solution {
public:
    string reorganizeString(string S) {
        string ans = "";

        // Find the most frequent character
        unordered_map<char,int> count;
        int max_count = 0;
        char max_char = S[0];
        for(int i = 0; i < S.length(); i++){
            count[S[i]]++;
            if(count[S[i]] > max_count){
                max_count = count[S[i]];
                max_char = S[i];
            }
        }

        // Initialize #max_count substrings
        vector<string> subs;
        string tmp = "";
        tmp += max_char;
        for(int i = 0; i < max_count; i++){
            subs.push_back(tmp);
        }

        // Add other characters to the end
        // No two adjacent characters are the same b/c the number of subtrings is already the same as max_count
        int idx = 0;
        int other_tot = 0;
        for(auto e:count){
            if(e.first == max_char) continue;
            other_tot += e.second;
            for(int i = 0; i < e.second; i++){
                subs[idx] += e.first;
                idx = idx == max_count - 1 ? 0 : idx + 1;
            }
        }

        // If the other characters still leave two original strings unmodified, the task is not possible
        if(other_tot < max_count - 1) return "";

        // return
        for(int i = 0; i < max_count; i++){
            ans += subs[i];
        }

        return ans;
    }
};
