class Solution {
public:
    int kthGrammar(int N, int K) {
        int inv = 0;
        while( N > 1){
            if(K%2 == 0){
                inv++;
            }
            K = (K+1)/2;
            N --;
        }
        if(inv%2 == 0){
            return 0;
        }
        return 1;
    }
};
