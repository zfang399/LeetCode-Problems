class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        int ans = 0;
        set<pair<string, string>> group;
        for(int i = 0; i < A.size(); i++){
            map<char, int> count;
            string odd = "";
            string even = "";
            // Get odd string
            for(int j = 0; j < A[i].length(); j += 2) count[A[i][j]]++;
            for(auto &e:count){
                while(e.second > 0){
                    odd += e.first;
                    e.second--;
                }
            }

            // Get even string
            for(int j = 1; j < A[i].length(); j += 2) count[A[i][j]]++;
            for(auto &e:count){
                while(e.second > 0){
                    even += e.first;
                    e.second--;
                }
            }

            // Compare with current groups
            if(group.find(make_pair(odd, even)) == group.end()){
                group.insert(make_pair(odd, even));
                ans++;
            }
        }

        return ans;
    }
};
