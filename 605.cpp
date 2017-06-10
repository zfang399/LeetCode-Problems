class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n<1) return true;
        if(!flowerbed[0] && n==1 && flowerbed.size()==1) return true;
        if(!flowerbed[0] && !flowerbed[1]){
            flowerbed[0]=1;
            n--;
        }
        for(int i=1;i<flowerbed.size()-1;i++){
            if(!flowerbed[i] && !flowerbed[i-1] && !flowerbed[i+1]){
                n--;
                flowerbed[i]=true;
            }
        }
        if(!flowerbed[flowerbed.size()-1] && !flowerbed[flowerbed.size()-2]) n--;
        if(n<=0) return true;
        return false;
    }
};
