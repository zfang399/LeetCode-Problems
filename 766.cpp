class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int diags = m + n - 1;
        for(int i = 1; i <=diags; i++){
            int r = max(m - i, 0);
            int c = max(i - m, 0);
            int num = matrix[r][c];
            while(r < m && c < n){
                if(matrix[r][c] != num) return false;
                r++;
                c++;
            }
        }
        return true;
    }
};
