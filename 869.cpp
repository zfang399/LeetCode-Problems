class Solution {
public:
    // idea from lee215
    bool reorderedPowerOf2(int N) {
        long digN = digitcount(N);
        for(int i = 0; i < 32; i++){
            if(digitcount(1 << i) == digN) return true;
        }
        return false;
    }

    long digitcount(int N){
        long digits = 0;
        while(N != 0){
            digits += pow(10, N % 10);
            N /= 10;
        }
        return digits;
    }
};
