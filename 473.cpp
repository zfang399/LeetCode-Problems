class Solution {
public:
    bool visited[15]={false};
    bool makesquare(vector<int>& nums) {
        if(nums.size()==0) return false;
        int ctot=0,cave=0;
        for(int i=0;i<nums.size();i++) ctot+=nums[i];
        if(ctot%4!=0) return false;
        cave=ctot/4;
        for(int i=0;i<nums.size();i++) if(nums[i]>cave) return false;
        visited[0]=true;
        return stick(cave-nums[0],cave,cave,cave,nums);
    }
    bool stick(int a, int b, int c, int d, vector<int>& nums){
        if(a<0 || b<0 || c<0 || d<0) return false;
        if(a==0 && b==0 && c==0 && d==0) return true;
        for(int i=1;i<nums.size();i++){
            if(!visited[i]){
                visited[i]=true;
                bool ret=false;
                ret=ret||stick(a-nums[i],b,c,d,nums);
                if(a!=b) ret=ret||stick(a,b-nums[i],c,d,nums);
                if(a!=c && b!=c) ret=ret||stick(a,b,c-nums[i],d,nums);
                if(a!=d && b!=d && c!=d) ret=ret||stick(a,b,c,d-nums[i],nums);
                visited[i]=false;
                return ret;
            }
        }
        return false;
    }
};
