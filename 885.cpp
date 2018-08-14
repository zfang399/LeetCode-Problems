class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        // Directions to go
        map<pair<int,int>, pair<int,int>> moves;
        moves[make_pair(1,0)] = make_pair(0,-1);
        moves[make_pair(0,-1)] = make_pair(-1,0);
        moves[make_pair(-1,0)] = make_pair(0,1);
        moves[make_pair(0,1)] = make_pair(1,0);

        // Initialization
        int add = 0;
        int countdown = 1;
        pair<int, int> m = make_pair(-1, 0);

        // Iterative moves
        vector<vector<int>> ans;
        ans.push_back({r0, c0});
        while(ans.size() < R * C){
            m = moves[m];
            add++;
            int tmp = countdown;
            while(tmp > 0){
                tmp--;
                r0 += m.first;
                c0 += m.second;
                if(r0 < R && r0 >= 0 && c0 < C && c0 >= 0){
                    ans.push_back({r0, c0});
                }
            }
            if(add == 2){
                countdown++;
                add = 0;
            }
        }

        return ans;
    }
};
