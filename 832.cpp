class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int r = A.size();
        int c = A[0].size();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < (c + 1) / 2; j++){
                if(A[i][j] == A[i][c - j - 1]){
                    A[i][j] = 1 - A[i][j];
                    A[i][c - j - 1] = A[i][j];
                }else{
                    A[i][j] = 1 - A[i][c - j - 1];
                    A[i][c - j - 1] = 1 - A[i][j];
                }
            }
        }
        return A;
    }
};
