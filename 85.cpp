class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        if(matrix[0].size()==0) return 0;
        int ans=0;
        int m=matrix.size(),n=matrix[0].size();
        vector<int> left(n,0),right(n,n),height(n,0);
        for(int i=0;i<m;i++){
            int cl=0,cr=n;
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') height[j]++;
                else height[j]=0;
            }
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') left[j]=max(left[j],cl);
                else{
                    left[j]=0;
                    cl=j+1;
                }
            }
            for(int j=n-1;j>=0;j--){
                if(matrix[i][j]=='1') right[j]=min(right[j],cr);
                else{
                    right[j]=n;
                    cr=j;
                }
            }
            for(int j=0;j<n;j++){
                ans=max(ans,((right[j]-left[j])*height[j]));
            }
        }
        return ans;
    }
};
