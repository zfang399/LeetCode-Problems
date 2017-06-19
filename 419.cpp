class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='X' && (i-1>=0?(board[i-1][j]=='.'):1) && (j-1>=0?(board[i][j-1]=='.'):1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};
