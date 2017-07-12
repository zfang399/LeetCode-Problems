class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        if(matrix[0].size()==0) return false;
        int i=0;
        while(i<matrix.size() && matrix[i][0]<=target){
            i++;
        }
        if(i>0) i--;
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) return false;
        }
        return false;
    }
};
