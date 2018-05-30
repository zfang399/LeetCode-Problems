class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int,int> counts;
        int islands = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    islands ++;
                    dfs(grid, counts, i, j, islands + 1);
                }
            }
        }
        int ans = 0;
        bool got = false;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    got = true;
                    int tot = 1;
                    vector<bool> used(islands + 5, false);
                    if(i > 0){
                        used[grid[i - 1][j]] = true;
                        tot += counts[grid[i - 1][j]];
                    }
                    if(i < grid.size() - 1 && !used[grid[i + 1][j]]){
                        used[grid[i + 1][j]] = true;
                        tot += counts[grid[i + 1][j]];
                    }
                    if(j > 0 && !used[grid[i][j - 1]]){
                        used[grid[i][j - 1]] = true;
                        tot += counts[grid[i][j - 1]];
                    }
                    if(j < grid[0].size() - 1 && !used[grid[i][j + 1]]){
                        used[grid[i][j + 1]] = true;
                        tot += counts[grid[i][j + 1]];
                    }
                    ans = max(ans, tot);
                }
            }
        }
        if(!got) return grid.size() * grid[0].size();
        return ans;
    }
    void dfs(vector<vector<int>>& grid, unordered_map<int,int>& counts, int x, int y, int val){
        grid[x][y] = val;
        counts[val] += 1;
        if(x > 0){
            if(grid[x - 1][y] == 1){
                dfs(grid, counts, x - 1, y, val);
            }
        }
        if(x < grid.size() - 1){
            if(grid[x + 1][y] == 1){
                dfs(grid, counts, x + 1, y, val);
            }
        }
        if(y > 0){
            if(grid[x][y - 1] == 1){
                dfs(grid, counts, x, y - 1, val);
            }
        }
        if(y < grid[0].size() - 1){
            if(grid[x][y + 1] == 1){
                dfs(grid, counts, x, y + 1, val);
            }
        }
        return;
    }
};
