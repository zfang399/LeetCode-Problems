class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m=M.size();
        if(m==0){
            vector<vector<int>> ans;
            return ans;
        }
        int n=M[0].size();
        if(n==0){
            vector<vector<int>> ans;
            return ans;
        }
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<M.size();i++){
            for(int j=0;j<M[0].size();j++){
                int count=1,sum=M[i][j];
                if(i-1>=0){
                    count++;
                    sum+=M[i-1][j];
                    if(j-1>=0){
                        count++;
                        sum+=M[i-1][j-1];
                    }
                    if(j+1<M[0].size()){
                        count++;
                        sum+=M[i-1][j+1];
                    }
                }
                if(i+1<M.size()){
                    count++;
                    sum+=M[i+1][j];
                    if(j-1>=0){
                        count++;
                        sum+=M[i+1][j-1];
                    }
                    if(j+1<M[0].size()){
                        count++;
                        sum+=M[i+1][j+1];
                    }
                }
                if(j-1>=0){
                    count++;
                    sum+=M[i][j-1];
                }
                if(j+1<M[0].size()){
                    count++;
                    sum+=M[i][j+1];
                }
                ans[i][j]=sum/count;
            }
        }
        return ans;
    }
};
