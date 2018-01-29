class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<string,bool> visited;
        string init = "";
        int zpos = 0;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                init += '0' + board[i][j];
                if(board[i][j] == 0) zpos = i*3 + j;
            }
        }
        return bfs(visited, init, zpos);
    }
    int bfs(unordered_map<string,bool> &visited, string str, int zpos){
        queue<string> sq;
        queue<int> iq;
        queue<int> count;
        sq.push(str);
        iq.push(zpos);
        count.push(0);
        visited[str] = true;
        while(sq.size()){
            str = sq.front();
            int t = iq.front();
            int c = count.front();
            visited[str] = true;
            sq.pop();
            iq.pop();
            count.pop();
            if(str == "123450"){
                return c;
            }
            int x = t/3;
            int y = t%3;

            if(y - 1 >= 0){
                string cpstr = str;
                cpstr[t] = cpstr[t - 1];
                cpstr[t - 1] = '0';
                if(!visited[cpstr]){
                    sq.push(cpstr);
                    iq.push(t - 1);
                    count.push(c + 1);
                }
            }
            if(y + 1 < 3){
                string cpstr = str;
                cpstr[t] = cpstr[t + 1];
                cpstr[t + 1] = '0';
                if(!visited[cpstr]){
                    sq.push(cpstr);
                    iq.push(t + 1);
                    count.push(c + 1);
                }
            }

            if(x == 0){
                string cpstr = str;
                cpstr[t] = cpstr[t + 3];
                cpstr[t + 3] = '0';
                if(!visited[cpstr]){
                    sq.push(cpstr);
                    iq.push(t + 3);
                    count.push(c + 1);
                }
            }else{
                string cpstr = str;
                cpstr[t] = cpstr[t - 3];
                cpstr[t - 3] = '0';
                if(!visited[cpstr]){
                    sq.push(cpstr);
                    iq.push(t - 3);
                    count.push(c + 1);
                }
            }
        }
        return -1;
    }
};
