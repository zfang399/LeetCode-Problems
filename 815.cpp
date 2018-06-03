class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        // if the start and the destination is the same
        if(S == T) return 0;

        int ans = 0;
        vector<vector<int>> br; // vector to record which routes each bus stop has
        vector<int> tmp;        // empty vector to accomodate the size of br
        br.push_back(tmp);      // there is at least one bus stop
        for(int i = 0; i < routes.size(); i++){
            for(int j = 0; j < routes[i].size(); j++){
                // increase bus stops if we run out of space
                while(br.size() - 1 < routes[i][j]){
                    br.push_back(tmp);
                }
                // add route i to bus stop routes[i][j]
                br[routes[i][j]].push_back(i);
            }
        }

        vector<bool> visited(br.size(),false);     // vector to record if each bus stop has been visited
        vector<bool> routed(routes.size(),false);  // vector to record if each route has been tried
        visited[S] = true;                         // start bus stop is already visited
        queue<int> path;                           // queue for BFS
        path.push(S);

        int counter = 1;                           // counter to make sure we add the answer correctly after each round

        // Breadth First Search
        // stop if there is no new bus stops we can try
        while(path.size()){
            counter--;
            int cur_stop = path.front();
            path.pop();
            // try all the routes the current bus stop can offer
            for(int i = 0; i < br[cur_stop].size(); i++){
                // skip if we have already tried this route
                int try_route = br[cur_stop][i];
                if(routed[try_route]) continue;
                routed[try_route] = true;          // mark as visited

                // try all the bus stops this route can lead to
                for(int j = 0; j < routes[try_route].size(); j++){
                    // if there is the destination, return.
                    if(routes[try_route][j] == T) return ans + 1;
                    // push the unvisited stops into BFS queue
                    if(!visited[routes[try_route][j]]){
                        visited[routes[try_route][j]] = true;
                        path.push(routes[try_route][j]);
                    }
                }
            }
            // if the current round of search is done: increment ans, update counter.
            if(counter == 0){
                counter = path.size();
                ans++;
            }
        }
        // return -1 if impossible
        return -1;
    }
};
