class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int ex=0,sum,i=a.length()-1,j=b.length()-1;
        while(i>=0 && j>=0){
            sum=a[i]-'0'+b[j]-'0'+ex;
            i--,j--;
            ans=to_string(sum%2)+ans;
            ex=sum/2;
            cout<<ans<<endl;
        }
        while(i>=0){
            sum=a[i]-'0'+ex;
            i--;
            ans=to_string(sum%2)+ans;
            ex=sum/2;
        }
        while(j>=0){
            sum=b[j]-'0'+ex;
            j--;
            ans=to_string(sum%2)+ans;
            ex=sum/2;
        }
        if(ex) ans='1'+ans;
        return ans;
    }
};
