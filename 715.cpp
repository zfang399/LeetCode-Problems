class RangeModule {
public:
    RangeModule() {

    }

    void addRange(int left, int right) {
        vector<pair<int,int>> tmp;
        for(int i=0;i<=intervals.size();i++){
            if(i==intervals.size() || intervals[i].first>right){
                tmp.push_back(make_pair(left,right));
                while(i<intervals.size()){
                    tmp.push_back(intervals[i]);
                    i++;
                }
            }else if(intervals[i].second<left){
                tmp.push_back(intervals[i]);
            }else{
                left=min(left,intervals[i].first);
                right=max(right,intervals[i].second);
            }
        }
        swap(intervals,tmp);
    }

    bool queryRange(int left, int right) {
        int l=0,r=intervals.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(intervals[mid].first>=right){
                r=mid-1;
            }else if(intervals[mid].second<=left){
                l=mid+1;
            }else{
                if(intervals[mid].first<=left && intervals[mid].second>=right) return true;
                return false;
            }
        }
        return false;
    }

    void removeRange(int left, int right) {
        vector<pair<int,int>> tmp;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i].second<=left || intervals[i].first>=right){
                tmp.push_back(intervals[i]);
            }else{
                if(intervals[i].first<left) tmp.push_back(make_pair(intervals[i].first,left));
                if(intervals[i].second>right) tmp.push_back(make_pair(right,intervals[i].second));
            }
        }
        swap(intervals,tmp);
    }
private:
    vector<pair<int,int>> intervals;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
