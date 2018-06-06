class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        map<string,vector<int>> vis;
        return helper(input, vis);
    }

    vector<int> helper(string s, map<string,vector<int>>& vis){
        // Memorization: if in memory, return.
        if(vis.count(s) > 0) return vis[s];
        // Initialization
        vector<int> ans;
        vector<int> prev;
        vector<int> after;
        bool no_op = true;
        // Recursive solution, divide and conquer
        // Try all combinations of substrings
        // For every substrings pair, try all combinations of numbers returned.
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '+'){
                no_op = false;
                prev = helper(s.substr(0,i), vis);
                after = helper(s.substr(i + 1), vis);
                for(int j = 0; j < prev.size(); j++){
                    for(int k = 0; k < after.size(); k++){
                        ans.push_back(prev[j] + after[k]);
                    }
                }
            }else if(s[i] == '-'){
                no_op = false;
                prev = helper(s.substr(0,i), vis);
                after = helper(s.substr(i + 1), vis);
                for(int j = 0; j < prev.size(); j++){
                    for(int k = 0; k < after.size(); k++){
                        ans.push_back(prev[j] - after[k]);
                    }
                }
            }else if(s[i] == '*'){
                no_op = false;
                prev = helper(s.substr(0,i), vis);
                after = helper(s.substr(i + 1), vis);
                for(int j = 0; j < prev.size(); j++){
                    for(int k = 0; k < after.size(); k++){
                        ans.push_back(prev[j] * after[k]);
                    }
                }
            }
        }
        // If this is just a number, push back the number
        if(no_op) ans.push_back(stoi(s));
        // Memorization: write the vector into memory
        vis[s] = ans;
        return ans;
    }
};
