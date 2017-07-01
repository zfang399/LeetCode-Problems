class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map <int,int> count;
        for(int i=0;i<wall.size();i++){
            int x=0;
            for(int j=0;j<wall[i].size()-1;j++){
                x+=wall[i][j];
                count[x]++;
            }
        }
        int ans=wall.size();
        for(auto e:count){
            if(wall.size()-e.second<ans){
                ans=wall.size()-e.second;
            }
        }
        return ans;
    }
};
