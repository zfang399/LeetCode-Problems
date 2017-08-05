class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9,vector<bool>(9));
        vector<vector<bool>> col(9,vector<bool>(9));
        vector<vector<vector<bool>>> box(3,vector<vector<bool>> (3,vector<bool>(9)));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.') continue;
                int x=board[i][j]-'1';
                row[i][x]=true;
                col[j][x]=true;
                box[i/3][j/3][x]=true;
            }
        }
        dfs(board,row,col,box,0,0);
    }
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>&row,vector<vector<bool>>&col,vector<vector<vector<bool>>>&box,int x,int y){
        while(board[x][y]!='.'){
            y++;
            if(y==9){
                x++;
                y=0;
            }
            if(x==9){
                return true;
            }
        }
        for(int i=0;i<=8;i++){
            if(!row[x][i] && !col[y][i] && !box[x/3][y/3][i]){
                row[x][i]=true;
                col[y][i]=true;
                box[x/3][y/3][i]=true;
                char c=i+'1';
                board[x][y]=c;
                if(dfs(board,row,col,box,x,y)){
                    return true;
                }
                row[x][i]=false;
                col[y][i]=false;
                box[x/3][y/3][i]=false;
            }
        }
        board[x][y]='.';
        return false;
    }
};
