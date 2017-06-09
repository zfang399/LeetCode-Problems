class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for(int i=0;i<ops.size();i++){
            m=min(ops[i][0],m);
            n=min(ops[i][1],n);
        }
        return m*n;
    }
};
