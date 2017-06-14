class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=digits.size()-1;
        digits[i]++;
        int e=digits[i]/10;
        while(e && i>0){
            digits[i]%=10;
            i--;
            digits[i]++;
            e=digits[i]/10;
        }
        if(e){
            digits[0]=0;
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
