class Solution {
public:
    int countPrimeSetBits(int l, int r) {
        set<int> p= {2, 3, 5, 7, 11, 13, 17, 19};
        int ans = 0;
        for (int i = l; i <= r; i++) {
            int sb = 0;
            for (int n = i; n; n >>= 1) sb += n & 1;
            ans += p.count(sb);
        }
        return ans;
    }
};
