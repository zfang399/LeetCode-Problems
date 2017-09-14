class Solution {
public:
    string toHex(int num) {
        if(num==0) return "0";
        string ans;
        char hexa[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        int cnt=0;
        while(num!=0 && cnt<8){
            ans=hexa[(num&15)]+ans;
            num=num>>4;
            cnt++;
        }
        return ans;
    }
};
