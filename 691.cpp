class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        vector<map<char,int>> v;
        map<string,bool> vis;
        for(int i=0;i<stickers.size();i++){
            map<char,int> m;
            for(int j=0;j<stickers[i].size();j++) m[stickers[i][j]]++;
            v.push_back(m);
        }
        for(int i=0;i<target.size();i++){
            bool f=false;
            for(int j=0;j<stickers.size();j++){
                if(v[j][target[i]]!=0){
                    f=true;
                    break;
                }
            }
            if(!f) return -1;
        }
        queue<string> q;
        queue<int> cnt;
        q.push(target);
        cnt.push(0);
        while(q.size()){
            int c=cnt.front();
            cnt.pop();
            string now=q.front();
            q.pop();
            if(vis[now]) continue;
            vis[now]=true;
            //cout<<now<<endl;
            if(now.length()==0) return c;
            for(int i=0;i<stickers.size();i++){
                bool f=false;
                string tmp=now;
                map<char,int> tt=v[i];
                for(int j=0;j<tmp.length();j++){
                    if(tt[tmp[j]]>0){
                        f=true;
                        tt[tmp[j]]--;
                        tmp=tmp.substr(0,j)+tmp.substr(j+1);
                        j--;
                    }
                }
                if(!f) continue;
                q.push(tmp);
                cnt.push(c+1);
            }
        }
        return -1;
    }
};
