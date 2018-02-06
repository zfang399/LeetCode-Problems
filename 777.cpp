class Solution {
public:
     bool canTransform(string start, string end) {
        int i = 0, j = 0, n = start.length();
        while(j < n && i < n){
            while(j < n && end[j] == 'X') j++;
            while(i < n && start[i] == 'X') i++l
            if(i == n && j == n) break;
            if(i == n || j == n) return false;
            if(start[i] != end[j]) return false;
            if(start[i] == 'R' && i > j) return false;
            if(start[i] == 'L' && i < j) return false;
            i++;
            j++;
        }

        return true;
    }
};
