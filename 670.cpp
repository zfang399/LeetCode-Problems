class Solution {
public:
    int maximumSwap(int num) {
        vector<int> ns;
        while(num>0){
            ns.push_back(num%10);
            num/=10;
        }
        for(int i=ns.size()-1;i>0;i--){
            int m=0,p=0;
            for(int j=i-1;j>=0;j--){
                if(ns[j]>=m){
                    m=ns[j];
                    p=j;
                }
            }
            if(m>ns[i]){
                ns[p]=ns[i];
                ns[i]=m;
                break;
            }
        }
        long long ans=0;
        for(int i=ns.size()-1;i>=0;i--){
            ans+=ns[i];
            ans*=10;
        }
        ans/=10;
        return ans;
    }
};
