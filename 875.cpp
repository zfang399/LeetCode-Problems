class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int kmin = 1;
        int kmax = 0;
        for(int i = 0; i < piles.size(); i++) if(piles[i] > kmax) kmax = piles[i];

        // Binary search
        while(kmin < kmax){
            int kmid = kmin + (kmax - kmin) / 2;
            //cout << kmin << " " << kmid << " " << kmax << endl;
            if(finish(piles, kmid) <= H){
                kmax = kmid;
            }else{
                kmin = kmid + 1;
            }
        }
        return kmax;
    }

    // Hours to finish
    int finish(vector<int>& piles, int speed){
        int res = 0;
        for(int i = 0; i < piles.size(); i++){
            int add = piles[i] / speed;
            if(add * speed < piles[i]) add++;
            res += add;
        }
        return res;
    }
};
