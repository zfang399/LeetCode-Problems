class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int allxor = 0;
        for(int i = 0; i < nums.size(); i++) allxor = allxor ^ nums[i];
        return allxor == 0 || nums.size() % 2 == 0;
    }
};
