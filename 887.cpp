class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        vector<int> row(grid.size(), 0);
        vector<int> col(grid.size(), 0);
        int topdown = 0;
        for(int i = 0; i < grid.size(); i++){
            // row
            for(int j = 0; j < grid.size(); j++){
                if(grid[i][j] != 0) topdown++;
                if(grid[i][j] > row[i]) row[i] = grid[i][j];
            }

            // col
            for(int j = 0; j < grid.size(); j++){
                if(grid[j][i] > col[i]) col[i] = grid[j][i];
            }

            ans += row[i] + col[i];
        }

        ans += topdown;
        return ans;
    }
};
