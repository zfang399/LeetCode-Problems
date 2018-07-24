class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<pair<int,int>, bool> obs;
        for (int i = 0; i < obstacles.size(); i++){
            if(obstacles[i][0] == 0 && obstacles[i][1] == 0) continue;
            obs[make_pair(obstacles[i][0], obstacles[i][1])] = true;
        }
        int cur_x = 0;
        int cur_y = 0;
        int dir_x = 0;
        int dir_y = 1;
        int maxd  = 0;
        for (int i = 0; i < commands.size(); i++){
            if(commands[i] == -1){
                if(dir_y == 1){
                    // north to east
                    dir_y = 0;
                    dir_x = 1;
                }else if(dir_x == 1){
                    // east to south
                    dir_y = -1;
                    dir_x = 0;
                }else if(dir_y == -1){
                    // south to west
                    dir_y = 0;
                    dir_x = -1;
                }else{
                    // west to north
                    dir_y = 1;
                    dir_x = 0;
                }
            }else if(commands[i] == -2){
                if(dir_y == 1){
                    // north to west
                    dir_y = 0;
                    dir_x = -1;
                }else if(dir_x == -1){
                    // west to south
                    dir_y = -1;
                    dir_x = 0;
                }else if(dir_y == -1){
                    // south to east
                    dir_y = 0;
                    dir_x = 1;
                }else{
                    // east to north
                    dir_y = 1;
                    dir_x = 0;
                }
            }else{
                int steps = commands[i];
                // Walk and check
                while(!obs[make_pair(cur_x, cur_y)] && steps > 0){
                    //cout << cur_x << " " << cur_y << endl;
                    if(cur_x * cur_x + cur_y * cur_y > maxd) maxd = cur_x * cur_x + cur_y * cur_y;
                    steps--;
                    cur_x += dir_x;
                    cur_y += dir_y;
                }

                // Go back if obstacle
                if(obs[make_pair(cur_x, cur_y)]){
                    cur_x -= dir_x;
                    cur_y -= dir_y;
                }else{
                    if(cur_x * cur_x + cur_y * cur_y > maxd) maxd = cur_x * cur_x + cur_y * cur_y;
                }
            }
        }
        return maxd;
    }
};
