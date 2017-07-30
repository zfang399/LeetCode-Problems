class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        queue<int> h,p,s;
        map<pair<int,int>,bool> visited;
        h.push(1);
        p.push(0);
        s.push(0);
        while(h.size()){
            int hh=h.front(),pp=p.front(),ss=s.front();
            h.pop();
            p.pop();
            s.pop();
            if(visited[make_pair(hh,pp)]) continue;
            visited[make_pair(hh,pp)]=true;
            if(hh+pp==n) return ss+1;
            else if(hh+pp>n) continue;
            if(pp!=0){
                h.push(hh+pp);
                p.push(pp);
                s.push(ss+1);
            }
            h.push(hh);
            p.push(hh);
            s.push(ss+1);
        }
    }
};
