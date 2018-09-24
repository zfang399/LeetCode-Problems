class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int idx = 1;
        while(A[idx] - A[idx - 1] >= 0 && idx < A.size()){
            idx++;
        }
        if(idx == A.size()) return true;
        idx = 1;
        while(A[idx] - A[idx - 1] <= 0 && idx < A.size()){
            idx++;
        }
        if(idx == A.size()) return true;
        return false;
    }
};
