class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool f=false;
        for (int i = 0;i<bits.size();i++) {
            if(bits[i]){
                f=false;
                i+=1;
            }
            else f=true;
        }
        return f;
    }
};
