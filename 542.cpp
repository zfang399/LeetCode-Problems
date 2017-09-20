class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<int>> v(m,vector<int>(n));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!matrix[i][j]){
                    v[i][j]=true;
                    ans[i][j]=0;
                    q.push(make_pair(i,j));
                }
            }
        }
        while(q.size()){
            pair<int,int> x=q.front();
            q.pop();
            if(x.first-1>=0){
                if(!v[x.first-1][x.second]){
                    v[x.first-1][x.second]=true;
                    ans[x.first-1][x.second]=ans[x.first][x.second]+1;
                    q.push(make_pair(x.first-1,x.second));
                }
            }
            if(x.first+1<m){
                if(!v[x.first+1][x.second]){
                    v[x.first+1][x.second]=true;
                    ans[x.first+1][x.second]=ans[x.first][x.second]+1;
                    q.push(make_pair(x.first+1,x.second));
                }
            }
            if(x.second-1>=0){
                if(!v[x.first][x.second-1]){
                    v[x.first][x.second-1]=true;
                    ans[x.first][x.second-1]=ans[x.first][x.second]+1;
                    q.push(make_pair(x.first,x.second-1));
                }
            }
            if(x.second-1<n){
                if(!v[x.first][x.second+1]){
                    v[x.first][x.second+1]=true;
                    ans[x.first][x.second+1]=ans[x.first][x.second]+1;
                    q.push(make_pair(x.first,x.second+1));
                }
            }
        }
        return ans;
    }
};
