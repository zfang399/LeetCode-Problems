class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        // flip rows
        for(int i = 0; i < A.size(); i++){
            if(A[i][0] == 0){
                for(int j = 0; j < A[i].size(); j++){
                    A[i][j] = 1- A[i][j];
                }
            }
        }

        // flip columns with more zeros than ones
        for(int j = 0; j < A[0].size(); j++){
            int ones = 0;
            for(int i = 0; i < A.size(); i++){
                ones += A[i][j];
            }
            if(ones * 2 < A.size()){
                for(int i = 0; i < A.size(); i++){
                    A[i][j] = 1- A[i][j];
                }
            }
        }

        // calculate scores
        int ans = 0;
        for(int i = 0; i < A.size(); i++){
            int tmp = 0;
            int times = 1;
            for(int j = A[i].size() - 1; j >= 0; j--){
                tmp += A[i][j] * times;
                times *= 2;
            }
            ans += tmp;
        }

        return ans;
    }
};
