class Solution {
public:
    string fractionAddition(string expression) {
        unordered_map <int,int> nume;
        bool neg=false;
        int num=0;
        if(expression[0]=='-'){
            neg=true;
        }else{
            num=expression[0]-'0';
        }
        int i=1;
        while(i<expression.length()){
            if(expression[i]=='/'){
                i++;
                int denom=expression[i]-'0';
                i++;
                while(expression[i]!='+' && expression[i]!='-' && i<expression.length()){
                    denom*=10;
                    denom+=expression[i]-'0';
                    i++;
                }
                if(neg) num=-num;
                nume[denom]+=num;
                num=0;
                continue;
            }else if(expression[i]=='-'){
                neg=true;
            }else if(expression[i]=='+'){
                neg=false;
            }else{
                num*=10;
                num+=expression[i]-'0';
            }
            i++;
        }
        int tot=9*8*7*6*5*4*3*2,numer=0;
        for(auto e:nume){
            numer+=e.second*tot/e.first;
        }
        cout<<numer<<" "<<tot<<endl;
        for(i=2;i<=9;i++){
            while(numer%i==0 && tot%i==0){
                numer/=i;
                tot/=i;
            }
        }
        return to_string(numer)+"/"+to_string(tot);
    }
};
