class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(!matrix.size()) return ans;
        vector<vector<int>> mov(4,vector<int>(2));
        vector<vector<bool>> v(matrix.size(),vector<bool>(matrix[0].size()));
        mov[0][0]=0,mov[0][1]=1;
        mov[1][0]=1,mov[1][1]=0;
        mov[2][0]=0,mov[2][1]=-1;
        mov[3][0]=-1,mov[3][1]=0;
        int dir=0,x=0,y=0;
        ans.push_back(matrix[x][y]);
        v[x][y]=true;
        dfs(matrix,v,mov,ans,dir,x,y);
        return ans;
    }
    void dfs(vector<vector<int>>& matrix,vector<vector<bool>>& v, vector<vector<int>>& mov, vector<int>& ans, int dir, int x, int y){
        dir%=4;
        if(ans.size()==matrix.size()*matrix[0].size()) return;
        if(x+mov[dir][0]>=0 && x+mov[dir][0]<matrix.size() && y+mov[dir][1]>=0 && y+mov[dir][1]<matrix[0].size()){
            if(!v[x+mov[dir][0]][y+mov[dir][1]]){
                v[x+mov[dir][0]][y+mov[dir][1]]=true;
                ans.push_back(matrix[x+mov[dir][0]][y+mov[dir][1]]);
                dfs(matrix,v,mov,ans,dir,x+mov[dir][0],y+mov[dir][1]);
            }else{
                dir++;
                dfs(matrix,v,mov,ans,dir,x,y);
            }
        }else{
            dir++;
            dfs(matrix,v,mov,ans,dir,x,y);
        }
    }
};
