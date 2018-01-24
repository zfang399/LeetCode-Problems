class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ans = 0;
        vector<int> pos(row.size(),0);
        for(int i = 0; i < row.size(); i++) pos[row[i]] = i;
        for(int i = 0; i < row.size(); i+=2){
            int x;
            if(row[i] % 2) x = row[i] -1;
            else x = row[i] + 1;
            if(row[i + 1] != x){
                int tmp = row[i + 1];
                pos[tmp] = pos[x];
                pos[x] = i + 1;
                row[pos[tmp]] = tmp;
                row[i + 1] = x;
                ans++;
            }
        }
        return ans;
    }
};
