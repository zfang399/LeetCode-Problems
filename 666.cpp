class Solution {
public:
    int pathSum(vector<int>& nums) {
        int ans=0;
        vector<vector<int>> t(5,vector<int>(9,-1));
        for(int i=0;i<nums.size();i++){
            int d=nums[i]/100;
            int p=(nums[i]-d*100)/10;
            int v=nums[i]-d*100-p*10;
            t[d][p]=v;
        }
        int top=16;
        for(int i=4;i>=1;i--){
            top/=2;
            for(int j=1;j<=top;j++){
                if(t[i][j]==-1) continue;
                bool kk=false;
                if(i==4) kk=true;
                else if(t[i+1][2*(j-1)+1]==-1 && t[i+1][2*(j-1)+2]==-1) kk=true;
                if(kk){
                    int x=i,y=j;
                    while(x>=1){
                        ans+=t[x][y];
                        x--;
                        y=(y-1)/2+1;
                    }
                }
            }
        }
        return ans;
    }
};
