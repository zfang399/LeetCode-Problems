class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if(forest.empty()) return 0;
        if(forest[0].empty()) return 0;
        vector<vector<int>> t;
        for(int i=0;i<forest.size();i++){
            for(int j=0;j<forest[0].size();j++){
                if(forest[i][j]>1){
                    t.push_back({forest[i][j],i,j});
                }
            }
        }
        sort(t.begin(),t.end());
        int ans=0,x=0,y=0;
        for(int i=0;i<t.size();i++){
            int add=bfs(forest,x,y,t[i][1],t[i][2]);
            if(add==-1) return -1;
            ans+=add;
            x=t[i][1];
            y=t[i][2];
        }
        return ans;
    }
    int bfs(vector<vector<int>>& forest,int i,int j,int fi,int fj){
        if(i==fi && j==fj) return 0;
        queue<pair<int, int>> q;
        q.push(make_pair(i,j));
        vector<vector<bool>> visited(forest.size(),vector<bool>(forest[0].size(),false));
        visited[i][j]=true;
        int step=0;
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(q.size()){
            step++;
            int size=q.size();
            for(int i=0;i<size;i++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int i=0;i<dir.size();i++){
                    int r=row+dir[i][0];
                    int c=col+dir[i][1];
                    if (r<0||r>=forest.size()||c<0||c>=forest[0].size()||visited[r][c]==1||forest[r][c]==0) continue;
                    if (r==fi&&c==fj) return step;
                    visited[r][c]=1;
                    q.push(make_pair(r,c));
                }
            }
        }
        return -1;
    }
};
