class Solution {
public:
    bool buddyStrings(string A, string B) {
        // If lengths are different, or lengths smaller than 2, false.
        if(A.length() != B.length()) return false;
        if(A.length() < 2) return false;

        // Find the first pair of different characters
        unordered_map<char,bool> seen;
        bool rep = false;
        int diff1 = -1;
        for(int i = 0; i < A.length(); i++){
            if(!seen[A[i]]) seen[A[i]] = true;
            else rep = true;
            if(A[i] != B[i]){
                diff1 = i;
                break;
            }
        }
        // If the strings are identical, return true if there are repeated characters, else return false
        if(diff1 == -1) return rep;

        // Find the second pair of different characters
        int diff2 = -1;
        for(int i = diff1 + 1; i < A.length(); i++){
            if(A[i] != B[i]){
                diff2 = i;
                break;
            }
        }
        // False if only one place is different
        if(diff2 == -1) return false;
        // False if these two places do not agree after swapping
        if (!(A[diff1] == B[diff2] && A[diff2] == B[diff1])) return false;

        // False if there are more than two pairs of different characters
        for(int i = diff2 + 1; i < A.length(); i++){
            if(A[i] != B[i]) return false;
        }
        return true;
    }
};
