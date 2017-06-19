class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ar=0,br=0,ai=0,bi=0,i=0;
        bool isneg=false;
        if(a[0]=='-'){
            i++;
            isneg=true;
        }
        while(a[i]!='+'){
            ar=ar*10+(a[i]-'0');
            i++;
        }
        if(isneg) ar=-ar;
        isneg=false;
        i++;
        if(a[i]=='-'){
            i++;
            isneg=true;
        }
        while(a[i]!='i'){
            ai=ai*10+(a[i]-'0');
            i++;
        }
        if(isneg) ai=-ai;

        isneg=false;
        i=0;
        if(b[0]=='-'){
            i++;
            isneg=true;
        }
        while(b[i]!='+'){
            br=br*10+(b[i]-'0');
            i++;
        }
        if(isneg) br=-br;
        isneg=false;
        i++;
        if(b[i]=='-'){
            i++;
            isneg=true;
        }
        while(b[i]!='i'){
            bi=bi*10+(b[i]-'0');
            i++;
        }
        if(isneg) bi=-bi;

        string ans=to_string(ar*br-ai*bi)+"+"+to_string(ar*bi+ai*br)+"i";
        return ans;
    }
};
