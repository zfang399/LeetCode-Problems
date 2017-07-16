class Solution {
public:
    int nextGreaterElement(int n) {
        string x=to_string(n);
        int i=-1;
        for(i=x.size()-2;i>=0;i--){
            if(x[i]<x[i+1]) break;
        }
        if(i==-1) return -1;
        reverse(x.begin()+i+1,x.end());
        int indj=0,diff=INT_MAX;
        for(int j=i+1;j<x.size();j++){
            if(x[j]-x[i]<diff && x[j]-x[i]!=0 && x[j]!='0' && x[j]-x[i]>0){
                indj=j;
                diff=x[j]-x[i];
            }
        }
        swap(x[indj],x[i]);
        if(stoll(x)>INT_MAX) return -1;
        cout<<1;
        return stoi(x);
    }
};
