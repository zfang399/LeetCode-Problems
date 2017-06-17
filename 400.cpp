class Solution {
public:
    int findNthDigit(int n) {
        long long basen=9,based=1;
        while(n>basen*based){
            n-=basen*based;
            basen*=10;
            based++;
        }
        int nth=n/based,dth=n%based;
        cout<<nth<<endl;
        if(dth==0){
            dth=based;
            nth--;
        }
        long long num=pow(10,based-1)+nth;
        while(based-dth>0){
            num/=10;
            dth++;
        }
        return num%10;
    }
};
