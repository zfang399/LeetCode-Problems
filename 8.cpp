class Solution {
public:
    int myAtoi(string str) {
        long long ans=0;
        int ind=1;
        for(int i=0;i<str.size();i++){
            while(str[i]==' ') i++;
            if(str[i]=='-'||str[i] =='+') ind=(str[i++]=='-')?-1:1;
            if(str[i]=='.') return ans;
            while(0<=str[i]-'0' && str[i]-'0'<=9){
                int x=str[i]-'0';
                ans=ans*10+x;
                if(ans*ind>=INT_MAX) return INT_MAX;
                if(ans*ind<=INT_MIN) return INT_MIN;
                i++;
            }
            return ans*ind;
        }
        return ans*ind;
    }
};
