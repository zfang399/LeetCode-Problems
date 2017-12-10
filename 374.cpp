// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long f=1,r=n;
        while(f<=r){
            int m=(f+r)/2,res=guess(m);
            if(res==0){
                return m;
            }else if(res==1){
                f=m+1;
            }else{
                r=m-1;
            }
        }
    }
};
 
