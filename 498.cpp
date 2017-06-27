class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size()==0) return ans;
        if(matrix[0].size()==0) return ans;
        if(matrix.size()==1) return matrix[0];
        if(matrix[0].size()==1){
            for(int i=0;i<matrix.size();i++) ans.push_back(matrix[i][0]);
            return ans;
        }
        int m=matrix.size()-1,n=matrix[0].size()-1;
        for(int i=0;i<=m+n;i++){
            if(i%2==0) for(int j=min(i,m);j>=max(0,i-n);j--) ans.push_back(matrix[j][i-j]);
            else for(int j=max(0,i-n);j<=min(i,m);j++) ans.push_back(matrix[j][i-j]);
        }
        return ans;
    }
};
