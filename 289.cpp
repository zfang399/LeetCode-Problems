class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size()==0) return;
        if(board[0].size()==0) return;
        int m=board.size()-1,n=board[0].size()-1;
        if(m==0 && n==0){
            board[0][0]=0;
            return;
        }else if(m==0){
            if(board[0][0]) board[0][0]=3;
            if(board[0][n]) board[0][n]=3;
            for(int i=1;i<n;i++){
                if(board[0][i-1]%2+board[0][i+1]%2<2 && board[0][i]){
                    board[0][i]=3;
                }
            }
            for(int i=0;i<=n;i++){
                if(board[0][i]==3) board[0][i]=0;
            }
            return;
        }else if(n==0){
            if(board[0][0]) board[0][0]=3;
            if(board[m][0]) board[m][0]=3;
            for(int i=1;i<m;i++){
                if(board[i-1][0]%2+board[i+1][0]%2<2 && board[i][0]){
                    board[i][0]=3;
                }
            }
            for(int i=0;i<=m;i++){
                if(board[i][0]==3) board[i][0]=0;
            }
            return;
        }
        if(board[0][1]%2+board[1][0]%2+board[1][1]%2<2){
            if(board[0][0]==1) board[0][0]=3;
        }else if(board[0][1]%2+board[1][0]%2+board[1][1]%2==3){
            if(board[0][0]==0) board[0][0]=2;
        }
        if(board[1][n-1]%2+board[0][n-1]%2+board[1][n]%2<2){
            if(board[0][n]==1) board[0][n]=3;
        }else if(board[1][n-1]%2+board[0][n-1]%2+board[1][n]%2==3){
            if(board[0][n]==0) board[0][n]=2;
        }
        if(board[m][1]%2+board[m-1][0]%2+board[m-1][1]%2<2){
            if(board[m][0]==1) board[m][0]=3;
        }else if(board[m][1]%2+board[m-1][0]%2+board[m-1][1]%2==3){
            if(board[m][0]==0) board[m][0]=2;
        }
        if(board[m-1][n]%2+board[m][n-1]%2+board[m-1][n-1]%2<2){
            if(board[m][n]==1) board[m][n]=3;
        }else if(board[m-1][n]%2+board[m][n-1]%2+board[m-1][n-1]%2==3){
            if(board[m][n]==0) board[m][n]=2;
        }
        for(int i=1;i<m;i++){
            if(board[i-1][0]%2+board[i+1][0]%2+board[i][1]%2+board[i-1][1]%2+board[i+1][1]%2<2){
                if(board[i][0]==1) board[i][0]=3;
            }else if(board[i-1][0]%2+board[i+1][0]%2+board[i][1]%2+board[i-1][1]%2+board[i+1][1]%2==3){
                if(board[i][0]==0) board[i][0]=2;
            }else if(board[i-1][0]%2+board[i+1][0]%2+board[i][1]%2+board[i-1][1]%2+board[i+1][1]%2>3){
                if(board[i][0]==1) board[i][0]=3;
            }
            if(board[i-1][n]%2+board[i+1][n]%2+board[i][n-1]%2+board[i-1][n-1]%2+board[i+1][n-1]%2<2){
                if(board[i][n]==1) board[i][n]=3;
            }else if(board[i-1][n]%2+board[i+1][n]%2+board[i][n-1]%2+board[i-1][n-1]%2+board[i+1][n-1]%2==3){
                if(board[i][n]==0) board[i][n]=2;
            }else if(board[i-1][n]%2+board[i+1][n]%2+board[i][n-1]%2+board[i-1][n-1]%2+board[i+1][n-1]%2>3){
                if(board[i][n]==1) board[i][n]=3;
            }
        }
        for(int i=1;i<n;i++){
            if(board[0][i-1]%2+board[0][i+1]%2+board[1][i]%2+board[1][i-1]%2+board[1][i+1]%2<2){
                if(board[0][i]==1) board[0][i]=3;
            }else if(board[0][i-1]%2+board[0][i+1]%2+board[1][i]%2+board[1][i-1]%2+board[1][i+1]%2==3){
                if(board[0][i]==0) board[0][i]=2;
            }else if(board[0][i-1]%2+board[0][i+1]%2+board[1][i]%2+board[1][i-1]%2+board[1][i+1]%2>3){
                if(board[0][i]==1) board[0][i]=3;
            }
            if(board[m][i-1]%2+board[m][i+1]%2+board[m-1][i]%2+board[m-1][i-1]%2+board[m-1][i+1]%2<2){
                if(board[m][i]==1) board[m][i]=3;
            }else if(board[m][i-1]%2+board[m][i+1]%2+board[m-1][i]%2+board[m-1][i-1]%2+board[m-1][i+1]%2==3){
                if(board[m][i]==0) board[m][i]=2;
            }else if(board[m][i-1]%2+board[m][i+1]%2+board[m-1][i]%2+board[m-1][i-1]%2+board[m-1][i+1]%2>3){
                if(board[m][i]==1) board[m][i]=3;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(board[i-1][j]%2+board[i+1][j]%2+board[i][j-1]%2+board[i][j+1]%2+board[i-1][j-1]%2+board[i-1][j+1]%2+board[i+1][j-1]%2+board[i+1][j+1]%2<2){
                    if(board[i][j]==1) board[i][j]=3;
                }else if(board[i-1][j]%2+board[i+1][j]%2+board[i][j-1]%2+board[i][j+1]%2+board[i-1][j-1]%2+board[i-1][j+1]%2+board[i+1][j-1]%2+board[i+1][j+1]%2==3){
                    if(board[i][j]==0) board[i][j]=2;
                }else if(board[i-1][j]%2+board[i+1][j]%2+board[i][j-1]%2+board[i][j+1]%2+board[i-1][j-1]%2+board[i-1][j+1]%2+board[i+1][j-1]%2+board[i+1][j+1]%2>3){
                    if(board[i][j]==1) board[i][j]=3;
                }
            }
        }
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(board[i][j]==3) board[i][j]=0;
                if(board[i][j]==2) board[i][j]=1;
            }
        }
    }
};
