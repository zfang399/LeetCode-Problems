class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int r = grid.size();
        int c = grid[0].size();
        if(r < 3 || c < 3) return ans;
        for(int i = 0; i < r - 2; i ++){
            for(int j = 0; j < c - 2; j ++){
                unordered_map<int,bool> uni;
                bool unique = true;
                int r1 = 0, r2 = 0, r3 = 0;
                int c1 = 0, c2 = 0, c3 = 0;
                int d1 = 0, d2 = 0;
                for(int rn = 0; rn < 3; rn++){
                    for(int cn = 0; cn < 3; cn++){
                        r1 += rn == 0 ? grid[i + rn][j + cn] : 0;
                        r2 += rn == 1 ? grid[i + rn][j + cn] : 0;
                        r3 += rn == 2 ? grid[i + rn][j + cn] : 0;
                        c1 += cn == 0 ? grid[i + rn][j + cn] : 0;
                        c2 += cn == 1 ? grid[i + rn][j + cn] : 0;
                        c3 += cn == 2 ? grid[i + rn][j + cn] : 0;
                        d1 += rn == cn ? grid[i + rn][j + cn] : 0;
                        d2 += (rn + cn) == 2 ? grid[i + rn][j + cn] : 0;
                        if(uni[grid[i + rn][j + cn]] || grid[i + rn][j + cn] < 1 || grid[i + rn][j + cn] > 9){
                            unique = false;
                            break;
                        }
                        uni[grid[i + rn][j + cn]] = true;
                    }
                    if(!unique) break;
                }
                if(!unique) continue;
                if(r1 != r2) continue;
                if(r2 != r3) continue;
                if(r3 != c1) continue;
                if(c1 != c2) continue;
                if(c1 != c3) continue;
                if(c3 != d1) continue;
                if(d1 != d2) continue;
                ans += 1;
            }
        }
        return ans;
    }
};
