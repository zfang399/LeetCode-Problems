class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> impos;
        for(int i = 0; i < fronts.size(); i++){
            if(fronts[i] == backs[i]) impos.insert(fronts[i]);
        }
        int ans = 2005;
        for(int i = 0; i < fronts.size(); i++){
            if(impos.count(fronts[i]) == 0) ans = fronts[i] < ans ? fronts[i] : ans;
            if(impos.count(backs[i]) == 0) ans = backs[i] < ans ? backs[i] : ans;
        }
        if(ans == 2005) return 0;
        return ans;
    }
};
