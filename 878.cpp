class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        if(A > B) swap(A,B);

        // Find least common multiple
        long long int gg = gcd(A,B);
        long long int lcm = A * B / gg;

        // Calculate cycles + residual
        long long int lcount = lcm / A + lcm / B - 1;
        long long int div = N / lcount;
        long long int res = N % lcount;

        // Add cycles and residual
        long long int tmp = 0;
        tmp = (lcm * div) % 1000000007;
        int aa = 0;
        int bb = 0;
        int add = 0;
        while(res > 0){
            res--;
            if(aa + A <= bb + B){
                aa += A;
                add = aa;
            }else{
                bb += B;
                add = bb;
            }
        }
        return (tmp + add) % 1000000007;
    }

    int gcd(int A, int B) {
        return B == 0 ? A : gcd(B, A % B);
    }
};
