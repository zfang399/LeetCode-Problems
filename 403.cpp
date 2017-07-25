class Solution {
public:
    map< pair<int,int>, bool > v;
    bool canCross(vector<int>& stones) {
        unordered_map<int,bool> rock;
        int target=stones[stones.size()-1];
        for(int i=0;i<stones.size();i++){
            if(i>3 && stones[i]>stones[i-1]*2) return false;
            rock[stones[i]]=true;
        }
        return dfs(1,rock,target,stones[0]);
    }
    bool dfs(int step,unordered_map<int,bool>& rock,int target,int nowat){
        if(v[make_pair(nowat,step)]) return false;
        if(nowat==0){
            if(rock[nowat+step] && dfs(step,rock,target,nowat+step)) return true;
            return false;
        }
        if (nowat+step-1==target||nowat+step==target||nowat+step+1==target){
            return true;
        }
        if(rock[nowat+step]){
            if(dfs(step,rock,target,nowat+step)) return true;
        }
        if(rock[nowat+step+1]){
            if(dfs(step+1,rock,target,nowat+step+1)) return true;
        }
        if(rock[nowat+step-1] && step-1>0){
            if(dfs(step-1,rock,target,nowat+step-1)) return true;
        }
        v[make_pair(nowat,step)]=true;
        return false;
    }
};
