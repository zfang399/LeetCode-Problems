class Solution {
public:
    int mirrorReflection(int p, int q) {
        int addh = 0;
        int ref  = 0;

        while(addh % p != 0 || ref == 0){
            addh += q;
            addh %= 2 * p;
            ref++;

            // up and down some times, multiples of 2*p
            if(addh == 0) return 0;
            // ended up on top, odd multiples of p
            if(addh == p){
                if(ref % 2 == 1) return 1;
                return 2;
            }
        }
    }
};
