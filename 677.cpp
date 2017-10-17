class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string,int> m;
    MapSum() {

    }

    void insert(string key, int val) {
        m[key]=val;
    }

    int sum(string prefix) {
        int ans=0;
        for(auto e:m){
            if(e.first.substr(0,prefix.length()).compare(prefix)==0){
                ans+=e.second;
            }
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
