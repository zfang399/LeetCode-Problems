class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size();
        vector<bool> vis(N, false);
        queue<int> tovis;

        // start from room #0, until we cannot visit any new room
        tovis.push(0);
        while(tovis.size()){
            int cur_room = tovis.front();
            tovis.pop();
            // mark as visited
            vis[cur_room] = true;
            // add the unvisited room to the queue
            for(int i = 0; i < rooms[cur_room].size(); i++){
                if(vis[rooms[cur_room][i]]) continue;
                tovis.push(rooms[cur_room][i]);
                vis[rooms[cur_room][i]] = true;
            }
        }
        for(int i = 0; i < N; i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};
