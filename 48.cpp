class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size()/2;i++){
            int r=matrix.size()-1-i;
            for(int j=1;j<matrix.size()-2*i;j++){
                int tmp=matrix[i][i+j];
                matrix[i][i+j]=matrix[r-j][i];
                matrix[r-j][i]=matrix[r][r-j];
                matrix[r][r-j]=matrix[i+j][r];
                matrix[i+j][r]=tmp;
            }
        }
    }
};
