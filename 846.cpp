class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> count;
        for(int i = 0; i < hand.size(); i++){
            count[hand[i]] ++;
        }

        for(map<int,int>::iterator it = count.begin(); it != count.end(); it++){
            // cout << it->first << " " << it->second <<endl;
            if(it->second == 0) continue;
            int first = it->first;
            int num = it->second;
            map<int,int>::iterator tmp = it;
            for(int i = 0; i < W; i++){
                if(count[first] < num) return false;
                count[first] -= num;
                first++;
            }
        }
        return true;
    }
};
