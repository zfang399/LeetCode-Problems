class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        map<string,int> count;
        map<string,bool> ban;
        for(int i = 0; i < banned.size(); i++){
            ban[banned[i]] = true;
        }
        string cur;
        int maxn = 0;
        string ans;
        for(int i = 0; i < p.size(); i++){
            if(p[i] == '!' || p[i] == '?' || p[i] == 39 || p[i] == ',' || p[i] == ';' || p[i] == '.' || p[i] == ' '){
                //cout<< cur <<" " << count[cur]<<endl;
                if(cur.length() != 0 && !ban[cur]){
                    count[cur] ++;
                    if(maxn < count[cur]){
                        maxn = count[cur];
                        ans = cur;
                    }
                }
                cur = "";
                continue;
            }
            cur = cur + char(tolower(p[i]));
        }
        if(cur.length() != 0 && !ban[cur]){
            count[cur] ++;
            if(maxn < count[cur]){
                maxn = count[cur];
                ans = cur;
            }
        }
        return ans;
    }
};
