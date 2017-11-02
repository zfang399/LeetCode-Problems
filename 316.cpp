class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,bool> inq;
        unordered_map<char,int> cnt;
        string ans;
        for(int i=0;i<s.length();i++){
            cnt[s[i]]++;
        }
        for(int i=0;i<s.length();i++){
            cnt[s[i]]--;
            //cout<<ans<<endl;
            if(inq[s[i]]){
                continue;
            }
            while (s[i] < ans.back() && cnt[ans.back()]) {
                inq[ans.back()] = false;
                ans.pop_back();
            }
            ans += s[i];
            inq[s[i]] = true;
        }
        return ans;
    }
};
