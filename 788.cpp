class Solution {
public:
    int rotatedDigits(int n) {
        int i, num, count = 0, is_valid[] = {0, 0, 1, 2, 2, 1, 1, 2, 0, 1};
        bool found = false;

        for(i = 2; i <= n; i++){
            num = i; found = false;
            while(num){
               if(is_valid[num % 10] == 2) {found = false; break;}
               if(is_valid[num % 10] == 1) found = true;
               num = num/10;
            }
            if(found == true) count++;
        }
        return count;
    }
};
