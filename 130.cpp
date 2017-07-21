class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(!board.size()) return;
        if(!board[0].size()) return;
        int m=board.size(),n=board[0].size();
        vector<vector<bool>> v(m,vector<bool>(n));
        queue<int> x,y;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                x.push(i);
                y.push(0);
            }
            if(board[i][n-1]=='O'){
                x.push(i);
                y.push(n-1);
            }
        }
        for(int i=1;i<n-1;i++){
            if(board[0][i]=='O'){
                x.push(0);
                y.push(i);
            }
            if(board[m-1][i]=='O'){
                x.push(m-1);
                y.push(i);
            }
        }
        while(x.size()){
            int xx=x.front();
            int yy=y.front();
            x.pop();
            y.pop();
            if(v[xx][yy]) continue;
            v[xx][yy]=true;
            if(xx-1>=0){
                if(board[xx-1][yy]=='O'){
                    x.push(xx-1);
                    y.push(yy);
                }
            }
            if(xx+1<m){
                if(board[xx+1][yy]=='O'){
                    x.push(xx+1);
                    y.push(yy);
                }
            }
            if(yy-1>=0){
                if(board[xx][yy-1]=='O'){
                    x.push(xx);
                    y.push(yy-1);
                }
            }
            if(yy+1<n){
                if(board[xx][yy+1]=='O'){
                    x.push(xx);
                    y.push(yy+1);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !v[i][j]) board[i][j]='X';
            }
        }
    }

};
