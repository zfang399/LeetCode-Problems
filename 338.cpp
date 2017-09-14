class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1,0);
        int off=1;
        for(int i=1;i<num+1;i++){
            if(off*2==i) off=i;
            ans[i]=ans[i-off]+1;
        }
        return ans;
    }
};
