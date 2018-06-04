class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        queue<int> step;
        map<string,bool> inq,dead;
        q.push("0000");
        step.push(0);
        inq["0000"] = true;
        for(int i = 0; i < deadends.size(); i++){
            dead[deadends[i]] = true;
        }
        while(q.size()){
            string now = q.front();
            int sp = step.front();
            q.pop();
            step.pop();
            if(dead[now]) return -1;
            for(int i = 0; i < now.size(); i++){
                string copy1 = now;
                string copy2 = now;
                int cur = now[i] - '0';
                int c1 = (cur+1)%10;
                int c2 = ((cur-1)%10+10)%10;
                copy1[i] = to_string(c1)[0];
                copy2[i] = to_string(c2)[0];
                if(!dead[copy1] && !inq[copy1]){
                    inq[copy1] = true;
                    if(copy1.compare(target) == 0){
                        return sp+1;
                    }
                    q.push(copy1);
                    step.push(sp+1);
                }
                if(!dead[copy2] && !inq[copy2]){
                    inq[copy2] = true;
                    if(copy2.compare(target) == 0){
                        return sp+1;
                    }
                    q.push(copy2);
                    step.push(sp+1);
                }
            }
        }
        return -1;
    }
};
