class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(!board.size()) return false;
        if(!board[0].size()) return false;
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size()));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    visited[i][j]=true;
                    if(dfs(board,word.substr(1),i,j,visited)) return true;
                    visited[i][j]=false;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word,int x,int y,vector<vector<bool>>& visited){
        if(word=="") return true;
        bool ret=false;
        if(x-1>=0 && !visited[x-1][y]){
            if(board[x-1][y]==word[0]){
                visited[x-1][y]=true;
                ret=ret||dfs(board,word.substr(1),x-1,y,visited);
                visited[x-1][y]=false;
            }
        }
        if(ret) return ret;
        if(x+1<board.size() && !visited[x+1][y]){
            if(board[x+1][y]==word[0]){
                visited[x+1][y]=true;
                ret=ret||dfs(board,word.substr(1),x+1,y,visited);
                visited[x+1][y]=false;
            }
        }
        if(ret) return ret;
        if(y-1>=0 && !visited[x][y-1]){
            if(board[x][y-1]==word[0]){
                visited[x][y-1]=true;
                ret=ret||dfs(board,word.substr(1),x,y-1,visited);
                visited[x][y-1]=false;
            }
        }
        if(ret) return ret;
        if(y+1<board[0].size() && !visited[x][y+1]){
            if(board[x][y+1]==word[0]){
                visited[x][y+1]=true;
                ret=ret||dfs(board,word.substr(1),x,y+1,visited);
                visited[x][y+1]=false;
            }
        }
        return ret;
    }
};
