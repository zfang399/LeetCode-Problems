class Solution {
public:
    string getPermutation(int n, int k) {
        if(n==1) return to_string(k);
        string ans;
        vector<int> num(n+1);
        int tot=1,xth,nn=n;
        for(int i=1;i<=n;i++){
            num[i]=i;
            tot*=i;
        }
        tot/=nn;
        nn--;
        while(k>0 && nn>=0){
            xth=(k-1)/tot+1;
            //k%=tot;
            k-=(xth-1)*tot;
            if(nn>0) tot/=nn;
            nn--;
            ans+=to_string(num[xth]);
            num.erase(num.begin()+xth,num.begin()+xth+1);
        }
        return ans;
    }
};
