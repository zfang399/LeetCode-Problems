class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int f=0,r=height.size()-1;
        while(f<r){
            int h=min(height[f],height[r]);
            ans=max(ans,h*(r-f));
            while(height[f]<=h) f++;
            while(height[r]<=h) r--;
        }
        return ans;
    }
};
