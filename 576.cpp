class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        unsigned int g[2][50][50] = {};
        while (N-->0){
            for (int k = 0; k < m; ++k){
                for (int l = 0, nc = (N + 1) % 2, np = N % 2; l < n; ++l){
                    g[nc][k][l] = ((k == 0 ? 1 : g[np][k - 1][l]) + (k == m - 1 ? 1 : g[np][k + 1][l])
                        + (l == 0 ? 1 : g[np][k][l - 1]) + (l == n - 1 ? 1 : g[np][k][l + 1])) % 1000000007;
                }
            }
        }
        return g[1][i][j];
    }
};
