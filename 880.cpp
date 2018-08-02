class Solution {
public:
    int totw = 0;
    map<int, int> aggpos;
    // total weight
    // assign presum weight
    Solution(vector<int> w) {
        for(int i = 0; i < w.size(); i++){
            totw += w[i];
            aggpos[totw] = i;
        }
    }

    int pickIndex() {
        // random number between 0 and total weight
        double ran = ((double) rand() / (RAND_MAX)) * totw;
        return aggpos.upper_bound(ran)->second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
