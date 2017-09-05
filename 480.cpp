class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        unordered_map<int, int> hash;
        priority_queue<int, vector<int>> bm;
        priority_queue<int, vector<int>, greater<int>> tm;
        int i=0;
        while(i<k){
            bm.push(nums[i]);
            i++;
        }
        for (int i=k/2;i>0;--i) {
            tm.push(bm.top()); bm.pop();
        }
        while (true) {
            if (k%2){
                ans.push_back(bm.top());
            }
            else{
                ans.push_back(((double)bm.top()+tm.top())/2);
            }
            if (i==nums.size())break;
            int m=nums[i-k],n=nums[i++],balance=0;
            if (m<=bm.top()){
                --balance;
                if(m==bm.top()){
                    bm.pop();
                }else {
                    ++hash[m];
                }
            }else{
                ++balance;
                if (m == tm.top()){
                    tm.pop();
                }else{
                    ++hash[m];
                }
            }

            if (!bm.empty() && n <= bm.top()){
                ++balance;
                bm.push(n);
            }else{
                --balance;
                tm.push(n);
            }

            if(balance < 0){
                bm.push(tm.top());
                tm.pop();
            }else if(balance > 0){
                tm.push(bm.top());
                bm.pop();
            }
            while (!bm.empty() && hash[bm.top()]){
                --hash[bm.top()];
                bm.pop();
            }
            while (!tm.empty() && hash[tm.top()]){
                --hash[tm.top()];
                tm.pop();
            }
        }
        return ans;
    }
};
