class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        set<int> chunk;
        for (int i = 0; i < arr.size(); i++) {
            chunk.insert(arr[i]);
            if (*chunk.rbegin() == i) ans++;
        }
        return ans;
    }
};
