class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        // If only one number, difference is 0
        if(A.size() <= 1) return 0;
        // Map to get all numbers, since all numbers are between 0 and 10000, we can "sort" it really efficiently
        map<int,bool> inA;
        int minA = 10000;
        int maxA = 0;
        for(int i = 0; i < A.size(); i++){
            inA[A[i]] = true;
            minA = min(minA, A[i]);
            maxA = max(maxA, A[i]);
        }
        // Save map into vector
        vector<int> sortedA;
        for(int i = minA; i <= maxA; i++){
            if(inA[i]) sortedA.push_back(i);
        }

        int n = sortedA.size();
        // If only one effective number, return 0
        if(n == 1) return 0;
        // Baseline answer
        int ans = maxA - minA;
        // If K is 0, no possibility to improve baseline answer, return it
        if(K == 0) return ans;
        // Return best answer
        int lb, rb;
        // Try every i, where we add K to A[j] for 0 <= j <= i, and subtract K to A[j] for i + 1 < j <= n - 1.
        for(int i = 0; i < n - 1; i++){
            lb = min(sortedA[0] + K, sortedA[i + 1] - K);
            rb = max(sortedA[i] + K, sortedA[n - 1] - K);
            ans = min(ans, rb - lb);
        }
        return ans;
    }
};
