class Solution {
public:
    bool judgeCircle(string moves) {
        int h=0,v=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L'){
                h--;
            }else if(moves[i]=='R'){
                h++;
            }else if(moves[i]=='U'){
                v--;
            }else if(moves[i]=='D'){
                v++;
            }
        }
        if(!h && !v) return true;
        return false;
    }
};
