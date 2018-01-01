class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        for(int i = 0; i < V; i++){
            drop(heights,K,heights[K]+1,true,true);
        }
        return heights;
    }
    bool drop(vector<int>& heights, int K, int h, bool left, bool right){
        if(left && K>0 && heights[K-1] <= heights[K] && drop(heights, K-1, heights[K],true,false)) return true;
        if(right && K<heights.size()-1 && heights[K+1] <= heights[K] && drop(heights, K+1, heights[K],false,true)) return true;
        if(heights[K] == h) return false;
        heights[K]++;
        return true;
    }
};
