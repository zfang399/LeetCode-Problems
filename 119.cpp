class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        vector<int> *tmp;
        for(int i=0;i<=rowIndex;i++){
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    ans.push_back(1);
                }else{
                    ans.push_back(ans[j-1]+ans[j]);
                }
            }
            ans.erase(ans.begin(),ans.begin()+i);
        }
        return ans;
    }
};
