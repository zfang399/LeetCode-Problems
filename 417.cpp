class Solution {
public:
    bool visited[150][150]={false};
    bool at[150][150]={false};
    bool pa[150][150]={false};
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int>> ans;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                trygo(i,j,matrix);
                if(at[i][j]&&pa[i][j]) ans.push_back(make_pair(i,j));
            }
        }
        return ans;
    }
    void trygo(int x, int y, vector<vector<int>>& matrix){
        if(visited[x][y]) return;
        visited[x][y]=true;
        if(x==0 || y==0) at[x][y]=true;
        if(x==matrix.size()-1 || y==matrix[0].size()-1) pa[x][y]=true;
        if(x>0 && matrix[x][y]>=matrix[x-1][y]){
            trygo(x-1,y,matrix);
            at[x][y]=at[x][y]||at[x-1][y];
            pa[x][y]=pa[x][y]||pa[x-1][y];
            if(at[x][y]&&pa[x][y]){
                visited[x][y]=false;
                return;
            }
        }
        if(x<matrix.size()-1 && matrix[x][y]>=matrix[x+1][y]){
            trygo(x+1,y,matrix);
            at[x][y]=at[x][y]||at[x+1][y];
            pa[x][y]=pa[x][y]||pa[x+1][y];
            if(at[x][y]&&pa[x][y]){
                visited[x][y]=false;
                return;
            }
        }
        if(y>0 && matrix[x][y]>=matrix[x][y-1]){
            trygo(x,y-1,matrix);
            at[x][y]=at[x][y]||at[x][y-1];
            pa[x][y]=pa[x][y]||pa[x][y-1];
            if(at[x][y]&&pa[x][y]){
                visited[x][y]=false;
                return;
            }
        }
        if(y<matrix[0].size()-1 && matrix[x][y]>=matrix[x][y+1]){
            trygo(x,y+1,matrix);
            at[x][y]=at[x][y]||at[x][y+1];
            pa[x][y]=pa[x][y]||pa[x][y+1];
            if(at[x][y]&&pa[x][y]){
                visited[x][y]=false;
                return;
            }
        }
        visited[x][y]=false;
        return;
    }
};
