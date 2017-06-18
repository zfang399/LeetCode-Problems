class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int pl=arrays[0][0],pr=arrays[0].back(),ans=0;
        for(int i=1;i<arrays.size();i++){
            ans=max(ans,max(abs(pl-arrays[i].back()),abs(pr-arrays[i][0])));
            pl=min(arrays[i][0],pl);
            pr=max(arrays[i].back(),pr);
        }
        return ans;
    }
};
