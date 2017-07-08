class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int> (n,0));
        int mov[5][3];
        mov[1][1]=0,mov[1][2]=1;
        mov[2][1]=1,mov[2][2]=0;
        mov[3][1]=0,mov[3][2]=-1;
        mov[4][1]=-1,mov[4][2]=0;
        int count=0,x=0,y=-1,nm=1;
        while(count<n*n){
            if(x+mov[nm][1]>=0 && x+mov[nm][1]<n && y+mov[nm][2]>=0 && y+mov[nm][2]<n && ans[x+mov[nm][1]][y+mov[nm][2]]==0){
                count++;
                ans[x+mov[nm][1]][y+mov[nm][2]]=count;
                x+=mov[nm][1];
                y+=mov[nm][2];
            }else{
                nm++;
                if(nm>4) nm=1;
            }
        }
        return ans;
    }
};
