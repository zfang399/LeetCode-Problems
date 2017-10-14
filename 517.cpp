class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        vector<int> presum;
        presum.push_back(0);
        for(int i=0;i<machines.size();i++){
            presum.push_back(presum.back()+machines[i]);
        }
        if(presum.back()%machines.size()!=0) return -1;
        int avg=presum.back()/machines.size();
        int ans=0;
        for(int i=0;i<machines.size();i++){
            int l=i*avg-presum[i];
            int r=(machines.size()-i-1)*avg-(presum.back()-presum[i+1]);
            if(l>0 && r>0){
                ans=max(ans,l+r);
            }else{
                ans=max(ans,max(abs(l),abs(r)));
            }
        }
        return ans;
    }
};
