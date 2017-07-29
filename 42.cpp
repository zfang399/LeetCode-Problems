class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3) return 0;
        int ans=0;
        int f=0,r=height.size()-1,base=0;
        while(height[f]<=height[f+1] && f<r) f++;
        while(height[r]<=height[r-1] && r>f) r--;
        while(f<r){
            int k=min(height[f],height[r]);
            for(int i=f+1;i<r;i++){
                if(height[i]<k) ans+=(k-max(base,height[i]));
            }
            base=k;
            if(height[f]<height[r]){
                int fn=f;
                while(height[f]>=height[fn] && fn<r) fn++;
                f=fn;
            }else if(height[f]>height[r]){
                int rn=r;
                while(height[r]>=height[rn] && rn>f) rn--;
                r=rn;
            }else{
                int fn=f,rn=r;
                while(height[f]>=height[fn] && fn<r) fn++;
                while(height[r]>=height[rn] && rn>fn) rn--;
                f=fn,r=rn;
            }
        }
        return ans;
    }
};
