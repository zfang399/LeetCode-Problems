class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image;
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(image.size(),vector<bool>(image[0].size(),false));
        q.push(make_pair(sr,sc));
        while(q.size()){
            int r = q.front().first;
            int c = q.front().second;
            //cout<<r<<" "<<c<<endl;
            q.pop();
            if(visited[r][c]) continue;
            visited[r][c]=true;
            if(r > 0){
                if(image[r-1][c] == image[r][c] && !visited[r-1][c]){
                    q.push(make_pair(r-1,c));
                }
            }
            if(r + 1 < image.size()){
                if(image[r+1][c] == image[r][c] && !visited[r+1][c]){
                    q.push(make_pair(r+1,c));
                }
            }
            if(c > 0){
                if(image[r][c-1] == image[r][c] && !visited[r][c-1]){
                    q.push(make_pair(r,c-1));
                }
            }
            if(c + 1 < image[0].size()){
                if(image[r][c+1] == image[r][c] && !visited[r][c+1]){
                    q.push(make_pair(r,c+1));
                }
            }
            image[r][c] = newColor;
        }
        return image;
    }
};
