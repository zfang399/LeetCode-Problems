class Solution {
public:
    map<pair<int,int>,double> vis;
    double largestSumOfAverages(vector<int>& A, int K) {
        return help(A,0,K);
    }

    double help(vector<int>& A, int start, int K){
        if(vis[make_pair(start,K)] != 0) return vis[make_pair(start,K)];
        if(K == 1){
            double ret = 0;
            for(int i = start; i < A.size(); i++){
                ret += A[i];
            }
            vis[make_pair(start,K)] = ret/(A.size() - start);
            return ret/(A.size() - start);
        }
        double cursum = 0;
        double curave = 0;
        double ans = 0;
        for(int i = start; i < A.size() - K + 1; i++){
            cursum += A[i];
            if(vis[make_pair(i + 1,K-1)] != 0){
                curave = cursum / (i - start +1) + vis[make_pair(i + 1,K-1)];
                if(curave > ans) ans = curave;
                continue;
            }
            curave = cursum / (i - start +1) + help(A, i + 1, K - 1);
            if(curave > ans) ans = curave;
        }
        vis[make_pair(start,K)] = ans;
        return ans;
    }
};
