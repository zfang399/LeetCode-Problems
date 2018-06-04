class Solution {
public:
    string crackSafe(int n, int k) {
        int tot = pow(k,n);
        string ans = "";
        for(int i = 0; i < n; i++) ans += "0";
        set<string> vis;
        vis.insert(ans);
        helper(ans, tot, vis, n, k);
        return ans;
    }

    bool helper(string& ans, int total, set<string> &vis, int n, int k){
        if(vis.size() == total) return true;
        string overlap = ans.substr(ans.length() - n + 1);
        for(int i = 0; i < k; i++){
            string cur = overlap + "0";
            cur[cur.length() - 1] += i;
            if(vis.count(cur) == 0){
                vis.insert(cur);
                ans = ans + cur[cur.length() - 1];
                if(helper(ans, total, vis, n, k)) return true;
                vis.erase(vis.find(cur));
                ans = ans.substr(0, ans.length() - 1);
            }
        }
        return false;
    }
};
