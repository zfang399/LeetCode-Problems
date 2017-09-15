class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r,d;
        int l=senate.length();
        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R') r.push(i);
            else d.push(i);
        }
        while(r.size() && d.size()){
            int rt=r.front(),dt=d.front();
            r.pop();
            d.pop();
            if(rt<dt){
                r.push(rt+l);
            }else{
                d.push(dt+l);
            }
        }
        if(r.size()) return "Radiant";
        return "Dire";
    }
};
