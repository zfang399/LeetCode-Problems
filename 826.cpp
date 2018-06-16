class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans = 0;
        unordered_map<int,int> promax;
        unordered_map<int,int> workernum;
        // Save the corresponding profit of each difficulty
        for(int i = 0; i < difficulty.size(); i++){
            promax[difficulty[i]] = max(promax[difficulty[i]], profit[i]);
        }

        // Save the number of workers with each capacity, and get the best worker
        int bestworker = 0;
        for(int i = 0; i < worker.size(); i++){
            workernum[worker[i]]++;
            bestworker = worker[i] > bestworker ? worker[i] : bestworker;
        }

        // Loop from low to high, find the most profitable work the current worker can do, and add to the answer.
        int cur_max = 0;
        for(int i = 1; i <= bestworker; i++){
            if(promax.count(i) > 0){
                cur_max = promax[i] > cur_max ? promax[i] : cur_max;
            }
            if(workernum.count(i) > 0){
                ans += workernum[i] * cur_max;
            }
        }

        return ans;
    }
};
