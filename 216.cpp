class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> t;
        helper(k,n,t);
        return ans;
    }
    void helper(int k, int n, vector<int> x){
        if(k==0 && n==0){
            ans.push_back(x);
            return;
        }else if(k==0 || n==0) return;
        int nn=0;
        for(int i=1;i<k;i++) nn+=i;
        int maxf=min(9,(n-nn)/k),minf=0;
        if(x.size()!=0) minf=x.back();
        for(int i=minf+1;i<=maxf;i++){
            x.push_back(i);
            helper(k-1,n-i,x);
            x.erase(x.end()-1,x.end());
        }
    }
};
