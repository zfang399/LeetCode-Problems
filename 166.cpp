class Solution {
public:
    string fractionToDecimal(int numer, int denom) {
        long numerator=numer;
        long denominator=denom;
        if(numerator%denominator==0) return to_string(numerator/denominator);
        string ans;
        if(numerator<0){
            if(denominator<0){
                numerator*=-1;
                denominator*=-1;
            }else{
                ans="-";
                numerator*=-1;
            }
        }else if(denominator<0){
            ans="-";
            denominator*=-1;
        }
        if(numerator>denominator){
            ans+=to_string(numerator/denominator);
            ans+='.';
            numerator=(numerator%denominator)*10;
        }else{
            ans+="0.";
            numerator*=10;
        }
        unordered_map<long,long> m;
        while (numerator) {
            long q=numerator/denominator;
            if (m.find(numerator)!=m.end()) {
                ans.insert(m[numerator],1,'(');
                ans+=')';
                break;
            }
            m[numerator]=ans.size();
            ans+=to_string(q);
            numerator=(numerator%denominator)*10;
        }
        return ans;
    }
};
