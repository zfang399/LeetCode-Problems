class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int i1 = num1.size() - 1,i2 = num2.size() - 1;
        int now = 0, ex = 0;
        while(i1 >= 0 && i2 >= 0){
            now= ex + num1[i1] + num2[i2] - '0' - '0';
            i1--;
            i2--;
            ex= now / 10;
            now= now % 10;
            ans=to_string(now) + ans;
        }
        while(i1>=0){
            now=ex+num1[i1]-'0';
            i1--;
            ex=now/10;
            now=now%10;
            ans=to_string(now)+ans;
        }
        while(i2 >= 0){
            now= ex + num2[i2] - '0';
            i2--;
            ex= now / 10;
            now= now % 10;
            ans= to_string(now) + ans;
        }
        if(ex){
            ans= to_string(ex) + ans;
        }
        return ans;
    }
}; 
