class Solution {
public:
    int kSimilarity(string A, string B) {
        // If the strings are the same, no swaps needed
        if(A.compare(B) == 0) return 0;
        // Try swaps
        for (int i = 0; i < A.size() - 1; i++) {
            // If the i-th character is already matched, continue
            if (A[i] == B[i]) continue;
            vector<int> change;
            for (int j = i + 1; j < A.size(); j++) {
                // If the i-th can be fixed by swapping i and j, push it back to vector
                if (A[j] == B[i] && A[j] != B[j]) {
                    change.push_back(j);
                    // If the swap can solve two problems at a time, this is the optimal solution for the current case
                    if (A[i] == B[j]) {
                        swap(A[i],A[j]);
                        return 1 + kSimilarity(A.substr(i+1),B.substr(i+1));
                    }
                }
            }
            // Try all possible swaps in changes.
            int mink = A.size() - 1; // worst situation
            for (int j = 0; j < change.size(); j++) {
                swap(A[i], A[change[j]]);
                mink = min(mink, 1 + kSimilarity(A.substr(i + 1), B.substr(i + 1)));
                swap(A[i], A[change[j]]);
            }
            return mink;
        }
        return 0;
    }
};
