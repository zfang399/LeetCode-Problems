class NumMatrix {
public:
    vector<vector<int>> pre;
    NumMatrix(vector<vector<int>> matrix) {
        for(int i=0;i<matrix.size();i++){
            vector<int> x;
            pre.push_back(x);
            pre[i].push_back(matrix[i][0]);
            for(int j=1;j<matrix[0].size();j++){
                pre[i].push_back(matrix[i][j]+pre[i][j-1]);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret=0;
        for(int i=row1;i<=row2;i++){
            ret+=pre[i][col2]-pre[i][col1-1];
        }
        return ret;
    }

};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
