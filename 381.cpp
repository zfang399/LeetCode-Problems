class RandomizedCollection {
public:
    map<int,vector<int>> index;
    vector<int> nums;
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        if (index[val].size()>0){
            index[val].push_back(nums.size()-1);
            return false;
        }else{
            index[val].push_back(nums.size()-1);
            return true;
        }
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(index[val].size()==0) return false;
        int x=index[val].back();
        if(x==nums.size()-1){
            index[val].pop_back();
            nums.pop_back();
            return true;
        }
        int y=nums[nums.size()-1];
        index[val].pop_back();
        swap(nums[x],nums[nums.size()-1]);
        nums.pop_back();
        index[y].pop_back();
        index[y].push_back(x);
        sort(index[y].begin(),index[y].end());
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        int n=nums.size();
        int x=rand()%n;
        return nums[x];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
