class Solution {
public:
    bool isAdditiveNumber(string num) {
        for(int i = 1; i <= num.size()/2; i++){
            for(int j = 1; j <= (num.size()-i)/2; j++){
                if(addi(num.substr(0,i), num.substr(i,j), num.substr(i+j))) return true;
            }
        }
        return false;
    }
    bool addi(string s1, string s2, string s3){
        if(s1.size()>1 && s1[0]=='0') return false;
        if(s2.size()>1 && s2[0]=='0') return false;
        string tot;
        int i = s1.length() - 1, j = s2.length() - 1, carry = 0;
        while(i >= 0 || j >= 0){
            int sum = carry;
            if(i >= 0){
                sum += s1[i--]-'0';
            }
            if(j >= 0){
                sum += s2[j--]-'0';
            }
            tot += sum%10 + '0';
            carry = sum/10;
        }
        if(carry) tot += carry+'0';
        reverse(tot.begin(), tot.end());
        if(s3.compare(tot) == 0) return true;
        if(s3.size() <= tot.size() || tot.compare(s3.substr(0,tot.length())) != 0) return false;
        return addi(s2,tot,s3.substr(tot.length()));
    }
};
