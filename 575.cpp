class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int num=candies.size()/2;
        map<int,int> candykind;
        for(int i=0;i<candies.size();i++){
            if(candykind.count(candies[i])==1){
                continue;
            }
            candykind[candies[i]]=1;
        }
        if(candykind.size()>num) return num;
        return candykind.size();
    }
};
