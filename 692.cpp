class Solution {
public:
    class cmp{
        public:
            bool operator()(pair<string,int> n1,pair<string,int> n2) {
                if(n1.second!=n2.second) return n1.second<n2.second;
                return n1.first>n2.first;
            }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string,int> m;
        priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> q;
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }
        for(auto e:m){
            q.push(make_pair(e.first,e.second));
        }
        for(int i=0;i<k;i++){
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};
