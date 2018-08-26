class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int N = grid.size();
        int ans = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == 0) continue;
                ans += grid[i][j] * 4 + 2;
                if(i > 0) ans -= 2 * min(grid[i][j], grid[i - 1][j]);
                if(j > 0) ans -= 2 * min(grid[i][j], grid[i][j - 1]);
            }
        }
        return ans;
    }
};
