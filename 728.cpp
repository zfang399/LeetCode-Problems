class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++){
            if(selfdiv(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
    bool selfdiv(int k){
        int tmp = k;
        while(tmp>0){
            int x = tmp % 10;
            tmp /= 10;
            if(x==0) return false;
            if(k % x != 0) return false;
        }
        return true;
    }
};
