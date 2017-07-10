class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            bool e[9]={false};
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(e[board[i][j]-'1']) return false;
                e[board[i][j]-'1']=true;
            }
            memset(e,false,sizeof(e));
            for(int j=0;j<9;j++){
                if(board[j][i]=='.') continue;
                if(e[board[j][i]-'1']) return false;
                e[board[j][i]-'1']=true;
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                bool e[9]={false};
                for(int ii=i*3;ii<i*3+3;ii++){
                    for(int jj=j*3;jj<j*3+3;jj++){
                        if(board[ii][jj]=='.') continue;
                        if(e[board[ii][jj]-'1']) return false;
                        e[board[ii][jj]-'1']=true;
                    }
                }
            }
        }
        return true;
    }
};
