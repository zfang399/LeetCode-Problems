class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> s;
        int i=0;
        int ans=0;
        while (i<heights.size()) {
            if (s.empty()||heights[i]>=heights[s.top()]){
                s.push(i);
                i++;
            }
            else {
                int h=s.top();
                s.pop();
                ans=max(ans,heights[h]*(s.empty()?i:i-s.top()-1));
            }
        }
        return ans;
    }
};
