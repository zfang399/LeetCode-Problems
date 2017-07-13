class Solution {
public:
    string getHint(string secret, string guess) {
        int scow[10]={0},gcow[10]={0},a=0,b=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                a++;
            }else{
                scow[secret[i]-'0']++;
                gcow[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++) b+=min(scow[i],gcow[i]);
        return to_string(a)+"A"+to_string(b)+"B";
    }
};
