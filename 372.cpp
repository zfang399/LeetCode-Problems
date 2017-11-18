class Solution {
public:
    int power(int a, int x){
        a %= 1337;
        int ret = 1;
        for (int i = 0; i < x; ++i) ret = (ret * a) % 1337;
        return ret;
    }
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last = b.back();
        b.pop_back();
        return power(superPow(a, b),10)*power(a,last)% 1337;
    }
};
