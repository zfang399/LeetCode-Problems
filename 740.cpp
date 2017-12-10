class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> points(10001,0);
        for(int i = 0; i < nums.size(); i++){
            points[nums[i]] += nums[i];
        }
        int prev = 0;
        int cur = 0;
        for(int i = 0; i < points.size(); i++){
            int tmp = cur;
            cur = max(prev + points[i], cur);
            prev = tmp;
        }
        return cur;
    }
};
