class Solution {
public:
    int numDecodings(string s) {
        if(s.length()==0) return 0;
        if(s[0]-'1'<0 || s[0]-'9'>0) return 0;
        vector<int> v(s.length()+1);
        v[0]=1,v[1]=1;
        for(int i=1;i<s.length();i++){
            if(((s[i-1]-'0')*10+s[i]-'0')>=10 && ((s[i-1]-'0')*10+s[i]-'0')<=26){
                if(s[i]-'0'<=0 || s[i]-'9'>0) v[i+1]=v[i-1];
                else v[i+1]=v[i-1]+v[i];
            }else{
                if(s[i]-'0'<=0 || s[i]-'9'>0) return 0;
                v[i+1]=v[i];
            }
        }
        return v[s.length()];
    }
};
