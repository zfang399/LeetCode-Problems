class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> count;
        for(int i = 0; i < answers.size(); i++) count[answers[i]]++;
        int ans = 0;
        for(auto e:count){
            ans += (e.second + e.first) / (e.first + 1) * (e.first + 1);
        }
        return ans;
    }
};