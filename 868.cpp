class Solution {
public:
    int binaryGap(int N) {
        // whether the first one is found
        bool oneyet = false;
        // whether the second one is found
        bool twoyet = false;
        // last found one
        int lastone = 0;
        int count = 0;
        int ans = 0;
        while(N > 0){
            count++;
            int digit = N % 2;
            N /= 2;
            if(digit){
                if(!oneyet){
                    oneyet = true;
                    lastone = count;
                }else{
                    if(!twoyet){
                        twoyet = true;
                        ans = count - lastone;
                    }else{
                        ans = max(ans, count - lastone);
                    }
                    lastone = count;
                }
            }
        }
        if(!twoyet) return 0;
        return ans;
    }
};
