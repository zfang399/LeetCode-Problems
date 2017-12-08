class Solution {
public:
    bool isPowerOfFour(int num) {
        return fmod(log10(num)/log10(4),1)==0;
    } 
};
