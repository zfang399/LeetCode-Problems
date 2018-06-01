class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int ans = 0;
        vector<vector<int>> left(N + 2, vector<int>(N + 2, 0));
        vector<vector<int>> right(N + 2, vector<int>(N + 2, 0));
        vector<vector<int>> up(N + 2, vector<int>(N + 2, 0));
        vector<vector<int>> down(N + 2, vector<int>(N + 2, 0));
        vector<vector<bool>> is_mine(N + 2, vector<bool>(N + 2, false));
        for(int i = 0; i < mines.size(); i++) is_mine[mines[i][0]][mines[i][1]] = true;
        // compute left and up
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(is_mine[i - 1][j - 1]) continue;
                left[i][j] = left[i][j - 1] + 1;
                up[i][j] = up[i - 1][j] + 1;
            }
        }
        // compute right and down
        for(int i = N; i > 0; i--){
            for(int j = N; j > 0; j--){
                // if the answer is already better than current
                if(j < ans) continue;
                if(i < ans) break;
                if(is_mine[i - 1][j - 1]) continue;
                right[i][j] = right[i][j + 1] + 1;
                down[i][j] = down[i + 1][j] + 1;
                ans = max(ans, min(left[i][j], min(right[i][j], min(up[i][j], down[i][j]))));
            }
        }
        return ans;
    }
};
