class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        if(num.length()==k) return "0";
        while(k>0){
            bool zero=false;
            for(int i=0;i<k;i++){
                if(num[i]=='0'){
                    num=num.substr(i+1);
                    zero=true;
                    k-=i;
                    break;
                }
            }
            if(!zero) break;
        }
        int f=0;
        while(k>0 && num.length()){
            int maxp=num.length()-1,maxn=0;
            for(int i=0;i<num.length()-1;i++){
                if(num[i]>num[i+1]){
                    maxp=i;
                    maxn=num[i]-'0';
                    break;
                }
            }
            num=num.substr(0,maxp)+num.substr(maxp+1);
            k--;
            f=min(maxp,int(num.length())-k);
        }
        while(num[0]=='0' && num.length()>1) num=num.substr(1);
        if(num.length()==0) num="0";
        return num;
    }
};
