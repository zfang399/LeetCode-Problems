class Solution {
public:
    vector<int> constructRectangle(int area) {
        int mid=sqrt(area);
        vector<int> ans;
        for(int i=mid;i>=1;i--){
            if(area%i==0){
                if(i>area/i){
                    ans.push_back(i);
                    ans.push_back(area/i);
                }else{
                    ans.push_back(area/i);
                    ans.push_back(i);
                }
                return ans;
            }
        }
    }
};
