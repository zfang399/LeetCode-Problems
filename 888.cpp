class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = 0;
        set<int> inA;
        for(int i = 0; i < A.size(); i++){
            sumA += A[i];
            inA.insert(A[i]);
        }

        int sumB = 0;
        set<int> inB;
        for(int i = 0; i < B.size(); i++){
            sumB += B[i];
            inB.insert(B[i]);
        }

        // A has 2*diff more candies than B
        int diff = (sumA - sumB) / 2;

        vector<int> ans;
        for(int i = 0; i < A.size(); i++){
            if(inB.find(A[i] - diff) != inB.end()){
                ans.push_back(A[i]);
                ans.push_back(A[i] - diff);
                return ans;
            }
        }
    }
};
