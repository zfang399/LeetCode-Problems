class Solution {
public:
    int longestMountain(vector<int>& A) {
        int m = A.size();
        if(m == 0) return 0;
        // left peak and right peak
        vector<int> lp(m,0);
        vector<int> rp(m,0);
        lp[0] = 0;
        rp[m - 1] = 0;
        for(int i = 1; i < m; i++){
            lp[i] = A[i] > A[i - 1] ? lp[i - 1] + 1 : 0;
            rp[m - i - 1] = A[m - i - 1] > A[m - i] ? rp[m - i] + 1 : 0;
        }
        // get answer
        int ans = 0;
        for(int i = 0; i < m; i++){
            if(lp[i] == 0 || rp[i] == 0) continue;
            ans = lp[i] + rp[i] + 1 > ans ? lp[i] + rp[i] + 1 : ans;
        }
        return ans;
    }
};
