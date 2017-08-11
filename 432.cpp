class AllOne {
public:
    /** Initialize your data structure here. */
    unordered_map<string,int> m;
    map<int,map<string,bool>> x;
    AllOne() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(m.count(key)>0){
            x[m[key]].erase(key);
            if(x[m[key]].size()==0) x.erase(m[key]);
            m[key]++;
            x[m[key]][key]=true;
        }else{
            m[key]=1;
            x[1][key]=true;
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(m.count(key)==0) return;
        if(m[key]==1){
            x[1].erase(key);
            if(x[1].size()==0) x.erase(1);
            m.erase(key);
        }else{
            x[m[key]].erase(key);
            if(x[m[key]].size()==0) x.erase(m[key]);
            m[key]--;
            x[m[key]][key]=true;
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(x.size()==0) return "";
        auto iter=x.crbegin();
        if(iter->second.size()==0) return "";
        return iter->second.begin()->first;
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(x.size()==0) return "";
        auto iter=x.begin();
        if(iter->second.size()==0) return "";
        return iter->second.begin()->first;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
