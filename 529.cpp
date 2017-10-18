class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r=click[0],c=click[1];
        if(board[r][c]=='M'){
            board[r][c]='X';
            return board;
        }
        queue<pair<int,int>> q;
        q.push(make_pair(r,c));
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),false));
        while(q.size()){
            int row=q.front().first;
            int col=q.front().second;
            vis[row][col]=true;
            q.pop();
            int mine=mines(board,row,col);
            if(mine==0){
                board[row][col]='B';
                vector<vector<int>> dir={{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
                for(int i=0;i<dir.size();i++){
                    r=row+dir[i][0];
                    c=col+dir[i][1];
                    if(r<0||r>=board.size()||c<0||c>=board[0].size()||vis[r][c]||board[r][c]!='E'){
                        continue;
                    }
                    q.push(make_pair(r,c));
                    vis[r][c]=true;
                }
            }else{
                board[row][col]='0'+mine;
            }
        }
        return board;
    }
    int mines(vector<vector<char>>& board,int r,int c){
        vector<vector<int>> dir={{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
        int ret=0;
        for(int i=0;i<dir.size();i++){
            int row=r+dir[i][0];
            int col=c+dir[i][1];
            if(row<0 || row>=board.size() || col<0 || col>=board[0].size()){
                continue;
            }
            if(board[row][col]=='M') ret++;
        }
        return ret;
    }
};
