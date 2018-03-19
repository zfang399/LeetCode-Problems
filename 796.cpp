class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() == 0 && B.size() == 0) return true;
        for(int i = 0; i < B.size(); i++){
            string rotated = B.substr(i) + B.substr(0,i);
            if(A.compare(rotated) == 0){
                return true;
            }
        }
        return false;
    }
};
