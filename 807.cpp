class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int len = grid.size();
        vector<int> rowmax(len,0), colmax(len,0);
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                rowmax[i] = max(rowmax[i], grid[i][j]);
                colmax[j] = max(colmax[j], grid[i][j]);
            }
        }

        int ans = 0;

        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                ans += min(rowmax[i],colmax[j]) - grid[i][j];
            }
        }

        return ans;
    }
};
